// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "clientProxyGame.h"
#include "clientProxyUnit.h"
#include "clientProxyObject.h"
#include "clientProxyMunition.h"
#include "clientProxyTerritories.h"
#include "../communicators/clientCommunicator.h"
#include "../../libs/Lock.h"
//------------------------------------------------------------------------------
#define BROKEN "true"
#define DEAD "dead"
#define OBSOLETE "obsolete"
//------------------------------------------------------------------------------
// GAME CONSTRUCTOR
//------------------------------------------------------------------------------
ClientProxyGame::ClientProxyGame(petitions_t& petitions):
        petitions(petitions), interpreter(*this) {}
//------------------------------------------------------------------------------
// GAME DESTRUCTOR
//------------------------------------------------------------------------------
ClientProxyGame::~ClientProxyGame() {
    if (!munitions.empty()) {
        for (ClientProxyMunition* aMunition : munitions.getList()) {
            delete aMunition;
        }
    }
    if (!units.empty()) {
        for (ClientProxyUnit* aUnit : units.getList()) {
            delete aUnit;
        }
    }
    if (!proxyTerritories.empty()) {
        for (ClientProxyTerritories* aTerritory : proxyTerritories.getList()) {
            delete aTerritory;
        }
    }
    if (!objects.empty()) {
        for (ClientProxyObject* anObject : objects.getList()) {
            delete anObject;
        }
    }
}
//------------------------------------------------------------------------------
// GET INITIAL MODEL
//------------------------------------------------------------------------------
void ClientProxyGame::getInitialModel() {
    std::string command;
    command = aParser.armString("getInitialModel");
    petitions.push(command);
}
//------------------------------------------------------------------------------
// GET MODEL
//------------------------------------------------------------------------------
void ClientProxyGame::getModel() {
    std::string command;
    command = aParser.armString("getModel");
    petitions.push(command);
}
//------------------------------------------------------------------------------
// RECEIVED MODEL
//------------------------------------------------------------------------------
void ClientProxyGame::receiveModel(std::string parsedModel) {
    interpreter.deserialize(parsedModel);
}
//------------------------------------------------------------------------------
// GET BROKEN OBJECTS
//------------------------------------------------------------------------------
proxyObjectsMap& ClientProxyGame::getBrokenObjects() {
    return brokenObjects;
}
//------------------------------------------------------------------------------
// GET DEAD UNITS
//------------------------------------------------------------------------------
proxyUnitsMap& ClientProxyGame::getDeadUnits() {
    return deadUnits;
}
//------------------------------------------------------------------------------
// GET OBSOLETE MUNITIONS
//------------------------------------------------------------------------------
proxyMunitionMap& ClientProxyGame::getObsoleteMunitions() {
    return obsoleteMunitions;
}
//------------------------------------------------------------------------------
// ADD MUNITION
//------------------------------------------------------------------------------
void ClientProxyGame::addMunition(ClientProxyMunition& aMunition) {
    Lock lock(aMutex);
    if (munitions.keyExist(aMunition.getId())) return;
    munitions(aMunition.getId(), &aMunition);
}
//------------------------------------------------------------------------------
// GET MUNITION
//------------------------------------------------------------------------------
proxyMunitionMap& ClientProxyGame::getMunitions() {
    Lock lock(aMutex);
    return munitions;
}
//------------------------------------------------------------------------------
// ADD TERRITORY
//------------------------------------------------------------------------------
void ClientProxyGame::addTerritory(ClientProxyTerritories& aTerritory) {
    Lock lock(aMutex);
    if (proxyTerritories.keyExist(aTerritory.getId())) return;
    proxyTerritories(aTerritory.getId(), &aTerritory);
}
//------------------------------------------------------------------------------
// GET TERRITORIES
//------------------------------------------------------------------------------
proxyTerritoriesMap& ClientProxyGame::getTerritories() {
    Lock lock(aMutex);
    return proxyTerritories;
}
//------------------------------------------------------------------------------
// ADD OBJECT
//------------------------------------------------------------------------------
void ClientProxyGame::addObject(ClientProxyObject& anObject) {
    Lock lock(aMutex);
    if (objects.keyExist(anObject.getId())) return;
    objects(anObject.getId(), &anObject);
}
//------------------------------------------------------------------------------
// GET OBJECTS
//------------------------------------------------------------------------------
proxyObjectsMap& ClientProxyGame::getObjects() {
    Lock lock(aMutex);
    return objects;
}
//------------------------------------------------------------------------------
// ADD UNIT
//------------------------------------------------------------------------------
void ClientProxyGame::addUnit(ClientProxyUnit& aUnit) {
    Lock lock(aMutex);
    if (units.keyExist(aUnit.getId())) return;
    units(aUnit.getId(), &aUnit);
}
//------------------------------------------------------------------------------
// GET UNITS
//------------------------------------------------------------------------------
proxyUnitsMap& ClientProxyGame::getUnits() {
    Lock lock(aMutex);
    return units;
}
//------------------------------------------------------------------------------
// SET MAP DIMENSIONS
//------------------------------------------------------------------------------
void ClientProxyGame::setMapDimensions(uint32_t width, uint32_t height) {
    this->width = width;
    this->height = height;
    gameMap.reserve(width);
    for (uint32_t x = 0; x < this->width; x++) {
        std::vector<ClientProxyNode*> vecY;
        vecY.reserve(height);
        for (uint32_t y = 0; y < this->height; y++) {
            vecY.push_back(nullptr);
        }
        gameMap.push_back(vecY);
    }
}
//------------------------------------------------------------------------------
// CREATE PLAYER
//------------------------------------------------------------------------------
void ClientProxyGame::createPlayer(size_t idTeam) {
    std::string command = aParser.armString("createPlayer-%zu", idTeam);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT GRUNT
//------------------------------------------------------------------------------
void ClientProxyGame::createRobotGrunt(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotGrunt-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT LASER
//------------------------------------------------------------------------------
void ClientProxyGame::createRobotLaser(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotLaser-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT TOUGH
//------------------------------------------------------------------------------
void ClientProxyGame::createRobotTough(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotTough-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT SNIPER
//------------------------------------------------------------------------------
void ClientProxyGame::createRobotSniper(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotSniper-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PYRO
//------------------------------------------------------------------------------
void ClientProxyGame::createRobotPyro(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotPyro-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PSYCHO
//------------------------------------------------------------------------------
void ClientProxyGame::createRobotPsycho(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotPsycho-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE ServerMML
//------------------------------------------------------------------------------
void ClientProxyGame::createVehicleMML(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleMML-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE HEAVY TANK
//------------------------------------------------------------------------------
void ClientProxyGame::createVehicleHeavyTank(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleHeavyTank-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE LIGHT TANK
//------------------------------------------------------------------------------
void ClientProxyGame::createVehicleLightTank(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleLightTank-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE MEDIUM TANK
//------------------------------------------------------------------------------
void ClientProxyGame::createVehicleMediumTank(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleMediumTank-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE JEEP TANK
//------------------------------------------------------------------------------
void ClientProxyGame::createVehicleJeep(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleJeep-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// MOVE UNIT TO
//------------------------------------------------------------------------------
void ClientProxyGame::moveUnitTo(uint32_t x, uint32_t y, size_t idUnit) {
    std::string command;
    command = aParser.armString("moveUnitTo-%u-%u-%zu", x, y, idUnit);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// ATTACK UNIT
//------------------------------------------------------------------------------
void ClientProxyGame::attackUnit(size_t idShooter, size_t idTarget) {
    std::string command;
    command = aParser.armString("attackUnit-%zu-%zu", idShooter, idTarget);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// ATTACK OBJECT
//------------------------------------------------------------------------------
void ClientProxyGame::attackObject(size_t idShooter, size_t idTarget) {
    std::string command;
    command = aParser.armString("attackObject-%zu-%zu", idShooter, idTarget);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// UPDATE
//------------------------------------------------------------------------------
void ClientProxyGame::update() {
    std::string command;
    command = aParser.armString("update");
    petitions.push(command);
}
//------------------------------------------------------------------------------
// UNIT DIE
//------------------------------------------------------------------------------
void ClientProxyGame::unitDie(size_t id) {
    if (deadUnits.keyExist(id)) return;
    deadUnits(id, units[id]);
}
//------------------------------------------------------------------------------
// MUNITION DIE
//------------------------------------------------------------------------------
void ClientProxyGame::MunitionDie(size_t id) {
    if (obsoleteMunitions.keyExist(id)) return;
    obsoleteMunitions(id, munitions[id]);
}
//------------------------------------------------------------------------------
// OBJECT DIE
//------------------------------------------------------------------------------
void ClientProxyGame::objectDie(size_t id) {
    if (brokenObjects.keyExist(id)) return;
    brokenObjects(id, objects[id]);
}
//------------------------------------------------------------------------------
// KILL UNIT
//------------------------------------------------------------------------------
void ClientProxyGame::killUnit(size_t id) {
    ClientProxyUnit* aUnit = units[id];
    units.erase(id);
    delete aUnit;
}
//------------------------------------------------------------------------------
// KILL MUNITION
//------------------------------------------------------------------------------
void ClientProxyGame::killMunition(size_t id) {
    ClientProxyMunition* aMunition = munitions[id];
    munitions.erase(id);
    delete aMunition;
}
//------------------------------------------------------------------------------
// KILL OBJECT
//------------------------------------------------------------------------------
void ClientProxyGame::killObject(size_t id) {
    ClientProxyObject* anObject = objects[id];
    objects.erase(id);
    delete anObject;
}
//------------------------------------------------------------------------------
// REFRESH PROXY GAME
//------------------------------------------------------------------------------
void ClientProxyGame::cleanProxyGame() {
    Lock lock(aMutex);
    //--------------------------------------------------------------------------
    for (ClientProxyUnit* aUnit : deadUnits.getList()) {
        killUnit(aUnit->getId());
    }
    deadUnits.clear();
    //--------------------------------------------------------------------------
    for (ClientProxyMunition* aMunition : obsoleteMunitions.getList()) {
        killMunition(aMunition->getId());
    }
    obsoleteMunitions.clear();
    //--------------------------------------------------------------------------
    for (ClientProxyObject* anObject : brokenObjects.getList()) {
        if (anObject->isBridge() || anObject->isBuilding()) continue;
        killObject(anObject->getId());
    }
    brokenObjects.clear();
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// CLEAN MUNITIONS
//------------------------------------------------------------------------------
void ClientProxyGame::cleanMunitions() {
    Lock lock(aMutex);
    for (ClientProxyMunition* aMunition : obsoleteMunitions.getList()) {
        killMunition(aMunition->getId());
    }
    obsoleteMunitions.clear();
}
//------------------------------------------------------------------------------
// CLEAN OBJECTS
//------------------------------------------------------------------------------
void ClientProxyGame::cleanObjects() {
    Lock lock(aMutex);
    for (ClientProxyObject* anObject : brokenObjects.getList()) {
        if (anObject->isBridge() || anObject->isBuilding()) continue;
        killObject(anObject->getId());
    }
    brokenObjects.clear();
}
//------------------------------------------------------------------------------
// CLEAN UNITS
//------------------------------------------------------------------------------
void ClientProxyGame::cleanUnits() {
    Lock lock(aMutex);
    for (ClientProxyUnit* aUnit : deadUnits.getList()) {
        killUnit(aUnit->getId());
    }
    deadUnits.clear();
}
//------------------------------------------------------------------------------
// CHECK NOT UPDATED MODEL
//------------------------------------------------------------------------------
void ClientProxyGame::checkNotUpdatedModel() {
    //--------------------------------------------------------------------------
    for (ClientProxyUnit* aUnit : units.getList()) {
        if (!aUnit->hasBeenUpdated()) {
            aUnit->changeState(DEAD);
            // printf("UNIT ID: %zu IS DEAD\n", aUnit->getId());
            unitDie(aUnit->getId());
        }
    }
    //--------------------------------------------------------------------------
    for (ClientProxyMunition* aMunition : munitions.getList()) {
        if (!aMunition->hasBeenUpdated()) {
            aMunition->changeState(OBSOLETE);
            // printf("MUNITION ID: %zu IS DEAD\n", aMunition->getId());
            MunitionDie(aMunition->getId());
        }
    }
    //--------------------------------------------------------------------------
    for (ClientProxyObject* anObject : objects.getList()) {
        if (!anObject->hasBeenUpdated()) {
            anObject->changeState(BROKEN);
            objectDie(anObject->getId());
        }
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
