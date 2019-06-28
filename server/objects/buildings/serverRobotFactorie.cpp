// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include "serverRobotFactorie.h"
//------------------------------------------------------------------------------
// ROBOT FACTORIE CONSTRUCTOR
//------------------------------------------------------------------------------
ServerRobotFactorie::ServerRobotFactorie(
        ServerNode &position, size_t id, size_t tecnologyLevel):
        ServerBuildings::ServerBuildings(position, id, tecnologyLevel) {}
//------------------------------------------------------------------------------
// ROBOT FACTORIE DESTRUCTOR
//------------------------------------------------------------------------------
ServerRobotFactorie::~ServerRobotFactorie() {}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool ServerRobotFactorie::isFort() const {
    return false;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool ServerRobotFactorie::isVehicleFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool ServerRobotFactorie::isRobotFactorie() const {
    return true;
}
//------------------------------------------------------------------------------
