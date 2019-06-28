// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverJeep.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// JEEP CONSTRUCTOR
//------------------------------------------------------------------------------
ServerJeep::ServerJeep(const ServerNode& initialPosition, size_t id):
        ServerVehicle::ServerVehicle(initialPosition, id) {
    shootingFrequency = settings.vehicleJeep["shootingFrequency"];
    reach = settings.vehicleJeep["reach"];
    structurePoints = settings.vehicleJeep["structurePoints"];
    baseSpeed = settings.vehicleJeep["speedBase"];
    minimumTechnologyLevel = settings.vehicleJeep["minimumTechnologyLevel"];
    munitionName = settings.vehicleJeepArmament["armament"];
}
//------------------------------------------------------------------------------
// JEEP DESTRUCTOR
//------------------------------------------------------------------------------
ServerJeep::~ServerJeep() {}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ServerJeep::isGrunt() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TOUGH
//------------------------------------------------------------------------------
bool ServerJeep::isTough() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNIPER
//------------------------------------------------------------------------------
bool ServerJeep::isSniper() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PSYCHO
//------------------------------------------------------------------------------
bool ServerJeep::isPsycho() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PYRO
//------------------------------------------------------------------------------
bool ServerJeep::isPyro() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerJeep::isLaser() const {
    return false;
}
//------------------------------------------------------------------------------
// IS JEEP
//------------------------------------------------------------------------------
bool ServerJeep::isJeep() const {
    return true;
}
//------------------------------------------------------------------------------
// IS MML
//------------------------------------------------------------------------------
bool ServerJeep::isMML() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LIGHT TANK
//------------------------------------------------------------------------------
bool ServerJeep::isLightTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MEDIUM TANK
//------------------------------------------------------------------------------
bool ServerJeep::isMediumTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HEAVY TANK
//------------------------------------------------------------------------------
bool ServerJeep::isHeavyTank() const {
    return false;
}
//------------------------------------------------------------------------------
