// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "highCaliberProjectiles.h"
#include "../settings/settings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// HIGH CALIBER PROJECTILES CONSTRUCTOR
//------------------------------------------------------------------------------
HighCaliberProjectiles::HighCaliberProjectiles(
        const Node& position, size_t id, const Unit& shooter):
        Armament::Armament(position, id, shooter) {
    damage = settings.highCaliberProjectiles["damage"];
}
//------------------------------------------------------------------------------
// HIGH CALIBER PROJECTILES DESTRUCTOR
//------------------------------------------------------------------------------
HighCaliberProjectiles::~HighCaliberProjectiles() {}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool HighCaliberProjectiles::isLaser()const {
    return false;
}
//------------------------------------------------------------------------------
// IS FLAMETHROWER
//------------------------------------------------------------------------------
bool HighCaliberProjectiles::isFlamethrower() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HIGH CALIBER PROJECTILES
//------------------------------------------------------------------------------
bool HighCaliberProjectiles::isHighCaliberProjectiles() const {
    return true;
}
//------------------------------------------------------------------------------
// IS MISSILES
//------------------------------------------------------------------------------
bool HighCaliberProjectiles::isMissiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BULLETS
//------------------------------------------------------------------------------
bool HighCaliberProjectiles::isBullets() const {
    return false;
}
//------------------------------------------------------------------------------
