// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverFlamethrower.h"
#include "../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// FLAMETHROWER CONSTRUCTOR
//------------------------------------------------------------------------------
ServerFlamethrower::ServerFlamethrower(
        const ServerNode& position, size_t id, const ServerUnit& shooter):
        ServerArmament::ServerArmament(position, id, shooter) {
    damage = settings.flamethrower["damage"];
}
//------------------------------------------------------------------------------
// FLAMETHROWER DESTRUCTOR
//------------------------------------------------------------------------------
ServerFlamethrower::~ServerFlamethrower() {}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerFlamethrower::isLaser()const {
    return false;
}
//------------------------------------------------------------------------------
// IS FLAMETHROWER
//------------------------------------------------------------------------------
bool ServerFlamethrower::isFlamethrower() const {
    return true;
}
//------------------------------------------------------------------------------
// IS HIGH CALIBER PROJECTILES
//------------------------------------------------------------------------------
bool ServerFlamethrower::isHighCaliberProjectiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MISSILES
//------------------------------------------------------------------------------
bool ServerFlamethrower::isMissiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BULLETS
//------------------------------------------------------------------------------
bool ServerFlamethrower::isBullets() const {
    return false;
}
//------------------------------------------------------------------------------
