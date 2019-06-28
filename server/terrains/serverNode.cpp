// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <cmath>
#include <iostream>
#include "serverNode.h"
#include "../maps/serverMap.h"
#include "../objects/serverObject.h"
#include "../units/robots/serverRobot.h"
#include "../units/vehicles/serverVehicle.h"
#include "../territories/serverTerritories.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// NODE CONSTRUCTOR
//------------------------------------------------------------------------------
ServerNode::ServerNode(uint32_t x, uint32_t y): x(x), y(y) {
    infiniteCost = 99999999999999;
    anObject = NULL;
    hasAnObject = false;
    territory = nullptr;
}
//------------------------------------------------------------------------------
// NODE DESTRUCTOR
//------------------------------------------------------------------------------
ServerNode::~ServerNode() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ServerNode::operator==(const ServerNode& otherNode)const {
    return (x == otherNode.x && y == otherNode.y);
}
//------------------------------------------------------------------------------
// OPERATOR !=
//------------------------------------------------------------------------------
bool ServerNode::operator!=(const ServerNode& otherNode)const {
    return (x != otherNode.x || y != otherNode.y);
}
//------------------------------------------------------------------------------
// OPERATOR ()
//------------------------------------------------------------------------------
void ServerNode::operator()(uint32_t x, uint32_t y) {
    this->x = x;
    this->y = y;
}
//------------------------------------------------------------------------------
// GET ADJACENT
//------------------------------------------------------------------------------
float ServerNode::getGroundFactor()const {
    return groundFactor;
}
//------------------------------------------------------------------------------
// GET ADJACENT
//------------------------------------------------------------------------------
const std::vector<ServerNode*>& ServerNode::getAdjacent() const {
    return adjacent;
}
//------------------------------------------------------------------------------
// ADD ADJACENT
//------------------------------------------------------------------------------
void ServerNode::addAdjacent(const ServerMap& aMap) {
    aMap.addAdjacentTo(*this);
}
//------------------------------------------------------------------------------
// ADD GROUND OBJECT
//------------------------------------------------------------------------------
void ServerNode::addGroundObject(ServerObject* anObjectToAdd) {
    anObject = anObjectToAdd;
    hasAnObject = true;
}
//------------------------------------------------------------------------------
// SHOW NODE
//------------------------------------------------------------------------------
void ServerNode::showNode() const {
    printf("(x, y): (%u, %u)\n", x, y);
}
//------------------------------------------------------------------------------
// DISTANCE TO
//------------------------------------------------------------------------------
double ServerNode::distanceTo(const ServerNode& aNode) const {
    int dx = abs(static_cast<int>(aNode.x - x));
    int dy = abs(static_cast<int>(aNode.y - y));
    return sqrt(pow(dx, 2) + pow(dy, 2));
}
//------------------------------------------------------------------------------
// HAS A GROUND OBJECT
//------------------------------------------------------------------------------
bool ServerNode::hasAGroundObject() const {
    return hasAnObject;
}
//------------------------------------------------------------------------------
// GET GROUND OBJECT
//------------------------------------------------------------------------------
const ServerObject* ServerNode::getGroundObject() const {
    return anObject;
}
//------------------------------------------------------------------------------
// ADD TERRITORY
//------------------------------------------------------------------------------
void ServerNode::addTerritory(const ServerTerritories &aTerritory) {
    territory = &aTerritory;
}
//------------------------------------------------------------------------------
// GET ID TERRITORY
//------------------------------------------------------------------------------
size_t ServerNode::getIdTerritory() const {
    return territory->getId();
}
//------------------------------------------------------------------------------
// GET PLAYER
//------------------------------------------------------------------------------
const ServerPlayer* ServerNode::getOwner() const {
    if (territory == nullptr) {
        throw Exception(
                "The territory pointer of the node: (%u, &u) is null\n", x, y);
    }
    return territory->getOwner();
}
//------------------------------------------------------------------------------
// GET X
//------------------------------------------------------------------------------
const uint32_t ServerNode::getX() const {
    return x;
}
//------------------------------------------------------------------------------
// GET Y
//------------------------------------------------------------------------------
const uint32_t ServerNode::getY() const {
    return y;
}
//------------------------------------------------------------------------------
