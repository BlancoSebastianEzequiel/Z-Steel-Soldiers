// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverMediumTank.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// ServerMML CONSTRUCTOR
//------------------------------------------------------------------------------
ServerMediumTank::ServerMediumTank(
        const ServerNode& initialPosition, size_t id):
        ServerVehicle::ServerVehicle(initialPosition, id) {
    shootingFrequency = settings.vehicleMediumTank["shootingFrequency"];
    reach = settings.vehicleMediumTank["reach"];
    structurePoints = settings.vehicleMediumTank["structurePoints"];
    baseSpeed = settings.vehicleMediumTank["speedBase"];
    minimumTechnologyLevel = settings.vehicleMediumTank
    ["minimumTechnologyLevel"];
    munitionName = settings.vehicleMediumTankArmament["armament"];
}
//------------------------------------------------------------------------------
// ServerMML DESTRUCTOR
//------------------------------------------------------------------------------
ServerMediumTank::~ServerMediumTank() {}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ServerMediumTank::isGrunt() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TOUGH
//------------------------------------------------------------------------------
bool ServerMediumTank::isTough() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNIPER
//------------------------------------------------------------------------------
bool ServerMediumTank::isSniper() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PSYCHO
//------------------------------------------------------------------------------
bool ServerMediumTank::isPsycho() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PYRO
//------------------------------------------------------------------------------
bool ServerMediumTank::isPyro() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerMediumTank::isLaser() const {
    return false;
}
//------------------------------------------------------------------------------
// IS JEEP
//------------------------------------------------------------------------------
bool ServerMediumTank::isJeep() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MML
//------------------------------------------------------------------------------
bool ServerMediumTank::isMML() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LIGHT TANK
//------------------------------------------------------------------------------
bool ServerMediumTank::isLightTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MEDIUM TANK
//------------------------------------------------------------------------------
bool ServerMediumTank::isMediumTank() const {
    return true;
}
//------------------------------------------------------------------------------
// IS HEAVY TANK
//------------------------------------------------------------------------------
bool ServerMediumTank::isHeavyTank() const {
    return false;
}
//------------------------------------------------------------------------------
