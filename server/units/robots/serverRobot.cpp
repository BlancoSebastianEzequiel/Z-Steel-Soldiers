// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../terrains/serverNode.h"
#include "serverRobot.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// ROBOT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerRobot::ServerRobot(const ServerNode& initialPosition, size_t id):
        ServerUnit::ServerUnit(initialPosition, id) {}
//------------------------------------------------------------------------------
// ROBOT DESTRUCTOR
//------------------------------------------------------------------------------
ServerRobot::~ServerRobot() {}
//------------------------------------------------------------------------------
// GET COST
//------------------------------------------------------------------------------
double ServerRobot::getCost(const ServerNode &aNode) {
    return aNode.getRobotCost(*this);
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double ServerRobot::getSpeed(const ServerNode &aNode) const {
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
bool ServerRobot::canPassThrough(const ServerNode &aNode) const {
    return aNode.robotPassThrough();
}
//------------------------------------------------------------------------------
// IS ROBOT
//------------------------------------------------------------------------------
bool ServerRobot::isRobot() const {
    return true;
}
//------------------------------------------------------------------------------
// IS VEHICLE
//------------------------------------------------------------------------------
bool ServerRobot::isVehicle() const {
    return false;
}
//------------------------------------------------------------------------------
