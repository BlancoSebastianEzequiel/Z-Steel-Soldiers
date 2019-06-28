// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverRobotLaser.h"
#include "../../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// LASER CONSTRUCTOR
//------------------------------------------------------------------------------
ServerRobotLaser::ServerRobotLaser(
        const ServerNode& initialPosition, size_t id):
        ServerRobot::ServerRobot(initialPosition, id) {
    shootingFrequency = settings.robotLaser["shootingFrequency"];
    reach = settings.robotLaser["reach"];
    manufacturing = settings.robotLaser["manufacturing"];
    structurePoints = settings.robotLaser["structurePoints"];
    minimumTechnologyLevel = settings.robotLaser["minimumTechnologyLevel"];
    munitionName = settings.robotLaserArmament["armament"];
}
//------------------------------------------------------------------------------
// LASER DESTRUCTOR
//------------------------------------------------------------------------------
ServerRobotLaser::~ServerRobotLaser() {}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ServerRobotLaser::isGrunt() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TOUGH
//------------------------------------------------------------------------------
bool ServerRobotLaser::isTough() const {
    return false;
}
//------------------------------------------------------------------------------
// IS SNIPER
//------------------------------------------------------------------------------
bool ServerRobotLaser::isSniper() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PSYCHO
//------------------------------------------------------------------------------
bool ServerRobotLaser::isPsycho() const {
    return false;
}
//------------------------------------------------------------------------------
// IS PYRO
//------------------------------------------------------------------------------
bool ServerRobotLaser::isPyro() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerRobotLaser::isLaser() const {
    return true;
}
//------------------------------------------------------------------------------
// IS JEEP
//------------------------------------------------------------------------------
bool ServerRobotLaser::isJeep() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MML
//------------------------------------------------------------------------------
bool ServerRobotLaser::isMML() const {
    return false;
}
//------------------------------------------------------------------------------
// IS LIGHT TANK
//------------------------------------------------------------------------------
bool ServerRobotLaser::isLightTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MEDIUM TANK
//------------------------------------------------------------------------------
bool ServerRobotLaser::isMediumTank() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HEAVY TANK
//------------------------------------------------------------------------------
bool ServerRobotLaser::isHeavyTank() const {
    return false;
}
//------------------------------------------------------------------------------
