// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverArmamentLaser.h"
#include "../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// ARMAMENT LASER CONSTRUCTOR
//------------------------------------------------------------------------------
ServerArmamentLaser::ServerArmamentLaser(
        const ServerNode& position, size_t id,
        const ServerUnit& shooter):
        ServerArmament::ServerArmament(position, id, shooter) {
    damage = settings.laser["damage"];
}
//------------------------------------------------------------------------------
// ARMAMENT LASER DESTRUCTOR
//------------------------------------------------------------------------------
ServerArmamentLaser::~ServerArmamentLaser() {}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerArmamentLaser::isLaser()const {
    return true;
}
//------------------------------------------------------------------------------
// IS FLAMETHROWER
//------------------------------------------------------------------------------
bool ServerArmamentLaser::isFlamethrower() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HIGH CALIBER PROJECTILES
//------------------------------------------------------------------------------
bool ServerArmamentLaser::isHighCaliberProjectiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MISSILES
//------------------------------------------------------------------------------
bool ServerArmamentLaser::isMissiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BULLETS
//------------------------------------------------------------------------------
bool ServerArmamentLaser::isBullets() const {
    return false;
}
//------------------------------------------------------------------------------
