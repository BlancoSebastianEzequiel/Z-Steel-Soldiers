#include <vector>
#include <cmath>
#include <iostream>
#include "node.h"
#include "../maps/map.h"
#include "behavior/terrainBehavior.h"
#include "../units/unit.h"
#include "../territories/territories.h"
#include "../settings/settings.h"

extern Settings settings;

Node::Node(uint32_t x, uint32_t y, size_t type): x(x), y(y) {
    territory = nullptr;
    terrain_t* terrainSettings = settings.terrains[type];
    behavior = TerrainBehavior::getInstance(*terrainSettings, type);
}

Node::~Node() {
    delete behavior;
}

bool Node::operator==(const Node& otherNode)const {
    return (x == otherNode.x && y == otherNode.y);
}

bool Node::operator!=(const Node& otherNode)const {
    return (x != otherNode.x || y != otherNode.y);
}

void Node::operator()(uint32_t x, uint32_t y) {
    this->x = x;
    this->y = y;
}

float Node::getGroundFactor()const {
    return behavior->getGroundFactor();
}

const std::vector<Node*>& Node::getAdjacent() const {
    return adjacent;
}

void Node::addAdjacent(const Map& aMap) {
    aMap.addAdjacentTo(*this);
}

void Node::addGroundObject(Object* anObjectToAdd) {
    behavior->addGroundObject(anObjectToAdd);
}

double Node::distanceTo(const Node& aNode) const {
    int dx = abs(static_cast<int>(aNode.x - x));
    int dy = abs(static_cast<int>(aNode.y - y));
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

bool Node::hasAGroundObject() const {
    return behavior->hasAGroundObject();
}

const Object* Node::getGroundObject() const {
    return behavior->getGroundObject();
}

void Node::addTerritory(const Territories &aTerritory) {
    territory = &aTerritory;
}

size_t Node::getIdTerritory() const {
    return territory->getId();
}

const Player* Node::getOwner() const {
    if (territory == nullptr) {
        throw Exception(
                "The territory pointer of the node: (%u, &u) is null\n", x, y);
    }
    return territory->getOwner();
}

const uint32_t Node::getX() const {
    return x;
}

const uint32_t Node::getY() const {
    return y;
}

size_t Node::getType() {
    return behavior->getType();
}

double Node::getVehicleCost(const Unit &aVehicle) const {
    return behavior->getVehicleCost(aVehicle, *this);
}

double Node::getRobotCost(const Unit &aRobot) const {
    return behavior->getRobotCost(aRobot, *this);
}

bool Node::vehiclePassThrough() const {
    return behavior->vehiclePassThrough();
}

bool Node::robotPassThrough() const {
    return behavior->robotPassThrough();
}
