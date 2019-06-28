// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverLightTank.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// LIGHT TANK CONSTRUCTOR
//------------------------------------------------------------------------------
ServerLightTank::ServerLightTank(const ServerNode& initialPosition, size_t id):
        ServerVehicle::ServerVehicle(initialPosition, id) {
    shootingFrequency = settings.vehicleLightTank["shootingFrequency"];
    reach = settings.vehicleLightTank["reach"];
    structurePoints = settings.vehicleLightTank["structurePoints"];
    baseSpeed = settings.vehicleLightTank["speedBase"];
    minimumTechnologyLevel = settings.vehicleLightTank
    ["minimumTechnologyLevel"];
    munitionName = settings.vehicleLightTankArmament["armament"];
}
//------------------------------------------------------------------------------
// LIGHT TANK DESTRUCTOR
//------------------------------------------------------------------------------
ServerLightTank::~ServerLightTank() {}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ServerLightTank::isGrunt() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TOUGH
//------------------------------------------------------------------------------
bool ServerLightTank::isTough() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNIPER
//------------------------------------------------------------------------------
bool ServerLightTank::isSniper() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PSYCHO
//------------------------------------------------------------------------------
bool ServerLightTank::isPsycho() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PYRO
//------------------------------------------------------------------------------
bool ServerLightTank::isPyro() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerLightTank::isLaser() const {
    return false;
}
//------------------------------------------------------------------------------
// IS JEEP
//------------------------------------------------------------------------------
bool ServerLightTank::isJeep() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MML
//------------------------------------------------------------------------------
bool ServerLightTank::isMML() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LIGHT TANK
//------------------------------------------------------------------------------
bool ServerLightTank::isLightTank() const {
    return true;
}
//------------------------------------------------------------------------------
// IS MEDIUM TANK
//------------------------------------------------------------------------------
bool ServerLightTank::isMediumTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HEAVY TANK
//------------------------------------------------------------------------------
bool ServerLightTank::isHeavyTank() const {
    return false;
}
//------------------------------------------------------------------------------
