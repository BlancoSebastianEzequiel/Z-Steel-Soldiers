// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverPyro.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// PYRO CONSTRUCTOR
//------------------------------------------------------------------------------
ServerPyro::ServerPyro(const ServerNode& initialPosition, size_t id):
        ServerRobot::ServerRobot(initialPosition, id) {
    shootingFrequency = settings.robotPyro["shootingFrequency"];
    reach = settings.robotPyro["reach"];
    manufacturing = settings.robotPyro["manufacturing"];
    structurePoints = settings.robotPyro["structurePoints"];
    minimumTechnologyLevel = settings.robotPyro["minimumTechnologyLevel"];
    munitionName = settings.robotPyroArmament["armament"];
}
//------------------------------------------------------------------------------
// PYRO DESTRUCTOR
//------------------------------------------------------------------------------
ServerPyro::~ServerPyro() {}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ServerPyro::isGrunt() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TOUGH
//------------------------------------------------------------------------------
bool ServerPyro::isTough() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNIPER
//------------------------------------------------------------------------------
bool ServerPyro::isSniper() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PSYCHO
//------------------------------------------------------------------------------
bool ServerPyro::isPsycho() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PYRO
//------------------------------------------------------------------------------
bool ServerPyro::isPyro() const {
    return true;
}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerPyro::isLaser() const {
    return false;
}
//------------------------------------------------------------------------------
// IS JEEP
//------------------------------------------------------------------------------
bool ServerPyro::isJeep() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MML
//------------------------------------------------------------------------------
bool ServerPyro::isMML() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LIGHT TANK
//------------------------------------------------------------------------------
bool ServerPyro::isLightTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MEDIUM TANK
//------------------------------------------------------------------------------
bool ServerPyro::isMediumTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HEAVY TANK
//------------------------------------------------------------------------------
bool ServerPyro::isHeavyTank() const {
    return false;
}
//------------------------------------------------------------------------------
