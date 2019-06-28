// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverHeavyTank.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// ServerMML CONSTRUCTOR
//------------------------------------------------------------------------------
ServerHeavyTank::ServerHeavyTank(const ServerNode& initialPosition, size_t id):
        ServerVehicle::ServerVehicle(initialPosition, id) {
    shootingFrequency = settings.vehicleHeavyTank["shootingFrequency"];
    reach = settings.vehicleHeavyTank["reach"];
    structurePoints = settings.vehicleHeavyTank["structurePoints"];
    baseSpeed = settings.vehicleHeavyTank["speedBase"];
    minimumTechnologyLevel = settings.vehicleHeavyTank
    ["minimumTechnologyLevel"];
    munitionName = settings.vehicleHeavyTankArmament["armament"];
}
//------------------------------------------------------------------------------
// ServerMML DESTRUCTOR
//------------------------------------------------------------------------------
ServerHeavyTank::~ServerHeavyTank() {}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ServerHeavyTank::isGrunt() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TOUGH
//------------------------------------------------------------------------------
bool ServerHeavyTank::isTough() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNIPER
//------------------------------------------------------------------------------
bool ServerHeavyTank::isSniper() const {
    return false;}
//------------------------------------------------------------------------------
// IS PSYCHO
//------------------------------------------------------------------------------
bool ServerHeavyTank::isPsycho() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PYRO
//------------------------------------------------------------------------------
bool ServerHeavyTank::isPyro() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerHeavyTank::isLaser() const {
    return false;
}
//------------------------------------------------------------------------------
// IS JEEP
//------------------------------------------------------------------------------
bool ServerHeavyTank::isJeep() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MML
//------------------------------------------------------------------------------
bool ServerHeavyTank::isMML() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LIGHT TANK
//------------------------------------------------------------------------------
bool ServerHeavyTank::isLightTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MEDIUM TANK
//------------------------------------------------------------------------------
bool ServerHeavyTank::isMediumTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HEAVY TANK
//------------------------------------------------------------------------------
bool ServerHeavyTank::isHeavyTank() const {
    return true;
}
//------------------------------------------------------------------------------
