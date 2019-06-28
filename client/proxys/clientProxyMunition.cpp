// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "clientProxyMunition.h"
//------------------------------------------------------------------------------
#define MOVING "moving"
#define OBSOLETE "obsolete"
#define OBJECT "object"
#define UNIT "unit"
//------------------------------------------------------------------------------
// CLIENT PROXY MUNITION CONSTRUCTOR
//------------------------------------------------------------------------------
ClientProxyMunition::ClientProxyMunition(
        size_t id, const size_t idShooter, const size_t idTarget):
        id(id), idShooter(idShooter), idTarget(idTarget) {
    updated = false;
}
//------------------------------------------------------------------------------
// CLIENT PROXY MUNITION DESTRUCTOR
//------------------------------------------------------------------------------
ClientProxyMunition::~ClientProxyMunition() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ClientProxyMunition::operator==(const ClientProxyMunition& otherMunition) {
    return id == otherMunition.getId();
}
//------------------------------------------------------------------------------
// SET MOVING DEST
//------------------------------------------------------------------------------
void ClientProxyMunition::setMovingDest(const ClientProxyNode& dest) {
    movingToDest = &dest;
}
//------------------------------------------------------------------------------
// MOVING TO
//------------------------------------------------------------------------------
const ClientProxyNode* ClientProxyMunition::movingTo() const {
    return movingToDest;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void ClientProxyMunition::changeState(std::string newState) {
    currentState = newState;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ClientProxyMunition::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// GET ID SHOOTER
//------------------------------------------------------------------------------
const size_t& ClientProxyMunition::getIdShooter() const {
    return idShooter;
}
//------------------------------------------------------------------------------
// GET ID TARGET
//------------------------------------------------------------------------------
const size_t& ClientProxyMunition::getIdTarget() {
    return idTarget;
}
//------------------------------------------------------------------------------
// IS TARGET AN OBJECT
//------------------------------------------------------------------------------
bool ClientProxyMunition::isTargetAnObject() const {
    return targetType == OBJECT;
}
//------------------------------------------------------------------------------
// SET TARGET TYPE
//------------------------------------------------------------------------------
void ClientProxyMunition::setTargetType(std::string type) {
    targetType = type;
}
//------------------------------------------------------------------------------
//  HAS BEEN UPDATED
//------------------------------------------------------------------------------
bool ClientProxyMunition::hasBeenUpdated() {
    bool aux = updated;
    updated = false;
    return aux;
}
//------------------------------------------------------------------------------
//  SET IS UPDATED
//------------------------------------------------------------------------------
void ClientProxyMunition::setIsUpdated(bool updated) {
    this->updated = updated;
}
//------------------------------------------------------------------------------
// SET SPEED
//------------------------------------------------------------------------------
void ClientProxyMunition::setSpeed(float speed) {
    this->speed = speed;
}
//------------------------------------------------------------------------------
// GET SPEED
//------------------------------------------------------------------------------
double ClientProxyMunition::getSpeed() {
    return speed;
}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool ClientProxyMunition::isMoving() const {
    return currentState == MOVING;
}
//------------------------------------------------------------------------------
// IS OBSOLETE
//------------------------------------------------------------------------------
bool ClientProxyMunition::isObsolete() const {
    return currentState == OBSOLETE;
}
//------------------------------------------------------------------------------