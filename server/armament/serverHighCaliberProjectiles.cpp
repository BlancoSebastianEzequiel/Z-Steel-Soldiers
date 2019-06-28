// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverHighCaliberProjectiles.h"
#include "../settings/serverSettings.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// HIGH CALIBER PROJECTILES CONSTRUCTOR
//------------------------------------------------------------------------------
ServerHighCaliberProjectiles::ServerHighCaliberProjectiles(
        const ServerNode& position, size_t id, const ServerUnit& shooter):
        ServerArmament::ServerArmament(position, id, shooter) {
    damage = settings.highCaliberProjectiles["damage"];
}
//------------------------------------------------------------------------------
// HIGH CALIBER PROJECTILES DESTRUCTOR
//------------------------------------------------------------------------------
ServerHighCaliberProjectiles::~ServerHighCaliberProjectiles() {}
//------------------------------------------------------------------------------
// IS LASER
//------------------------------------------------------------------------------
bool ServerHighCaliberProjectiles::isLaser()const {
    return false;
}
//------------------------------------------------------------------------------
// IS FLAMETHROWER
//------------------------------------------------------------------------------
bool ServerHighCaliberProjectiles::isFlamethrower() const {
    return false;
}
//------------------------------------------------------------------------------
// IS HIGH CALIBER PROJECTILES
//------------------------------------------------------------------------------
bool ServerHighCaliberProjectiles::isHighCaliberProjectiles() const {
    return true;
}
//------------------------------------------------------------------------------
// IS MISSILES
//------------------------------------------------------------------------------
bool ServerHighCaliberProjectiles::isMissiles() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BULLETS
//------------------------------------------------------------------------------
bool ServerHighCaliberProjectiles::isBullets() const {
    return false;
}
//------------------------------------------------------------------------------
