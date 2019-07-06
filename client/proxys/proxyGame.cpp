// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "proxyGame.h"
#include "proxyUnit.h"
#include "proxyObject.h"
#include "proxyMunition.h"
#include "proxyTerritories.h"
#include "../communicators/communicator.h"
#include "../../libs/Lock.h"
#include "../../petitions.h"
//------------------------------------------------------------------------------
// GAME CONSTRUCTOR
//------------------------------------------------------------------------------
ProxyGame::ProxyGame(petitions_t& petitions):
        petitions(petitions), interpreter(*this) {}
//------------------------------------------------------------------------------
// GAME DESTRUCTOR
//------------------------------------------------------------------------------
ProxyGame::~ProxyGame() {
    if (!munitions.empty()) {
        for (ProxyMunition* aMunition : munitions.getList()) {
            delete aMunition;
        }
    }
    if (!units.empty()) {
        for (ProxyUnit* aUnit : units.getList()) {
            delete aUnit;
        }
    }
    if (!proxyTerritories.empty()) {
        for (ProxyTerritories* aTerritory : proxyTerritories.getList()) {
            delete aTerritory;
        }
    }
    if (!objects.empty()) {
        for (ProxyObject* anObject : objects.getList()) {
            delete anObject;
        }
    }
}
//------------------------------------------------------------------------------
// GET INITIAL MODEL
//------------------------------------------------------------------------------
void ProxyGame::getInitialModel() {
    std::string command;
    command = aParser.armString("getInitialModel");
    petitions.push(command);
}
//------------------------------------------------------------------------------
// GET MODEL
//------------------------------------------------------------------------------
void ProxyGame::getModel() {
    std::string command;
    command = aParser.armString("getModel");
    petitions.push(command);
}
//------------------------------------------------------------------------------
// RECEIVED MODEL
//------------------------------------------------------------------------------
void ProxyGame::receiveModel(std::string parsedModel) {
    interpreter.deserialize(parsedModel);
}
//------------------------------------------------------------------------------
// GET BROKEN OBJECTS
//------------------------------------------------------------------------------
proxyObjectsMap& ProxyGame::getBrokenObjects() {
    return brokenObjects;
}
//------------------------------------------------------------------------------
// GET DEAD UNITS
//------------------------------------------------------------------------------
proxyUnitsMap& ProxyGame::getDeadUnits() {
    return deadUnits;
}
//------------------------------------------------------------------------------
// GET OBSOLETE MUNITIONS
//------------------------------------------------------------------------------
proxyMunitionMap& ProxyGame::getObsoleteMunitions() {
    return obsoleteMunitions;
}
//------------------------------------------------------------------------------
// ADD MUNITION
//------------------------------------------------------------------------------
void ProxyGame::addMunition(ProxyMunition& aMunition) {
    Lock lock(aMutex);
    if (munitions.keyExist(aMunition.getId())) return;
    munitions(aMunition.getId(), &aMunition);
}
//------------------------------------------------------------------------------
// GET MUNITION
//------------------------------------------------------------------------------
proxyMunitionMap& ProxyGame::getMunitions() {
    Lock lock(aMutex);
    return munitions;
}
//------------------------------------------------------------------------------
// ADD TERRITORY
//------------------------------------------------------------------------------
void ProxyGame::addTerritory(ProxyTerritories& aTerritory) {
    Lock lock(aMutex);
    if (proxyTerritories.keyExist(aTerritory.getId())) return;
    proxyTerritories(aTerritory.getId(), &aTerritory);
}
//------------------------------------------------------------------------------
// GET TERRITORIES
//------------------------------------------------------------------------------
proxyTerritoriesMap& ProxyGame::getTerritories() {
    Lock lock(aMutex);
    return proxyTerritories;
}
//------------------------------------------------------------------------------
// ADD OBJECT
//------------------------------------------------------------------------------
void ProxyGame::addObject(ProxyObject& anObject) {
    Lock lock(aMutex);
    if (objects.keyExist(anObject.getId())) return;
    objects(anObject.getId(), &anObject);
}
//------------------------------------------------------------------------------
// GET OBJECTS
//------------------------------------------------------------------------------
proxyObjectsMap& ProxyGame::getObjects() {
    Lock lock(aMutex);
    return objects;
}
//------------------------------------------------------------------------------
// ADD UNIT
//------------------------------------------------------------------------------
void ProxyGame::addUnit(ProxyUnit& aUnit) {
    Lock lock(aMutex);
    if (units.keyExist(aUnit.getId())) return;
    units(aUnit.getId(), &aUnit);
}
//------------------------------------------------------------------------------
// GET UNITS
//------------------------------------------------------------------------------
proxyUnitsMap& ProxyGame::getUnits() {
    Lock lock(aMutex);
    return units;
}
//------------------------------------------------------------------------------
// SET MAP DIMENSIONS
//------------------------------------------------------------------------------
void ProxyGame::setMapDimensions(uint32_t width, uint32_t height) {
    this->width = width;
    this->height = height;
    gameMap.reserve(width);
    for (uint32_t x = 0; x < this->width; x++) {
        std::vector<ProxyNode*> vecY;
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
void ProxyGame::createPlayer(size_t idTeam) {
    std::string command = aParser.armString("createPlayer-%zu", idTeam);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT GRUNT
//------------------------------------------------------------------------------
void ProxyGame::createRobotGrunt(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotGrunt-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT LASER
//------------------------------------------------------------------------------
void ProxyGame::createRobotLaser(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotLaser-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT TOUGH
//------------------------------------------------------------------------------
void ProxyGame::createRobotTough(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotTough-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT SNIPER
//------------------------------------------------------------------------------
void ProxyGame::createRobotSniper(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotSniper-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PYRO
//------------------------------------------------------------------------------
void ProxyGame::createRobotPyro(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotPyro-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PSYCHO
//------------------------------------------------------------------------------
void ProxyGame::createRobotPsycho(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createRobotPsycho-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE MML
//------------------------------------------------------------------------------
void ProxyGame::createVehicleMML(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleMML-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE HEAVY TANK
//------------------------------------------------------------------------------
void ProxyGame::createVehicleHeavyTank(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleHeavyTank-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE LIGHT TANK
//------------------------------------------------------------------------------
void ProxyGame::createVehicleLightTank(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleLightTank-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE MEDIUM TANK
//------------------------------------------------------------------------------
void ProxyGame::createVehicleMediumTank(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleMediumTank-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE JEEP TANK
//------------------------------------------------------------------------------
void ProxyGame::createVehicleJeep(size_t idBuilding) {
    std::string command;
    command = aParser.armString("createVehicleJeep-%zu", idBuilding);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// MOVE UNIT TO
//------------------------------------------------------------------------------
void ProxyGame::moveUnitTo(uint32_t x, uint32_t y, size_t idUnit) {
    std::string command;
    command = aParser.armString("moveUnitTo-%u-%u-%zu", x, y, idUnit);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// ATTACK UNIT
//------------------------------------------------------------------------------
void ProxyGame::attackUnit(size_t idShooter, size_t idTarget) {
    std::string command;
    command = aParser.armString("attackUnit-%zu-%zu", idShooter, idTarget);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// ATTACK OBJECT
//------------------------------------------------------------------------------
void ProxyGame::attackObject(size_t idShooter, size_t idTarget) {
    std::string command;
    command = aParser.armString("attackObject-%zu-%zu", idShooter, idTarget);
    petitions.push(command);
}
//------------------------------------------------------------------------------
// UPDATE
//------------------------------------------------------------------------------
void ProxyGame::update() {
    std::string command;
    command = aParser.armString("update");
    petitions.push(command);
}
//------------------------------------------------------------------------------
// UNIT DIE
//------------------------------------------------------------------------------
void ProxyGame::unitDie(size_t id) {
    if (deadUnits.keyExist(id)) return;
    deadUnits(id, units[id]);
}
//------------------------------------------------------------------------------
// MUNITION DIE
//------------------------------------------------------------------------------
void ProxyGame::MunitionDie(size_t id) {
    if (obsoleteMunitions.keyExist(id)) return;
    obsoleteMunitions(id, munitions[id]);
}
//------------------------------------------------------------------------------
// OBJECT DIE
//------------------------------------------------------------------------------
void ProxyGame::objectDie(size_t id) {
    if (brokenObjects.keyExist(id)) return;
    brokenObjects(id, objects[id]);
}
//------------------------------------------------------------------------------
// KILL UNIT
//------------------------------------------------------------------------------
void ProxyGame::killUnit(size_t id) {
    ProxyUnit* aUnit = units[id];
    units.erase(id);
    delete aUnit;
}
//------------------------------------------------------------------------------
// KILL MUNITION
//------------------------------------------------------------------------------
void ProxyGame::killMunition(size_t id) {
    ProxyMunition* aMunition = munitions[id];
    munitions.erase(id);
    delete aMunition;
}
//------------------------------------------------------------------------------
// KILL OBJECT
//------------------------------------------------------------------------------
void ProxyGame::killObject(size_t id) {
    ProxyObject* anObject = objects[id];
    objects.erase(id);
    delete anObject;
}
//------------------------------------------------------------------------------
// REFRESH PROXY GAME
//------------------------------------------------------------------------------
void ProxyGame::cleanProxyGame() {
    Lock lock(aMutex);
    //--------------------------------------------------------------------------
    for (ProxyUnit* aUnit : deadUnits.getList()) {
        killUnit(aUnit->getId());
    }
    deadUnits.clear();
    //--------------------------------------------------------------------------
    for (ProxyMunition* aMunition : obsoleteMunitions.getList()) {
        killMunition(aMunition->getId());
    }
    obsoleteMunitions.clear();
    //--------------------------------------------------------------------------
    for (ProxyObject* anObject : brokenObjects.getList()) {
        if (anObject->isBridge() || anObject->isBuilding()) continue;
        killObject(anObject->getId());
    }
    brokenObjects.clear();
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
// CLEAN MUNITIONS
//------------------------------------------------------------------------------
void ProxyGame::cleanMunitions() {
    Lock lock(aMutex);
    for (ProxyMunition* aMunition : obsoleteMunitions.getList()) {
        killMunition(aMunition->getId());
    }
    obsoleteMunitions.clear();
}
//------------------------------------------------------------------------------
// CLEAN OBJECTS
//------------------------------------------------------------------------------
void ProxyGame::cleanObjects() {
    Lock lock(aMutex);
    for (ProxyObject* anObject : brokenObjects.getList()) {
        if (anObject->isBridge() || anObject->isBuilding()) continue;
        killObject(anObject->getId());
    }
    brokenObjects.clear();
}
//------------------------------------------------------------------------------
// CLEAN UNITS
//------------------------------------------------------------------------------
void ProxyGame::cleanUnits() {
    Lock lock(aMutex);
    for (ProxyUnit* aUnit : deadUnits.getList()) {
        killUnit(aUnit->getId());
    }
    deadUnits.clear();
}
//------------------------------------------------------------------------------
// CHECK NOT UPDATED MODEL
//------------------------------------------------------------------------------
void ProxyGame::checkNotUpdatedModel() {
    //--------------------------------------------------------------------------
    for (ProxyUnit* aUnit : units.getList()) {
        if (!aUnit->hasBeenUpdated()) {
            aUnit->changeState(DEAD);
            // printf("UNIT ID: %zu IS DEAD\n", aUnit->getId());
            unitDie(aUnit->getId());
        }
    }
    //--------------------------------------------------------------------------
    for (ProxyMunition* aMunition : munitions.getList()) {
        if (!aMunition->hasBeenUpdated()) {
            aMunition->changeState(OBSOLETE);
            // printf("MUNITION ID: %zu IS DEAD\n", aMunition->getId());
            MunitionDie(aMunition->getId());
        }
    }
    //--------------------------------------------------------------------------
    for (ProxyObject* anObject : objects.getList()) {
        if (!anObject->hasBeenUpdated()) {
            anObject->changeState(BROKEN);
            objectDie(anObject->getId());
        }
    }
    //--------------------------------------------------------------------------
}
//------------------------------------------------------------------------------
