#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "game.h"
#include "../players/player.h"
#include "../terrains/node.h"
#include "../tasks/taskCreateUnit.h"
#include "../tasks/taskMove.h"
#include "../states/stateMoving.h"
#include "../states/stateStill.h"
#include "../tasks/taskAttackUnit.h"
#include "../objects/object.h"
#include "../tasks/taskAttackObject.h"
#include "../terrains/paths/nodePath.h"
#include "../states/stateAttackingUnit.h"
#include "../states/stateAttackingObject.h"
#include "../territories/territories.h"
#include "../teams/team.h"
#include "../objects/object.h"
#include "../armament/armament.h"
#include "../tasks/shoots/taskShoot.h"
#include "../tasks/shoots/taskShootUnit.h"
#include "../tasks/shoots/taskShootObject.h"
#include "../proxy_client/proxyClient.h"
#include "../../libs/Lock.h"
#include "../../libs/definitions.h"

bool cmpTasks(Task *a, Task *b) {
    return a->waitingTime > b->waitingTime;
}

Game::Game(char* mapFileName):
        gameMap(mapFileName), tasks(cmpTasks), interpreter(*this) {
    munitionQuant = 0;
    unitsQuant = 0;
    finish = false;
    playersQuant = 0;
    model.reserve(MODEL_SIZE);
    initialModel.reserve(INITIAL_MODEL_SIZE);
    initialModel = interpreter.InitialSerialize();
}

Game::~Game() {
    for (Player* aPlayer : players.getList()) {
        delete aPlayer;
    }
    for (Task* aTask : tasks.getQueue()) {
        delete aTask;
    }
    for (Armament* aMunition : munitions.getList()) {
        delete aMunition;
    }
    for (Team* aTeam : teams.getList()) {
        delete aTeam;
    }
}

msg_t Game::receivePetition(const std::string &petition) {
    Lock lock(aMutex);
    return interpreter.deserializePetition(petition);
}

const std::vector<std::string> Game::getInitialModel() {
    return initialModel;
}

const std::vector<std::string> Game::getModel() {
    model.clear();
    model = interpreter.serialize();
    return model;
}

msg_t Game::createPlayer(size_t idTeam) {
    size_t id = ++playersQuant;
    auto* newPlayer = new Player(gameMap, id);
    gameMap.addInitialTerritoryToPlayer(*newPlayer);
    players(id, newPlayer);
    Team* aTeam;
    if (!teams.keyExist(idTeam)) {
        aTeam = new Team(idTeam);
        teams(idTeam, aTeam);
    } else {
        aTeam = teams[idTeam];
    }
    aTeam->addPlayer(*newPlayer);
    const Territories* aTerritory = newPlayer->getTerritoryWithBuilding();
    Node* node = aTerritory->getBuilding()->getWalkableNode();
    size_t idUnit = ++unitsQuant;
    newPlayer->createUnit(node->getX(), node->getY(), idUnit, GRUNT);
    units(idUnit, newPlayer->getUnit(idUnit));
    std::string idPlayerString = aParser.size_tToString(id);
    return msg_t(1, idPlayerString);
}

void Game::killPlayer(size_t idPlayer) {
    Lock lock(aMutex);
    Player* aPlayer = getPlayer(idPlayer);
    for (Unit* aUnit :  aPlayer->getUnits().getList()) {
        units.erase(aUnit->getId());
    }
    aPlayer->getTeam()->erasePlayer(aPlayer->getId());
    players.erase(idPlayer);
    delete aPlayer;
}

Player* Game::getPlayer(size_t idPlayer) {
    return players[idPlayer];
}

void Game::validateUnitTasksAndState(Unit& aUnit) {
    const State* state = aUnit.getCurrentState();
    //--------------------------------------------------------------------------
    if (state->isStill()) clearUnitTasks(aUnit);
    //--------------------------------------------------------------------------
    if (state->isAttackingUnit()) {
        const StateAttackingUnit* attackingUnit;
        attackingUnit = (const StateAttackingUnit*)state;
        size_t idTarget = attackingUnit->getIdReceiver();
        if (!units.keyExist(idTarget)) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new StateStill());
            return;
        }
        if (units[idTarget]->getCurrentState()->isDead()) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new StateStill());
            return;
        }
    }
    //--------------------------------------------------------------------------
    if (state->isAttackingObject()) {
        const StateAttackingObject* attackingObject;
        attackingObject = (const StateAttackingObject*)state;
        size_t idTarget = attackingObject->getIdReceiver();
        if (!gameMap.getObjects().keyExist(idTarget)) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new StateStill());
            return;
        }
        Object* object = gameMap.getObjects()[idTarget];
        if (object->getCurrentState()->isBroken()) {
            clearUnitTasks(aUnit);
            aUnit.changeState(*new StateStill());
            return;
        }
    }
    //--------------------------------------------------------------------------
}

