// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include "serverVehicleFactorie.h"
//------------------------------------------------------------------------------
// VEHICLE FACTORIE CONSTRUCTOR
//------------------------------------------------------------------------------
ServerVehicleFactorie::ServerVehicleFactorie(
        ServerNode &position, size_t id, size_t tecnologyLevel):
        ServerBuildings::ServerBuildings(position, id, tecnologyLevel) {}
//------------------------------------------------------------------------------
// VEHICLE FACTORIE DESTRUCTOR
//------------------------------------------------------------------------------
ServerVehicleFactorie::~ServerVehicleFactorie() {}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool ServerVehicleFactorie::isFort() const {
    return false;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool ServerVehicleFactorie::isVehicleFactorie() const {
    return true;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool ServerVehicleFactorie::isRobotFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
