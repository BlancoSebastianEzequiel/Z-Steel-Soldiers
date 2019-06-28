// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <iostream>
#include "clientProxyNode.h"
#include "clientProxyTerritories.h"
#include "../../libs/Exception.h"
//------------------------------------------------------------------------------
#define DUST "dust"
#define GRASS "grass"
#define SNOW "snow"
#define HIGHWAY "highway"
#define ASPHALT_ROAD "asphaltRoad"
#define WATER "water"
#define SWAMP "swamp"
#define LAVA "lava"
//------------------------------------------------------------------------------
// NODE CONSTRUCTOR
//------------------------------------------------------------------------------
ClientProxyNode::ClientProxyNode(uint32_t x, uint32_t y, std::string type):
        x(x), y(y), type(type) {
    anObject = NULL;
    wasAnObjectAdded = false;
    territory = nullptr;
}
//------------------------------------------------------------------------------
// NODE DESTRUCTOR
//------------------------------------------------------------------------------
ClientProxyNode::~ClientProxyNode() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ClientProxyNode::operator==(const ClientProxyNode& otherNode) const {
    return x == otherNode.getX() && y == otherNode.getY();
}
//------------------------------------------------------------------------------
// OPERATOR !=
//------------------------------------------------------------------------------
bool ClientProxyNode::operator!=(const ClientProxyNode& otherNode)const {
    return x != otherNode.getX() || y != otherNode.getY();
}
//------------------------------------------------------------------------------
// SHOW NODE
//------------------------------------------------------------------------------
void ClientProxyNode::showNode() const {
    printf("(x, y): (%u, %u)\n", x, y);
}
//------------------------------------------------------------------------------
// SET GROUND FACTOR
//------------------------------------------------------------------------------
void ClientProxyNode::setGroundFactor(float groundFactor) {
    this->groundFactor = groundFactor;
}
//------------------------------------------------------------------------------
// GET GROUND FACTOR
//------------------------------------------------------------------------------
const float& ClientProxyNode::getGroundFactor() const {
    return groundFactor;
}
//------------------------------------------------------------------------------
// ADD OBJECT
//------------------------------------------------------------------------------
void ClientProxyNode::addObject(ClientProxyObject *anObjectToAdd) {
    anObject = anObjectToAdd;
    wasAnObjectAdded = true;
}
//------------------------------------------------------------------------------
// HAS A GROUND OBJECT
//------------------------------------------------------------------------------
bool ClientProxyNode::hasAnObject() const {
    return wasAnObjectAdded;
}
//------------------------------------------------------------------------------
// GET GROUND OBJECT
//------------------------------------------------------------------------------
const ClientProxyObject* ClientProxyNode::getGroundObject() const {
    return anObject;
}
//------------------------------------------------------------------------------
// ADD TERRITORY
//------------------------------------------------------------------------------
void ClientProxyNode::addTerritory(const ClientProxyTerritories &aTerritory) {
    territory = &aTerritory;
}
//------------------------------------------------------------------------------
// GET ID TERRITORY
//------------------------------------------------------------------------------
size_t ClientProxyNode::getIdTerritory() const {
    return territory->getId();
}
//------------------------------------------------------------------------------
// GET PLAYER
//------------------------------------------------------------------------------
const size_t ClientProxyNode::getOwnerId() const {
    if (territory == nullptr) {
        throw Exception(
                "The territory pointer of the node: (%u, &u) is null\n", x, y);
    }
    return territory->getOwnerId();
}
//------------------------------------------------------------------------------
// GET X
//------------------------------------------------------------------------------
const uint32_t ClientProxyNode::getX() const {
    return x;
}
//------------------------------------------------------------------------------
// GET Y
//------------------------------------------------------------------------------
const uint32_t ClientProxyNode::getY() const {
    return y;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isLava() const {
    return type == LAVA;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isDust() const {
    return type == DUST;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isGrass() const {
    return type == GRASS;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isSnow() const {
    return type == SNOW;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isWater() const {
    return type == WATER;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isSwamp() const {
    return type == SWAMP;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isRoad() const {
    return type == HIGHWAY;
}
//------------------------------------------------------------------------------
// IS LAVA
//------------------------------------------------------------------------------
bool ClientProxyNode::isAsphaltRoad() const {
    return type == ASPHALT_ROAD;
}
//------------------------------------------------------------------------------
