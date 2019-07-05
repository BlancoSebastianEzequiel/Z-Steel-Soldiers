// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "player.h"
#include "../maps/map.h"
#include "../units/robots/grunt.h"
#include "../units/robots/robotLaser.h"
#include "../units/robots/tough.h"
#include "../units/robots/sniper.h"
#include "../units/robots/pyro.h"
#include "../units/robots/psycho.h"
#include "../units/vehicles/MML.h"
#include "../units/vehicles/heavyTank.h"
#include "../units/vehicles/lightTank.h"
#include "../units/vehicles/mediumTank.h"
#include "../units/vehicles/jeep.h"
#include "../objects/buildings/buildings.h"
#include "../territories/territories.h"
#include "../teams/team.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// PLAYER CONSTRUCTOR
//------------------------------------------------------------------------------
Player::Player(Map& aMap, size_t id): aMap(aMap), id(id) {
    takenTerritories = 0;
}
//------------------------------------------------------------------------------
// PLAYER DESTRUCTOR
//------------------------------------------------------------------------------
Player::~Player() {
    for (Unit* aUnit : units.getList()) {
        delete aUnit;
    }
}
//------------------------------------------------------------------------------
// CREATE ROBOT GRUNT
//------------------------------------------------------------------------------
void Player::createRobotGrunt(uint32_t x, uint32_t y, size_t id) {
    units(id, new Grunt(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT LASER
//------------------------------------------------------------------------------
void Player::createRobotLaser(uint32_t x, uint32_t y, size_t id) {
    units(id, new RobotLaser(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT TOUGH
//------------------------------------------------------------------------------
void Player::createRobotTough(uint32_t x, uint32_t y, size_t id) {
    units(id, new Tough(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT SNIPER
//------------------------------------------------------------------------------
void Player::createRobotSniper(uint32_t x, uint32_t y, size_t id) {
    units(id, new Sniper(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PYRO
//------------------------------------------------------------------------------
void Player::createRobotPyro(uint32_t x, uint32_t y, size_t id) {
    units(id, new Pyro(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE ROBOT PSYCHO
//------------------------------------------------------------------------------
void Player::createRobotPsycho(uint32_t x, uint32_t y, size_t id) {
    units(id, new Psycho(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE MML
//------------------------------------------------------------------------------
void Player::createVehicleMML(uint32_t x, uint32_t y, size_t id) {
    units(id, new MML(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE HEAVY TANK
//------------------------------------------------------------------------------
void Player::createVehicleHeavyTank(uint32_t x, uint32_t y, size_t id) {
    units(id, new HeavyTank(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE LIGHT TANK
//------------------------------------------------------------------------------
void Player::createVehicleLightTank(uint32_t x, uint32_t y, size_t id) {
    units(id, new LightTank(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE MEDIUM TANK
//------------------------------------------------------------------------------
void Player::createVehicleMediumTank(uint32_t x, uint32_t y, size_t id) {
    units(id, new MediumTank(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE JEEP TANK
//------------------------------------------------------------------------------
void Player::createVehicleJeep(uint32_t x, uint32_t y, size_t id) {
    units(id, new Jeep(*aMap.getNode(x, y), id));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// GET UNIT
//------------------------------------------------------------------------------
Unit* Player::getUnit(size_t id) {
    return units[id];
}
//------------------------------------------------------------------------------
// GET TAKEN TERRITORIES
//------------------------------------------------------------------------------
size_t Player::getTakenTerritories() const {
    return territories.size();
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t & Player::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// IS ENEMY
//------------------------------------------------------------------------------
bool Player::isEnemy(const Player& aPlayer) const {
    return !team->belongs(aPlayer);
}
//------------------------------------------------------------------------------
// GET UNITS
//------------------------------------------------------------------------------
unitsMap& Player::getUnits() {
    return units;
}
//------------------------------------------------------------------------------
// DELETE TERRITORY
//------------------------------------------------------------------------------
void Player::deleteTerritory(size_t id) {
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
const Territories* Player::getTerritoryWithBuilding() {
    for (const Territories* aTerritory : territories) {
        Buildings* building = aTerritory->getBuilding();
        if (building != nullptr) return aTerritory;
    }
    throw Exception("player id:%d does not has a territory with a building", id);
    // return nullptr;
}
//------------------------------------------------------------------------------
// ADD TERRITORY
//------------------------------------------------------------------------------
void Player::addTerritory(const Territories &aTerritory) {
    territories.push_back(&aTerritory);
}
//------------------------------------------------------------------------------
// ADD TEAM
//------------------------------------------------------------------------------
void Player::addTeam(Team& aTeam) {
    team = &aTeam;
}
//------------------------------------------------------------------------------
// GET TEAM
//------------------------------------------------------------------------------
Team * Player::getTeam() const {
    return team;
}
//------------------------------------------------------------------------------
// HAS LOST
//------------------------------------------------------------------------------
bool Player::hasLost() const {
    return getTakenTerritories() == 0 || units.size() == 0;  // ver dsp
}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool Player::operator==(const Player& aPlayer) const {
    return this->id == aPlayer.getId();
}
//------------------------------------------------------------------------------
// OPERATOR !=
//------------------------------------------------------------------------------
bool Player::operator!=(const Player& aPlayer) const {
    return this->id != aPlayer.getId();
}
//------------------------------------------------------------------------------
