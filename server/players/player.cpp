// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "player.h"
#include "../maps/map.h"
#include "../units/robot.h"
#include "../units/vehicle.h"
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
// CREATE ROBOT
//------------------------------------------------------------------------------
void Player::createRobot(uint32_t x, uint32_t y, size_t id, std::string type) {
    units(id, new Robot(*aMap.getNode(x, y), id, type));
    units[id]->addPlayer(*this);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE
//------------------------------------------------------------------------------
void Player::createVehicle(uint32_t x, uint32_t y, size_t id, std::string type) {
    units(id, new Vehicle(*aMap.getNode(x, y), id, type));
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
