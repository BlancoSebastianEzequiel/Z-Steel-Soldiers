// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "flamethrower.h"
#include "../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// FLAMETHROWER CONSTRUCTOR
//------------------------------------------------------------------------------
Flamethrower::Flamethrower(
        const Node& position, size_t id, const Unit& shooter):
        Armament::Armament(position, id, shooter) {
    damage = settings.flamethrower["damage"];
}
//------------------------------------------------------------------------------
// FLAMETHROWER DESTRUCTOR
//------------------------------------------------------------------------------
Flamethrower::~Flamethrower() {}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool Flamethrower::isLaser()const {
    return false;
}
//------------------------------------------------------------------------------
// IS FLAMETHROWER
//------------------------------------------------------------------------------
bool Flamethrower::isFlamethrower() const {
    return true;
}
//------------------------------------------------------------------------------
// IS HIGH CALIBER PROJECTILES
//------------------------------------------------------------------------------
bool Flamethrower::isHighCaliberProjectiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS MISSILES
//------------------------------------------------------------------------------
bool Flamethrower::isMissiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BULLETS
//------------------------------------------------------------------------------
bool Flamethrower::isBullets() const {
    return false;
}
//------------------------------------------------------------------------------