// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include <utility>
#include "clientProxyUnit.h"
#include "clientProxyNode.h"
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
ClientProxyUnit::ClientProxyUnit(
        const ClientProxyNode& position, size_t id, std::string type):
        id(id), type(type) {
    this->position = &position;
    updated = false;
}
//------------------------------------------------------------------------------
// SERVER UNIT DESTRUCTOR
//------------------------------------------------------------------------------
ClientProxyUnit::~ClientProxyUnit() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ClientProxyUnit::operator==(const ClientProxyUnit& otherUnit) {
    return id == otherUnit.getId();
}
//------------------------------------------------------------------------------
// SET DAMAGE REL
//------------------------------------------------------------------------------
void ClientProxyUnit::setDamageRel(float damageRel) {
    this->damageRel = damageRel;
}
//------------------------------------------------------------------------------
// SET BASE SPEED
//------------------------------------------------------------------------------
void ClientProxyUnit::setBaseSpeed(float baseSpeed) {
    this->baseSpeed = baseSpeed;
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double ClientProxyUnit::getSpeed(const ClientProxyNode& aNode) const {
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
const ClientProxyNode* ClientProxyUnit::getPosition() const {
    return position;
}
//------------------------------------------------------------------------------
//  HAS BEEN UPDATED
//------------------------------------------------------------------------------
bool ClientProxyUnit::hasBeenUpdated() {
    bool aux = updated;
    updated = false;
    return aux;
}
//------------------------------------------------------------------------------
//  SET IS UPDATED
//------------------------------------------------------------------------------
void ClientProxyUnit::setIsUpdated(bool updated) {
    this->updated = updated;
}
//------------------------------------------------------------------------------
// SER OWNER ID
//------------------------------------------------------------------------------
void ClientProxyUnit::setOwnerId(size_t ownerId) {
    this->ownerId = ownerId;
}
//------------------------------------------------------------------------------
// GET OWNER ID
//------------------------------------------------------------------------------
size_t ClientProxyUnit::getOwnerId() {
    return ownerId;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ClientProxyUnit::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void ClientProxyUnit::changeState(std::string newState) {
    lastState = currentState;
    currentState = newState;
}
//------------------------------------------------------------------------------
// LAST STATE IS STILL
//------------------------------------------------------------------------------
bool ClientProxyUnit::lastStateIsStill() {
    if (lastState == STILL) {
        lastState = currentState;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
// POSITION HAS CHANGED
//------------------------------------------------------------------------------
bool ClientProxyUnit::positionHasChanged() {
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
void ClientProxyUnit::changePosition(const ClientProxyNode& newPosition) {
    positionChanged = *position != newPosition;
    position = &newPosition;
}
//------------------------------------------------------------------------------
// SET MOVING DEST
//------------------------------------------------------------------------------
void ClientProxyUnit::setMovingDest(const ClientProxyNode& dest) {
    movingToDest = &dest;
}
//------------------------------------------------------------------------------
// MOVING TO
//------------------------------------------------------------------------------
const ClientProxyNode* ClientProxyUnit::movingTo() const {
    return movingToDest;
}
//------------------------------------------------------------------------------
// IS DEAD
//------------------------------------------------------------------------------
bool ClientProxyUnit::isDead() const {
    return currentState == DEAD;
}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool ClientProxyUnit::isMoving() const {
    return currentState == MOVING;
}
//------------------------------------------------------------------------------
// IS STILL
//------------------------------------------------------------------------------
bool ClientProxyUnit::isStill() const {
    return currentState == STILL;
}
//------------------------------------------------------------------------------
// IS ROBOT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isRobot() const {
    return isGrunt() || isTough() || isSniper() || isPsycho() || isPyro() ||
            isLaser();
}
//------------------------------------------------------------------------------
// IS VEHICLE
//------------------------------------------------------------------------------
bool ClientProxyUnit::isVehicle() const {
    return isMML() || isJeep() || isLightTank() || isMediumTank() ||
            isHeavyTank();
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isGrunt() const {
    return type == GRUNT;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isTough() const {
    return type == TOUGH;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isSniper() const {
    return type == SNIPER;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isPsycho() const {
    return type == PSYCHO;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isPyro() const {
    return type == PYRO;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isLaser() const {
    return type == LASER;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isJeep() const {
    return type == JEEP;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isMML() const {
    return type == MML;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isLightTank() const {
    return type == LIGHT_TANK;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isMediumTank() const {
    return type == MEDIUM_TANK;
}
//------------------------------------------------------------------------------
// IS GRUNT
//------------------------------------------------------------------------------
bool ClientProxyUnit::isHeavyTank() const {
    return type == HEAVY_TANK;
}
//------------------------------------------------------------------------------