void Game::clearUnitTasks(Unit& aUnit) {
    Task* task;
    while (!aUnit.getTasks().empty()) {
        task = aUnit.getTasks().top();
        aUnit.getTasks().pop();
        delete task;
    }
}

void Game::territoryCapture(Unit &aUnit) {
    if (!aUnit.getPosition()->hasAGroundObject()) return;
    if (!aUnit.getPosition()->getGroundObject()->isFlag()) return;
    size_t idTerritory = aUnit.getPosition()->getIdTerritory();
    Territories* territory = gameMap.getTerritory(idTerritory);
    if (territory->hasAPlayer()) {
        if (*aUnit.getOwner() == *territory->getOwner()) return;
    }
    territory->changePlayer(*aUnit.getOwner());
}

void Game::unitDie(size_t id) {
    if (deadUnits.keyExist(id)) return;
    deadUnits(id, units[id]);
}

void Game::munitionDie(size_t id) {
    if (impactedMunitions.keyExist(id)) return;
    impactedMunitions(id, munitions[id]);
}

void Game::objectDie(size_t id) {
    if (brokenObjects.keyExist(id)) return;
    brokenObjects(id, gameMap.getObject(id));
}

void Game::killMunition(size_t id) {
    Armament* munition = munitions[id];
    munitions.erase(id);
    delete munition;
}

