// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include "serverGame.h"
#include "../players/serverPlayer.h"
#include "../terrains/serverNode.h"
#include "../tasks/serverTaskCreateGrunt.h"
#include "../tasks/serverTaskCreateTough.h"
#include "../tasks/serverTaskCreatePsycho.h"
#include "../tasks/serverTaskCreatePyro.h"
#include "../tasks/serverTaskCreateLaser.h"
#include "../tasks/serverTaskCreateSniper.h"
#include "../tasks/serverTaskCreateJeep.h"
#include "../tasks/serverTaskCreateLightTank.h"
#include "../tasks/serverTaskCreateMediumTank.h"
#include "../tasks/serverTaskCreateHeavyTank.h"
#include "../tasks/serverTaskCreateMML.h"
#include "../tasks/serverTaskMove.h"
#include "../states/serverStateMoving.h"
#include "../states/serverStateStill.h"
#include "../tasks/serverTaskAttackUnit.h"
#include "../objects/serverObject.h"
#include "../tasks/serverTaskAttackObject.h"
#include "../terrains/paths/serverNodePath.h"
#include "../states/serverStateAttackingUnit.h"
#include "../states/serverStateAttackingObject.h"
#include "../territories/serverTerritories.h"
#include "../teams/serverTeam.h"
#include "../objects/buildings/serverFort.h"
#include "../armament/serverBullets.h"
#include "../armament/serverHighCaliberProjectiles.h"
#include "../armament/serverMissiles.h"
#include "../armament/serverFlamethrower.h"
#include "../armament/serverArmamentLaser.h"
#include "../tasks/shoots/serverTaskShoot.h"
#include "../tasks/shoots/serverTaskShootUnit.h"
#include "../tasks/shoots/serverTaskShootObject.h"
#include "../proxy_client/serverProxyClient.h"
#include "../../libs/Lock.h"
//------------------------------------------------------------------------------
#define INITIAL_MODEL_SIZE 850
#define MODEL_SIZE 50
//------------------------------------------------------------------------------
// COMPARE TASKS
//------------------------------------------------------------------------------
bool cmpTasks(ServerTask *a, ServerTask *b) {
    return a->waitingTime > b->waitingTime;
}
//------------------------------------------------------------------------------
// GAME CONSTRUCTOR
//------------------------------------------------------------------------------
ServerGame::ServerGame(char* mapFileName):
        gameMap(mapFileName), tasks(cmpTasks), interpreter(*this) {
    munitionQuant = 0;
    unitsQuant = 0;
    finish = false;
    playersQuant = 0;
    model.reserve(MODEL_SIZE);
    initialModel.reserve(INITIAL_MODEL_SIZE);
    initialModel = interpreter.InitialSerialize();
}
//------------------------------------------------------------------------------
// GAME DESTRUCTOR
//------------------------------------------------------------------------------
ServerGame::~ServerGame() {
    for (ServerPlayer* aPlayer : players.getList()) {
        delete aPlayer;
    }
    for (ServerTask* aTask : tasks.getQueue()) {
        delete aTask;
    }
    for (ServerArmament* aMunition : munitions.getList()) {
        delete aMunition;
    }
    for (ServerTeam* aTeam : teams.getList()) {
        delete aTeam;
    }
}
//------------------------------------------------------------------------------
// RECEIVE PETITION
//------------------------------------------------------------------------------
void ServerGame::receivePetition(std::string petition) {
    Lock lock(aMutex);
    interpreter.deserializePetition(petition);
}
//------------------------------------------------------------------------------
// GET INITIAL MODEL
//------------------------------------------------------------------------------
const std::vector<std::string> ServerGame::getInitialModel() {
    Lock lock(aMutex);
    return initialModel;
}
//------------------------------------------------------------------------------
// GET MODEL
//------------------------------------------------------------------------------
const std::vector<std::string> ServerGame::getModel() {
    Lock lock(aMutex);
    model.clear();
    model = interpreter.serialize();
    return model;
}
//------------------------------------------------------------------------------
// CREATE PLAYER
//------------------------------------------------------------------------------
size_t ServerGame::createPlayer(size_t idTeam) {
    Lock lock(aMutex);
    size_t id = ++playersQuant;
    ServerPlayer* newPlayer = new ServerPlayer(gameMap, id);
    gameMap.addInitialTerritoryToPlayer(*newPlayer);
    players(id, newPlayer);
    ServerTeam* aTeam;
    if (!teams.keyExist(idTeam)) {
        aTeam = new ServerTeam(idTeam);
        teams(idTeam, aTeam);
    } else {
        aTeam = teams[idTeam];
    }
    aTeam->addPlayer(*newPlayer);
    const ServerTerritories* aTerritory = newPlayer->getTerritoryWithBuilding();
    ServerNode* node = aTerritory->getBuilding()->getWalkableNode();
    size_t idUnit = ++unitsQuant;
    newPlayer->createRobotGrunt(node->getX(), node->getY(), idUnit);
    units(idUnit, newPlayer->getUnit(idUnit));
    return id;
}
//------------------------------------------------------------------------------
// KILL PLAYER
//------------------------------------------------------------------------------
void ServerGame::killPlayer(size_t idPlayer) {
    Lock lock(aMutex);
    ServerPlayer* aPlayer = getPlayer(idPlayer);
    for (ServerUnit* aUnit :  aPlayer->getUnits().getList()) {
        units.erase(aUnit->getId());
    }
    aPlayer->getTeam()->erasePlayer(aPlayer->getId());
    players.erase(idPlayer);
    delete aPlayer;
}
//------------------------------------------------------------------------------
// GET PLAYER
//------------------------------------------------------------------------------
ServerPlayer* ServerGame::getPlayer(size_t idPlayer) {
    return players[idPlayer];
}
//------------------------------------------------------------------------------
// VALIDATE UNIT TASKS AND STATE
//------------------------------------------------------------------------------
void ServerGame::validateUnitTasksAndState(ServerUnit& aUnit) {
    const ServerState* state = aUnit.getCurrentState();
    //--------------------------------------------------------------------------
    if (state->isStill()) clearUnitTasks(aUnit);
    //--------------------------------------------------------------------------
    if (state->isAttackingUnit()) {
        const ServerStateAttackingUnit* attackingUnit;
        attackingUnit = (const ServerStateAttackingUnit*)state;
        size_t idTarget = attackingUnit->getIdReceiver();
        if (!units.keyExist(idTarget)) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new ServerStateStill());
            return;
        }
        if (units[idTarget]->getCurrentState()->isDead()) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new ServerStateStill());
            return;
        }
    }
    //--------------------------------------------------------------------------
    if (state->isAttackingObject()) {
        const ServerStateAttackingObject* attackingObject;
        attackingObject = (const ServerStateAttackingObject*)state;
        size_t idTarget = attackingObject->getIdReceiver();
        if (!gameMap.getObjects().keyExist(idTarget)) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new ServerStateStill());
            return;
        }
        ServerObject* object = gameMap.getObjects()[idTarget];
        if (object->getCurrentState()->isBroken()) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new ServerStateStill());
            if (object->isFort()) {
                ServerFort* aFort =  reinterpret_cast<ServerFort*>(object);
                aFort->showFlag();
            }
            return;
        }
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// CLEAR UNIT TASKS
//------------------------------------------------------------------------------
void ServerGame::clearUnitTasks(ServerUnit& aUnit) {
    ServerTask* task;
    while (!aUnit.getTasks().empty()) {
        task = aUnit.getTasks().top();
        aUnit.getTasks().pop();
        delete task;
    }
}
//------------------------------------------------------------------------------
// TERRAIN CAPTURE
//------------------------------------------------------------------------------
void ServerGame::territoryCapture(ServerUnit &aUnit) {
    if (!aUnit.getPosition()->hasAGroundObject()) return;
    if (!aUnit.getPosition()->getGroundObject()->isFlag()) return;
    size_t idTerritory = aUnit.getPosition()->getIdTerritory();
    ServerTerritories* territory = gameMap.getTerritory(idTerritory);
    if (territory->hasAPlayer()) {
        if (*aUnit.getOwner() == *territory->getOwner()) return;
    }
    territory->changePlayer(*aUnit.getOwner());
}
//------------------------------------------------------------------------------
// UNIT DIE
//------------------------------------------------------------------------------
void ServerGame::unitDie(size_t id) {
    if (deadUnits.keyExist(id)) return;
    deadUnits(id, units[id]);
}
//------------------------------------------------------------------------------
// MUNITION DIE
//------------------------------------------------------------------------------
void ServerGame::munitionDie(size_t id) {
    if (impactedMunitions.keyExist(id)) return;
    impactedMunitions(id, munitions[id]);
}
//------------------------------------------------------------------------------
// OBJECT DIE
//------------------------------------------------------------------------------
void ServerGame::objectDie(size_t id) {
    if (brokenObjects.keyExist(id)) return;
    brokenObjects(id, gameMap.getObject(id));
}
//------------------------------------------------------------------------------
// KILL OBJECT
//------------------------------------------------------------------------------
void ServerGame::killObject(size_t id) {
    ServerObject* anObject = gameMap.getObject(id);
    if (anObject->isBridge() || anObject->isBuilding()) return;
    gameMap.getObjects().erase(id);
    for (ServerUnit* otherUnits : units.getList()) {
        validateUnitTasksAndState(*otherUnits);
    }
    delete anObject;
}
//------------------------------------------------------------------------------
// KILL MUNITION
//------------------------------------------------------------------------------
void ServerGame::killMunition(size_t id) {
    ServerArmament* munition = munitions[id];
    munitions.erase(id);
    delete munition;
}
//------------------------------------------------------------------------------
// KILL UNIT
//------------------------------------------------------------------------------
void ServerGame::killUnit(ServerUnit& aUnit) {
    aUnit.getOwner()->getUnits().erase(aUnit.getId());
    units.erase(aUnit.getId());
    for (ServerUnit* otherUnits : units.getList()) {
        validateUnitTasksAndState(*otherUnits);
    }
    for (ServerArmament* aMunition : munitions.getList()) {
        if (aMunition->isTargetAnObject()) continue;
        size_t idShooter = aMunition->getShooterId();
        if (!units.keyExist(idShooter)) {
            munitionDie(aMunition->getId());
        }
        size_t idTarget = aMunition->getUnitTarget()->getId();
        if (idTarget == aUnit.getId() || idShooter == aUnit.getId()) {
            munitionDie(aMunition->getId());
        }
    }
    delete &aUnit;
}
//------------------------------------------------------------------------------
// MONITORING
//------------------------------------------------------------------------------
void ServerGame::monitoring(ServerUnit& aUnit) {
    const ServerState* state = aUnit.getCurrentState();
    if (state->isMoving()) return;
    size_t id = aUnit.getId();
    //--------------------------------------------------------------------------
    // MONITORING IF ATTACKING IS FINISHED OR RECALCULATE THE ATTACK
    //--------------------------------------------------------------------------
    if (state->isAttackingUnit()) {
        const ServerStateAttackingUnit* attackingUnit;
        attackingUnit = (const ServerStateAttackingUnit*)state;
        size_t idTarget = attackingUnit->getIdReceiver();
        ServerUnit* target = getUnit(idTarget);
        if (target->getCurrentState()->isDead()) {
            aUnit.changeState(*new ServerStateStill);
            clearUnitTasks(aUnit);
        } else {
            if (!aUnit.isReachable(*target)) attackUnit(id, idTarget);
        }
        return;
    }
    //--------------------------------------------------------------------------
    // MONITORING IF ATTACKING IS FINISHED OR RECALCULATE THE ATTACK
    //--------------------------------------------------------------------------
    if (state->isAttackingObject()) {
        const ServerStateAttackingObject* attackingObject;
        attackingObject = (const ServerStateAttackingObject*) state;
        size_t idTarget = attackingObject->getIdReceiver();
        ServerObject* object = gameMap.getObject(idTarget);
        if (object->getCurrentState()->isBroken()) {
            if (object->isFort()) {
                ServerFort* aFort =  reinterpret_cast<ServerFort*>(object);
                aFort->showFlag();
            }
            aUnit.changeState(*new ServerStateStill);
            clearUnitTasks(aUnit);
        } else {
            if (!aUnit.isReachable(*object)) attackObject(id, idTarget);
        }
        return;
    }
    //--------------------------------------------------------------------------
    // MONITORING ENEMY UNITS IN REACHABLE RANGE
    //--------------------------------------------------------------------------
    if (state->isStill()) {
        for (ServerUnit* otherUnit : units.getList()) {
            if (aUnit == *otherUnit) continue;
            if (!aUnit.isEnemy(*otherUnit)) continue;
            if (!aUnit.isReachable(*otherUnit)) continue;
            if (otherUnit->getCurrentState()->isDead()) continue;
            size_t otherId = otherUnit->getId();
            attackUnit(id, otherId);
        }
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// CLEAN UNITS
//------------------------------------------------------------------------------
void ServerGame::cleanUnits() {
    for (ServerUnit* aUnit : deadUnits.getList()) {
        killUnit(*aUnit);
    }
    deadUnits.clear();
}
//------------------------------------------------------------------------------
// CLEAN MUNITIONS
//------------------------------------------------------------------------------
void ServerGame::cleanMunitions() {
    for (ServerArmament* aMunition : impactedMunitions.getList()) {
        killMunition(aMunition->getId());
    }
    impactedMunitions.clear();
}
//------------------------------------------------------------------------------
// CLEAN OBJECTS
//------------------------------------------------------------------------------
void ServerGame::cleanObjects() {
    for (ServerObject* anObject : brokenObjects.getList()) {
        killObject(anObject->getId());
    }
    brokenObjects.clear();
}
//------------------------------------------------------------------------------
// CLEAN MODEL
//------------------------------------------------------------------------------
void ServerGame::cleanModel() {
    //--------------------------------------------------------------------------
    for (ServerUnit* aUnit : deadUnits.getList()) {
        killUnit(*aUnit);
    }
    deadUnits.clear();
    //--------------------------------------------------------------------------
    for (ServerArmament* aMunition : impactedMunitions.getList()) {
        killMunition(aMunition->getId());
    }
    impactedMunitions.clear();
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// REFRESH MUNITION TASKS
//------------------------------------------------------------------------------
void ServerGame::refreshMunitionTasks(ServerArmament& aMunition) {
    if (aMunition.getTasks().empty()) return;
    ServerTask* aTask;
    aTask = aMunition.getTasks().top();
    if (aTask->executable()) {
        aTask->execute();
        aMunition.getTasks().pop();
        if (aTask->isRelocable()) {
            aMunition.addTask(aTask);
        } else {
            delete aTask;
        }
    }
}
//------------------------------------------------------------------------------
// REFRESH UNITS TASKS
//------------------------------------------------------------------------------
void ServerGame::refreshUnitsTasks(ServerUnit& aUnit) {
    if (aUnit.getTasks().empty()) return;
    validateUnitTasksAndState(aUnit);
    if (aUnit.getTasks().empty()) return;
    ServerTask* aTask;
    aTask = aUnit.getTasks().top();
    if (aTask->executable()) {
        aTask->execute();
        aUnit.getTasks().pop();
        if (aTask->isRelocable()) {
            aUnit.addTask(aTask);
        } else {
            delete aTask;
        }
    }
}
//------------------------------------------------------------------------------
// UPDATE
//------------------------------------------------------------------------------
void ServerGame::update() {
    cleanModel();
    //--------------------------------------------------------------------------
    for (ServerUnit* aUnit : units.getList()) {
        if (aUnit->getCurrentState()->isDead()) {
            unitDie(aUnit->getId());
            continue;
        }
        territoryCapture(*aUnit);
        refreshUnitsTasks(*aUnit);
        monitoring(*aUnit);
    }
    //--------------------------------------------------------------------------
    for (ServerObject* anObject : gameMap.getObjects().getList()) {
        if (anObject->getCurrentState()->isBroken()) {
            if (!anObject->isBridge() || !anObject->isBuilding() ||
                    !anObject->isFlag()) {
                objectDie(anObject->getId());
                continue;
            }
            if (anObject->isFort()) {
                ServerFort* aFort =  reinterpret_cast<ServerFort*>(anObject);
                aFort->showFlag();
            }
        }
    }
    //--------------------------------------------------------------------------
    for (ServerArmament* aMunition : munitions.getList()) {
        if (aMunition->hasImpacted() || aMunition->hasDeprecated()) {
            munitionDie(aMunition->getId());
            continue;
        }
        refreshMunitionTasks(*aMunition);
    }
    //--------------------------------------------------------------------------
    ServerTask* aTask;
    if (tasks.empty()) return;
    aTask = tasks.top();
    if (aTask->executable()) {
        aTask->execute();
        tasks.pop();
        if (aTask->isRelocable()) {
            tasks.add(aTask);
        } else {
            delete aTask;
        }
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// CREATE ROBOT GRUNT
//------------------------------------------------------------------------------
void ServerGame::createRobotGrunt(size_t idBuilding) {
    tasks.add(new ServerTaskCreateGrunt(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE ROBOT LASER
//------------------------------------------------------------------------------
void ServerGame::createRobotLaser(size_t idBuilding) {
    tasks.add(new ServerTaskCreateLaser(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE ROBOT TOUGH
//------------------------------------------------------------------------------
void ServerGame::createRobotTough(size_t idBuilding) {
    tasks.add(new ServerTaskCreateTough(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE ROBOT SNIPER
//------------------------------------------------------------------------------
void ServerGame::createRobotSniper(size_t idBuilding) {
    tasks.add(new ServerTaskCreateSniper(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE ROBOT PYRO
//------------------------------------------------------------------------------
void ServerGame::createRobotPyro(size_t idBuilding) {
    tasks.add(new ServerTaskCreatePyro(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE ROBOT PSYCHO
//------------------------------------------------------------------------------
void ServerGame::createRobotPsycho(size_t idBuilding) {
    tasks.add(new ServerTaskCreatePsycho(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE VEHICLE ServerMML
//------------------------------------------------------------------------------
void ServerGame::createVehicleMML(size_t idBuilding) {
    tasks.add(new ServerTaskCreateMML(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE VEHICLE HEAVY TANK
//------------------------------------------------------------------------------
void ServerGame::createVehicleHeavyTank(size_t idBuilding) {
    tasks.add(new ServerTaskCreateHeavyTank(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE VEHICLE LIGHT TANK
//------------------------------------------------------------------------------
void ServerGame::createVehicleLightTank(size_t idBuilding) {
    tasks.add(new ServerTaskCreateLightTank(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE VEHICLE MEDIUM TANK
//------------------------------------------------------------------------------
void ServerGame::createVehicleMediumTank(size_t idBuilding) {
    tasks.add(new ServerTaskCreateMediumTank(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE VEHICLE JEEP TANK
//------------------------------------------------------------------------------
void ServerGame::createVehicleJeep(size_t idBuilding) {
    tasks.add(new ServerTaskCreateJeep(*this, idBuilding));
}
//------------------------------------------------------------------------------
// CREATE MUNITION BULLETS
//------------------------------------------------------------------------------
void ServerGame::createMunitionBullets(size_t idUnit) {
    size_t id = ++munitionQuant;
    ServerUnit* unit = getUnit(idUnit);
    munitions(id, new ServerBullets(*unit->getPosition(), id, *unit));
    unit->addCurrentIdMunition(id);
}
//------------------------------------------------------------------------------
// CREATE MUNITION HIGH CALIBER PROJECTILES
//------------------------------------------------------------------------------
void ServerGame::createMunitionHighCaliberProjectiles(size_t idUnit) {
    size_t id = ++munitionQuant;
    ServerUnit* unit = getUnit(idUnit);
    const ServerNode* position = unit->getPosition();
    munitions(id, new ServerHighCaliberProjectiles(*position, id, *unit));
    getUnit(idUnit)->addCurrentIdMunition(id);
}
//------------------------------------------------------------------------------
// CREATE MUNITION FLAMETHROWER
//------------------------------------------------------------------------------
void ServerGame::createMunitionFlamethrower(size_t idUnit) {
    size_t id = ++munitionQuant;
    ServerUnit* unit = getUnit(idUnit);
    munitions(id, new ServerFlamethrower(*unit->getPosition(), id, *unit));
    getUnit(idUnit)->addCurrentIdMunition(id);
}
//------------------------------------------------------------------------------
// CREATE MUNITION MISSILES
//------------------------------------------------------------------------------
void ServerGame::createMunitionMissiles(size_t idUnit) {
    size_t id = ++munitionQuant;
    ServerUnit* unit = getUnit(idUnit);
    munitions(id, new ServerMissiles(*unit->getPosition(), id, *unit));
    getUnit(idUnit)->addCurrentIdMunition(id);
}
//------------------------------------------------------------------------------
// CREATE MUNITION LASER
//------------------------------------------------------------------------------
void ServerGame::createMunitionLaser(size_t idUnit) {
    size_t id = ++munitionQuant;
    ServerUnit* unit = getUnit(idUnit);
    munitions(id, new ServerArmamentLaser(*unit->getPosition(), id, *unit));
    getUnit(idUnit)->addCurrentIdMunition(id);
}
//------------------------------------------------------------------------------
// CONVERT COORDINATE TO TILE
//------------------------------------------------------------------------------
uint32_t ServerGame::convertPixelToTile(uint32_t number) {
    return number / 64;
}
//------------------------------------------------------------------------------
// CONVERT COORDINATE TO PIXEL
//------------------------------------------------------------------------------
uint32_t ServerGame::convertTileToPixel(uint32_t number) {
    return 32 * (2 * number + 1);
}
//------------------------------------------------------------------------------
// MOVE UNIT UNTIL
//------------------------------------------------------------------------------
void ServerGame::moveUntil(
        const ServerNode& dst, size_t idUnit, float distance, double* time) {
    Path path = getUnit(idUnit)->goTo(dst);
    if (path.empty()) return;
    ServerNodePath* nodePath;
    ServerTaskMove* task;
    while (!path.empty()) {
        nodePath = path.front();
        path.pop();
        task = new ServerTaskMove(*this, *nodePath, idUnit);
        units[idUnit]->addTask(task);
        if (nodePath->getNode().distanceTo(dst) <= distance) {
            delete nodePath->getState();
            if (distance != 0) {
                nodePath->changeState(
                        *new ServerStateMoving(nodePath->getNode()));
            } else {
                nodePath->changeState(*new ServerStateStill());
            }
            if (time != nullptr) {
                *time = nodePath->getCumulativeWaitingTime() + 1;
            }
            while (!path.empty()) {
                nodePath = path.front();
                path.pop();
                delete nodePath->getState();
                delete nodePath;
            }
            break;
        }
    }
}
//------------------------------------------------------------------------------
// MOVE UNIT TO
//------------------------------------------------------------------------------
void ServerGame::moveUnitTo(uint32_t x, uint32_t y, size_t idUnit) {
    if (!units.keyExist(idUnit)) return;
    clearUnitTasks(*getUnit(idUnit));
    uint32_t tileX = convertPixelToTile(x);
    uint32_t tileY = convertPixelToTile(y);
    moveUntil(*gameMap.getNode(tileX, tileY), idUnit, 0, nullptr);
}
//------------------------------------------------------------------------------
// ATTACK UNIT
//------------------------------------------------------------------------------
void ServerGame::attackUnit(size_t idShooter, size_t idTarget) {
    if (!units.keyExist(idShooter)) return;
    ServerUnit* attacker = getUnit(idShooter);
    if (!units.keyExist(idTarget)) return;
    ServerUnit* receiver = getUnit(idTarget);
    if (!attacker->getOwner()->isEnemy(*receiver->getOwner())) return;
    clearUnitTasks(*getUnit(idShooter));
    double finalWaitingTime = 0;
    if (!attacker->isReachable(*receiver)) {
        uint32_t x = receiver->getPosition()->x;
        uint32_t y = receiver->getPosition()->y;
        ServerNode* dst = gameMap.getNode(x, y);
        float reach = attacker->getReachAttack();
        moveUntil(*dst, idShooter, reach, &finalWaitingTime);
    }
    ServerTaskShoot* shootTask;
    shootTask = new ServerTaskShootUnit(
            *this, idShooter, idTarget, finalWaitingTime);
    units[idShooter]->addTask(shootTask);
}
//------------------------------------------------------------------------------
// ATTACK OBJECT
//------------------------------------------------------------------------------
void ServerGame::attackObject(size_t idShooter, size_t idTarget) {
    // printf("ATTACK OBJECT\n");
    if (!units.keyExist(idShooter)) return;
    ServerUnit* attacker = getUnit(idShooter);
    if (!gameMap.getObjects().keyExist(idTarget)) return;
    ServerObject* receiver = gameMap.getObject(idTarget);
    if (receiver->isBuilding()) {
        if (!receiver->hasAnOwner()) return;
        if (!attacker->getOwner()->isEnemy(*receiver->getOwner())) return;
    }
    clearUnitTasks(*getUnit(idShooter));
    double finalWaitingTime = 0;
    if (!attacker->isReachable(*receiver)) {
        uint32_t x = receiver->getWalkableNode()->x;
        uint32_t y = receiver->getWalkableNode()->y;
        ServerNode* dst = gameMap.getNode(x, y);
        float reach = attacker->getReachAttack();
        moveUntil(*dst, idShooter, reach, &finalWaitingTime);
    }
    ServerTaskShoot* shootTask;
    shootTask = new ServerTaskShootObject(
            *this, idShooter, idTarget, finalWaitingTime);
    units[idShooter]->addTask(shootTask);
}
//------------------------------------------------------------------------------
// GET WINNER TEAM
//------------------------------------------------------------------------------
size_t ServerGame::getWinnerTeam() {
    size_t id = 0;
    for (ServerTeam* aTeam : teams.getList()) {
        if (!aTeam->hasLost()) {
            id = aTeam->getId();
        }
    }
    return id;
}
//------------------------------------------------------------------------------
// FINISH
//------------------------------------------------------------------------------
bool ServerGame::isFinished() {
    Lock lock(aMutex);
    if (gameMap.maximumQuantityOfPlayers != players.size()) return false;
    size_t quantity = 0;
    if (teams.empty()) {
        throw Exception("There are no teams in function isFinished\n");
    }
    for (ServerTeam* aTeam : teams.getList()) {
        if (!aTeam->hasLost()) quantity++;
    }
    return quantity == 1;
}
//------------------------------------------------------------------------------
// GET UNITS
//------------------------------------------------------------------------------
unitsMap& ServerGame::getUnits() {
    return units;
}
//------------------------------------------------------------------------------
// ADD NEW UNIT
//------------------------------------------------------------------------------
void ServerGame::addNewUnit(size_t id, ServerUnit* unit) {
    units(id, unit);
}
//------------------------------------------------------------------------------
// GET UNIT
//------------------------------------------------------------------------------
ServerUnit* ServerGame::getUnit(size_t id) {
    return units[id];
}
//------------------------------------------------------------------------------
// GET MUNITION
//------------------------------------------------------------------------------
ServerArmament* ServerGame::getMunition(size_t id) {
    return munitions[id];
}
//------------------------------------------------------------------------------
// GET MUNITIONS
//------------------------------------------------------------------------------
munitionsMap& ServerGame::getMunitions() {
    return munitions;
}
//------------------------------------------------------------------------------
