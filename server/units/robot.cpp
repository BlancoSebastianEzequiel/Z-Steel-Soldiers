// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../terrains/node.h"
#include "robot.h"
#include "../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// ROBOT CONSTRUCTOR
//------------------------------------------------------------------------------
Robot::Robot(const Node &initialPosition, size_t id, size_t type):
        Unit::Unit(initialPosition, id, type) {
    shootingFrequency = settings.units[type]["shootingFrequency"];
    reach = settings.units[type]["reach"];
    structurePoints = settings.units[type]["structurePoints"];
    manufacturing = settings.units[type]["manufacturing"];
    minimumTechnologyLevel = settings.units[type]["minimumTechnologyLevel"];
    munitionName = settings.unitsArmament[type]["armament"];
}
//------------------------------------------------------------------------------
// ROBOT DESTRUCTOR
//------------------------------------------------------------------------------
Robot::~Robot() {}
//------------------------------------------------------------------------------
// GET COST
//------------------------------------------------------------------------------
double Robot::getCost(const Node &aNode) {
    return aNode.getRobotCost(*this);
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double Robot::getSpeed(const Node &aNode) const {
    float finalVelocity;
    finalVelocity = 4 * aNode.getGroundFactor();
    if (finalVelocity > 1) {
        return finalVelocity;
    }
    return 1;
}
//------------------------------------------------------------------------------
// CAN PASS THROUGH
//------------------------------------------------------------------------------
bool Robot::canPassThrough(const Node &aNode) const {
    return aNode.robotPassThrough();
}
//------------------------------------------------------------------------------
// IS VEHICLE
//------------------------------------------------------------------------------
bool Robot::isVehicle() const {
    return false;
}
