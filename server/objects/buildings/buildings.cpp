// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include <cmath>
#include "buildings.h"
#include "../../units/unit.h"
#include "../../settings/settings.h"
#include "../../terrains/node.h"
#include "../../maps/map.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// BUILDINGS CONSTRUCTOR
//------------------------------------------------------------------------------
Buildings::Buildings(
        Node &position, size_t id, size_t tecnologyLevel):
        Object::Object(position, id),
        tecnologyLevel(tecnologyLevel) {
    structurePoints = (size_t) settings.Buildings["structurePoints"];
    for (unit_t* aUnit: settings.units.getList()) {
        unitManufacturingTime(
                (size_t) (*aUnit)["name"], (*aUnit)["baseManufacturingTime"]);
    }
}
//------------------------------------------------------------------------------
// BUILDINGS DESTRUCTOR
//------------------------------------------------------------------------------
Buildings::~Buildings() {}
//------------------------------------------------------------------------------
// ADD OBJECT TO NODES
//------------------------------------------------------------------------------
void Buildings::addObjectToNodes(Map& aMap) {
    uint32_t x = principalPosition.getX();
    uint32_t y = principalPosition.getY();
    Node* right = aMap.getNode(x+1, y);
    Node* left = aMap.getNode(x, y+1);
    Node* diagonal = aMap.getNode(x+1, y+1);
    principalPosition.addGroundObject(this);
    right->addGroundObject(this);
    left->addGroundObject(this);
    diagonal->addGroundObject(this);
    positions.push_back(right);
    positions.push_back(left);
    positions.push_back(diagonal);
    positions.push_back(&principalPosition);
    wasAdded = true;
}
//------------------------------------------------------------------------------
// GET TECNOLOGY LEVEL
//------------------------------------------------------------------------------
size_t Buildings::getTecnologyLevel() const {
    return tecnologyLevel;
}
//------------------------------------------------------------------------------
// CAN PASS THROUGH
//------------------------------------------------------------------------------
bool Buildings::canPassThrough() const {
    return false;
}
//------------------------------------------------------------------------------
// GET DAMAGE STRUCTURE REL
//------------------------------------------------------------------------------
float Buildings::getDamageStructureRel() const {
    return damageReceived / structurePoints;
}
//------------------------------------------------------------------------------
// MANUFACTURING TIME
//------------------------------------------------------------------------------
double Buildings::manufacturingTime(
        size_t takenTerritories, float baseManufacturingTime) {
    return (baseManufacturingTime / takenTerritories) /
            (sqrt(1 - getDamageStructureRel()));
}
//------------------------------------------------------------------------------
// GRUNT MANUFACTURING TIME
//------------------------------------------------------------------------------
double
Buildings::getUnitManufacturingTime(size_t takenTerritories, size_t type) {
    return manufacturingTime(takenTerritories, unitManufacturingTime[type]);
}
//------------------------------------------------------------------------------
// ADD PLAYER
//------------------------------------------------------------------------------
void Buildings::addPlayer(Player* aPlayer) {
    player = aPlayer;
}
//------------------------------------------------------------------------------
// GET CREATION POSITION
//------------------------------------------------------------------------------
Node* Buildings::getCreationPosition() {
    return getWalkableNode();
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool Buildings::isBuilding() const {
    return true;
}
//------------------------------------------------------------------------------
// IS FLAG
//------------------------------------------------------------------------------
bool Buildings::isFlag() const {
    return false;
}
//------------------------------------------------------------------------------
// IS STONE
//------------------------------------------------------------------------------
bool Buildings::isStone() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ICE BLOCK
//------------------------------------------------------------------------------
bool Buildings::isIceBlock() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BRIDGE
//------------------------------------------------------------------------------
bool Buildings::isBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool Buildings::isWoodenBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool Buildings::isConcreteBridge() const {
    return false;
}
//------------------------------------------------------------------------------
