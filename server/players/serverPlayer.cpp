// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverPlayer.h"
#include "../maps/serverMap.h"
#include "../units/robots/serverGrunt.h"
#include "../units/robots/serverRobotLaser.h"
#include "../units/robots/serverTough.h"
#include "../units/robots/serverSniper.h"
#include "../units/robots/serverPyro.h"
#include "../units/robots/serverPsycho.h"
#include "../units/vehicles/serverMML.h"
#include "../units/vehicles/serverHeavyTank.h"
#include "../units/vehicles/serverLightTank.h"
#include "../units/vehicles/serverMediumTank.h"
#include "../units/vehicles/serverJeep.h"
#include "../objects/buildings/serverBuildings.h"
#include "../territories/serverTerritories.h"
#include "../teams/serverTeam.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// PLAYER CONSTRUCTOR
//------------------------------------------------------------------------------
ServerPlayer::ServerPlayer(ServerMap& aMap, size_t id): aMap(aMap), id(id) {
    takenTerritories = 0;
}
//------------------------------------------------------------------------------
// PLAYER DESTRUCTOR
//------------------------------------------------------------------------------
ServerPlayer::~ServerPlayer() {
    for (ServerUnit* aUnit : units.getList()) {
        delete aUnit;
    }
}
//------------------------------------------------------------------------------
// CREATE ROBOT GRUNT
//------------------------------------------------------------------------------
void ServerPlayer::createRobotGrunt(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerGrunt(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT LASER
//------------------------------------------------------------------------------
void ServerPlayer::createRobotLaser(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerRobotLaser(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT TOUGH
//------------------------------------------------------------------------------
void ServerPlayer::createRobotTough(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerTough(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT SNIPER
//------------------------------------------------------------------------------
void ServerPlayer::createRobotSniper(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerSniper(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PYRO
//------------------------------------------------------------------------------
void ServerPlayer::createRobotPyro(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerPyro(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PSYCHO
//------------------------------------------------------------------------------
void ServerPlayer::createRobotPsycho(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerPsycho(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE ServerMML
//------------------------------------------------------------------------------
void ServerPlayer::createVehicleMML(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerMML(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE HEAVY TANK
//------------------------------------------------------------------------------
void ServerPlayer::createVehicleHeavyTank(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerHeavyTank(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE LIGHT TANK
//------------------------------------------------------------------------------
void ServerPlayer::createVehicleLightTank(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerLightTank(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE MEDIUM TANK
//------------------------------------------------------------------------------
void ServerPlayer::createVehicleMediumTank(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerMediumTank(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE JEEP TANK
//------------------------------------------------------------------------------
void ServerPlayer::createVehicleJeep(uint32_t x, uint32_t y, size_t id) {
    units(id, new ServerJeep(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// GET UNIT
//------------------------------------------------------------------------------
ServerUnit* ServerPlayer::getUnit(size_t id) {
    return units[id];
}
//------------------------------------------------------------------------------
// GET TAKEN TERRITORIES
//------------------------------------------------------------------------------
size_t ServerPlayer::getTakenTerritories() const {
    return territories.size();
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t & ServerPlayer::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// IS ENEMY
//------------------------------------------------------------------------------
bool ServerPlayer::isEnemy(const ServerPlayer& aPlayer) const {
    return !team->belongs(aPlayer);
}
//------------------------------------------------------------------------------
// GET UNITS
//------------------------------------------------------------------------------
unitsMap& ServerPlayer::getUnits() {
    return units;
}
//------------------------------------------------------------------------------
// DELETE TERRITORY
//------------------------------------------------------------------------------
void ServerPlayer::deleteTerritory(size_t id) {
    for (size_t i = 0; i < territories.size(); i++) {
        if (territories[i]->getId() == id) {
            territories.erase(territories.begin()+i);
            break;
        }
    }
}
//------------------------------------------------------------------------------
// GET TERRITORY WITH BUILDING
//------------------------------------------------------------------------------
const ServerTerritories* ServerPlayer::getTerritoryWithBuilding() {
    for (const ServerTerritories* aTerritory : territories) {
        ServerBuildings* building = aTerritory->getBuilding();
        if (building != nullptr) return aTerritory;
    }
    throw Exception("player id:%d does not has a territory with a building", id);
    // return nullptr;
}
//------------------------------------------------------------------------------
// ADD TERRITORY
//------------------------------------------------------------------------------
void ServerPlayer::addTerritory(const ServerTerritories &aTerritory) {
    territories.push_back(&aTerritory);
}
//------------------------------------------------------------------------------
// ADD TEAM
//------------------------------------------------------------------------------
void ServerPlayer::addTeam(ServerTeam& aTeam) {
    team = &aTeam;
}
//------------------------------------------------------------------------------
// GET TEAM
//------------------------------------------------------------------------------
ServerTeam * ServerPlayer::getTeam() const {
    return team;
}
//------------------------------------------------------------------------------
// HAS LOST
//------------------------------------------------------------------------------
bool ServerPlayer::hasLost() const {
    return getTakenTerritories() == 0 || units.size() == 0;  // ver dsp
}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ServerPlayer::operator==(const ServerPlayer& aPlayer) const {
    return this->id == aPlayer.getId();
}
//------------------------------------------------------------------------------
// OPERATOR !=
//------------------------------------------------------------------------------
bool ServerPlayer::operator!=(const ServerPlayer& aPlayer) const {
    return this->id != aPlayer.getId();
}
//------------------------------------------------------------------------------
