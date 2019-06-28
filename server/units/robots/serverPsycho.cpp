// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "../../terrains/serverNode.h"
#include "serverPsycho.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// PSYCHO CONSTRUCTOR
//------------------------------------------------------------------------------
ServerPsycho::ServerPsycho(const ServerNode& initialPosition, size_t id):
        ServerRobot::ServerRobot(initialPosition, id) {
    shootingFrequency = settings.robotPsycho["shootingFrequency"];
    reach = settings.robotPsycho["reach"];
    manufacturing = settings.robotPsycho["manufacturing"];
    structurePoints = settings.robotPsycho["structurePoints"];
    minimumTechnologyLevel = settings.robotPsycho["minimumTechnologyLevel"];
    munitionName = settings.robotPsychoArmament["armament"];
}
//------------------------------------------------------------------------------
// PSYCHO DESTRUCTOR
//------------------------------------------------------------------------------
ServerPsycho::~ServerPsycho() {}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ServerPsycho::isGrunt() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TOUGH
//------------------------------------------------------------------------------
bool ServerPsycho::isTough() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNIPER
//------------------------------------------------------------------------------
bool ServerPsycho::isSniper() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PSYCHO
//------------------------------------------------------------------------------
bool ServerPsycho::isPsycho() const {
    return true;
}
//------------------------------------------------------------------------------
// IS PYRO
//------------------------------------------------------------------------------
bool ServerPsycho::isPyro() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerPsycho::isLaser() const {
    return false;
}
//------------------------------------------------------------------------------
// IS JEEP
//------------------------------------------------------------------------------
bool ServerPsycho::isJeep() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MML
//------------------------------------------------------------------------------
bool ServerPsycho::isMML() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LIGHT TANK
//------------------------------------------------------------------------------
bool ServerPsycho::isLightTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MEDIUM TANK
//------------------------------------------------------------------------------
bool ServerPsycho::isMediumTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HEAVY TANK
//------------------------------------------------------------------------------
bool ServerPsycho::isHeavyTank() const {
    return false;
}
//------------------------------------------------------------------------------