void Game::killUnit(Unit& aUnit) {
    aUnit.getOwner()->getUnits().erase(aUnit.getId());
    units.erase(aUnit.getId());
    for (Unit* otherUnits : units.getList()) {
        validateUnitTasksAndState(*otherUnits);
    }
    for (Armament* aMunition : munitions.getList()) {
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

void Game::monitoring(Unit& aUnit) {
    const State* state = aUnit.getCurrentState();
    if (state->isMoving()) return;
    size_t id = aUnit.getId();
    //--------------------------------------------------------------------------
    // MONITORING IF ATTACKING IS FINISHED OR RECALCULATE THE ATTACK
    //--------------------------------------------------------------------------
    if (state->isAttackingUnit()) {
        const StateAttackingUnit* attackingUnit;
        attackingUnit = (const StateAttackingUnit*)state;
        size_t idTarget = attackingUnit->getIdReceiver();
        Unit* target = getUnit(idTarget);
        if (target->getCurrentState()->isDead()) {
            aUnit.changeState(*new StateStill);
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
        const StateAttackingObject* attackingObject;
        attackingObject = (const StateAttackingObject*) state;
        size_t idTarget = attackingObject->getIdReceiver();
        Object* object = gameMap.getObject(idTarget);
        if (object->getCurrentState()->isBroken()) {
            aUnit.changeState(*new StateStill);
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
        for (Unit* otherUnit : units.getList()) {
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

void Game::cleanModel() {
    //--------------------------------------------------------------------------
    for (Unit* aUnit : deadUnits.getList()) {
        killUnit(*aUnit);
    }
    deadUnits.clear();
    //--------------------------------------------------------------------------
    for (Armament* aMunition : impactedMunitions.getList()) {
        killMunition(aMunition->getId());
    }
    impactedMunitions.clear();
    //--------------------------------------------------------------------------
}

void Game::refreshMunitionTasks(Armament& aMunition) {
    if (aMunition.getTasks().empty()) return;
    Task* aTask;
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

void Game::refreshUnitsTasks(Unit& aUnit) {
    if (aUnit.getTasks().empty()) return;
    validateUnitTasksAndState(aUnit);
    if (aUnit.getTasks().empty()) return;
    Task* aTask;
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

msg_t Game::update() {
    cleanModel();
    //--------------------------------------------------------------------------
    for (Unit* aUnit : units.getList()) {
        if (aUnit->getCurrentState()->isDead()) {
            unitDie(aUnit->getId());
            continue;
        }
        territoryCapture(*aUnit);
        refreshUnitsTasks(*aUnit);
        monitoring(*aUnit);
    }
    //--------------------------------------------------------------------------
    for (Object* anObject : gameMap.getObjects().getList()) {
        if (anObject->getCurrentState()->isBroken()) {
            objectDie(anObject->getId());
        }
    }
    //--------------------------------------------------------------------------
    for (Armament* aMunition : munitions.getList()) {
        if (aMunition->hasImpacted() || aMunition->hasDeprecated()) {
            munitionDie(aMunition->getId());
            continue;
        }
        refreshMunitionTasks(*aMunition);
    }
    //--------------------------------------------------------------------------
    Task* aTask;
    if (tasks.empty()) return msg_t(0);
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
    return msg_t(0);
}

msg_t Game::createUnit(size_t idBuilding, size_t type) {
    tasks.add(new TaskCreateUnit(*this, idBuilding, type));
    return msg_t(0);
}

void Game::createMunition(size_t idUnit, size_t type) {
    size_t id = ++munitionQuant;
    Unit* unit = getUnit(idUnit);
    munitions(id, new Armament(*unit->getPosition(), id, *unit, type));
    unit->addCurrentIdMunition(id);
}

uint32_t Game::convertPixelToTile(uint32_t number) {
    return number / 64;
}

uint32_t Game::convertTileToPixel(uint32_t number) {
    return 32 * (2 * number + 1);
}

void Game::moveUntil(
        const Node& dst, size_t idUnit, float distance, double* time) {
    Path path = getUnit(idUnit)->goTo(dst);
    if (path.empty()) return;
    NodePath* nodePath;
    TaskMove* task;
    while (!path.empty()) {
        nodePath = path.front();
        path.pop();
        task = new TaskMove(*this, *nodePath, idUnit);
        units[idUnit]->addTask(task);
        if (nodePath->getNode().distanceTo(dst) <= distance) {
            delete nodePath->getState();
            if (distance != 0) {
                nodePath->changeState(
                        *new StateMoving(nodePath->getNode()));
            } else {
                nodePath->changeState(*new StateStill());
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

msg_t Game::moveUnitTo(uint32_t x, uint32_t y, size_t idUnit) {
    if (!units.keyExist(idUnit)) return msg_t(0);
    clearUnitTasks(*getUnit(idUnit));
    uint32_t tileX = convertPixelToTile(x);
    uint32_t tileY = convertPixelToTile(y);
    moveUntil(*gameMap.getNode(tileX, tileY), idUnit, 0, nullptr);
    return msg_t(0);
}

msg_t Game::attackUnit(size_t idShooter, size_t idTarget) {
    if (!units.keyExist(idShooter)) return msg_t(0);
    Unit* attacker = getUnit(idShooter);
    if (!units.keyExist(idTarget)) return msg_t(0);
    Unit* receiver = getUnit(idTarget);
    if (!attacker->getOwner()->isEnemy(*receiver->getOwner())) return msg_t(0);
    clearUnitTasks(*getUnit(idShooter));
    double finalWaitingTime = 0;
    if (!attacker->isReachable(*receiver)) {
        uint32_t x = receiver->getPosition()->x;
        uint32_t y = receiver->getPosition()->y;
        Node* dst = gameMap.getNode(x, y);
        float reach = attacker->getReachAttack();
        moveUntil(*dst, idShooter, reach, &finalWaitingTime);
    }
    TaskShoot* shootTask;
    shootTask = new TaskShootUnit(
            *this, idShooter, idTarget, finalWaitingTime);
    units[idShooter]->addTask(shootTask);
    return msg_t(0);
}

msg_t Game::attackObject(size_t idShooter, size_t idTarget) {
    if (!units.keyExist(idShooter)) return msg_t(0);
    Unit* attacker = getUnit(idShooter);
    if (!gameMap.getObjects().keyExist(idTarget)) return msg_t(0);
    Object* receiver = gameMap.getObject(idTarget);
    if (receiver->isBuilding()) {
        if (!receiver->hasAnOwner()) return msg_t(0);
        if (!attacker->getOwner()->isEnemy(*receiver->getOwner())) return msg_t(0);
    }
    clearUnitTasks(*getUnit(idShooter));
    double finalWaitingTime = 0;
    if (!attacker->isReachable(*receiver)) {
        uint32_t x = receiver->getWalkableNode()->x;
        uint32_t y = receiver->getWalkableNode()->y;
        Node* dst = gameMap.getNode(x, y);
        float reach = attacker->getReachAttack();
        moveUntil(*dst, idShooter, reach, &finalWaitingTime);
    }
    TaskShoot* shootTask;
    shootTask = new TaskShootObject(
            *this, idShooter, idTarget, finalWaitingTime);
    units[idShooter]->addTask(shootTask);
    return msg_t(0);
}

size_t Game::getWinnerTeam() {
    size_t id = 0;
    for (Team* aTeam : teams.getList()) {
        if (!aTeam->hasLost()) {
            id = aTeam->getId();
        }
    }
    return id;
}

bool Game::isFinished() {
    Lock lock(aMutex);
    if (gameMap.maximumQuantityOfPlayers != players.size()) return false;
    size_t quantity = 0;
    if (teams.empty()) {
        throw Exception("There are no teams in function isFinished\n");
    }
    for (Team* aTeam : teams.getList()) {
        if (!aTeam->hasLost()) quantity++;
    }
    return quantity == 1;
}

unitsMap& Game::getUnits() {
    return units;
}

void Game::addNewUnit(size_t id, Unit* unit) {
    units(id, unit);
}

Unit* Game::getUnit(size_t id) {
    return units[id];
}

Armament* Game::getMunition(size_t id) {
    return munitions[id];
}

munitionsMap& Game::getMunitions() {
    return munitions;
}
