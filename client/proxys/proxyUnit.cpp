// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include <utility>
#include "proxyUnit.h"
#include "proxyNode.h"
//------------------------------------------------------------------------------
#define GRUNT "grunt"
#define TOUGH "tough"
#define SNIPER "sniper"
#define PSYCHO "psycho"
#define PYRO "pyro"
#define LASER "laser"
#define HEAVY_TANK "heavyTank"
#define MEDIUM_TANK "MediumTank"
#define LIGHT_TANK "LightTank"
#define MML "MML"
#define JEEP "jeep"

#define MOVING "moving"
#define STILL "still"
#define DEAD "dead"
//------------------------------------------------------------------------------
// SERVER UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
ProxyUnit::ProxyUnit(
        const ProxyNode& position, size_t id, std::string type):
        id(id), type(type) {
    this->position = &position;
    updated = false;
}
//------------------------------------------------------------------------------
// SERVER UNIT DESTRUCTOR
//------------------------------------------------------------------------------
ProxyUnit::~ProxyUnit() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ProxyUnit::operator==(const ProxyUnit& otherUnit) {
    return id == otherUnit.getId();
}
//------------------------------------------------------------------------------
// SET DAMAGE REL
//------------------------------------------------------------------------------
void ProxyUnit::setDamageRel(float damageRel) {
    this->damageRel = damageRel;
}
//------------------------------------------------------------------------------
// SET BASE SPEED
//------------------------------------------------------------------------------
void ProxyUnit::setBaseSpeed(float baseSpeed) {
    this->baseSpeed = baseSpeed;
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double ProxyUnit::getSpeed(const ProxyNode& aNode) const {
    float finalVelocity;
    if (isRobot()) {
        finalVelocity = 4 * aNode.getGroundFactor();
        if (finalVelocity > 1) {
            return finalVelocity;
        }
        return 1;
    }
    finalVelocity = baseSpeed * aNode.getGroundFactor() * ( 1 - damageRel);
    if (finalVelocity > 1) {
        return finalVelocity;
    }
    return 1;
}
//------------------------------------------------------------------------------
// GET POSITION
//------------------------------------------------------------------------------
const ProxyNode* ProxyUnit::getPosition() const {
    return position;
}
//------------------------------------------------------------------------------
//  HAS BEEN UPDATED
//------------------------------------------------------------------------------
bool ProxyUnit::hasBeenUpdated() {
    bool aux = updated;
    updated = false;
    return aux;
}
//------------------------------------------------------------------------------
//  SET IS UPDATED
//------------------------------------------------------------------------------
void ProxyUnit::setIsUpdated(bool updated) {
    this->updated = updated;
}
//------------------------------------------------------------------------------
// SER OWNER ID
//------------------------------------------------------------------------------
void ProxyUnit::setOwnerId(size_t ownerId) {
    this->ownerId = ownerId;
}
//------------------------------------------------------------------------------
// GET OWNER ID
//------------------------------------------------------------------------------
size_t ProxyUnit::getOwnerId() {
    return ownerId;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ProxyUnit::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void ProxyUnit::changeState(std::string newState) {
    lastState = currentState;
    currentState = newState;
}
//------------------------------------------------------------------------------
// LAST STATE IS STILL
//------------------------------------------------------------------------------
bool ProxyUnit::lastStateIsStill() {
    if (lastState == STILL) {
        lastState = currentState;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
// POSITION HAS CHANGED
//------------------------------------------------------------------------------
bool ProxyUnit::positionHasChanged() {
    if (positionChanged) {
        bool answer = positionChanged;
        positionChanged = false;
        return answer;
    }
    return positionChanged;
}
//------------------------------------------------------------------------------
// CHANGE POSITION
//------------------------------------------------------------------------------
void ProxyUnit::changePosition(const ProxyNode& newPosition) {
    positionChanged = *position != newPosition;
    position = &newPosition;
}
//------------------------------------------------------------------------------
// SET MOVING DEST
//------------------------------------------------------------------------------
void ProxyUnit::setMovingDest(const ProxyNode& dest) {
    movingToDest = &dest;
}
//------------------------------------------------------------------------------
// MOVING TO
//------------------------------------------------------------------------------
const ProxyNode* ProxyUnit::movingTo() const {
    return movingToDest;
}
//------------------------------------------------------------------------------
// IS DEAD
//------------------------------------------------------------------------------
bool ProxyUnit::isDead() const {
    return currentState == DEAD;
}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool ProxyUnit::isMoving() const {
    return currentState == MOVING;
}
//------------------------------------------------------------------------------
// IS STILL
//------------------------------------------------------------------------------
bool ProxyUnit::isStill() const {
    return currentState == STILL;
}
//------------------------------------------------------------------------------
// IS ROBOT
//------------------------------------------------------------------------------
bool ProxyUnit::isRobot() const {
    return isGrunt() || isTough() || isSniper() || isPsycho() || isPyro() ||
            isLaser();
}
//------------------------------------------------------------------------------
// IS VEHICLE
//------------------------------------------------------------------------------
bool ProxyUnit::isVehicle() const {
    return isMML() || isJeep() || isLightTank() || isMediumTank() ||
            isHeavyTank();
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isGrunt() const {
    return type == GRUNT;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isTough() const {
    return type == TOUGH;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isSniper() const {
    return type == SNIPER;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isPsycho() const {
    return type == PSYCHO;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isPyro() const {
    return type == PYRO;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isLaser() const {
    return type == LASER;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isJeep() const {
    return type == JEEP;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isMML() const {
    return type == MML;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isLightTank() const {
    return type == LIGHT_TANK;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isMediumTank() const {
    return type == MEDIUM_TANK;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ProxyUnit::isHeavyTank() const {
    return type == HEAVY_TANK;
}
//------------------------------------------------------------------------------
