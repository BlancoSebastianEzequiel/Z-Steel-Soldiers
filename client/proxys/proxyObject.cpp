// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <iostream>
#include <utility>
#include "proxyObject.h"
#include "proxyNode.h"
//------------------------------------------------------------------------------
#define FORT "fort"
#define VEHICLE_FACTORIE "vFactory"
#define ROBOT_FACTORIE "rFactory"
#define STONE "rock"
#define ICE_BLOCK "iceBlock"
#define WOODEN_BRIDGE "woodBridge"
#define CONCRETE_BRIDGE "concreteBridge"
#define FLAG "flag"
#define BROKEN "true"
//------------------------------------------------------------------------------
// OBJECT CONSTRUCTOR
//------------------------------------------------------------------------------
ProxyObject::ProxyObject(
        ProxyNode& position, size_t id, std::string type):
        principalPosition(position), id(id), type(type) {
    updated = false;
}
//------------------------------------------------------------------------------
// OBJECT DESTRUCTOR
//------------------------------------------------------------------------------
ProxyObject::~ProxyObject() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ProxyObject::operator==(const ProxyObject& otherObject) {
    return id == otherObject.getId();
}
//------------------------------------------------------------------------------
// SET TECNOLOGY LEVEL
//------------------------------------------------------------------------------
void ProxyObject::setTecnologyLevel(size_t tecnologyLevel) {
    this->tecnologyLevel = tecnologyLevel;
}
//------------------------------------------------------------------------------
// GET TECNOLOGY LEVEL
//------------------------------------------------------------------------------
const size_t& ProxyObject::getTecnologyLevel() const {
    return tecnologyLevel;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool ProxyObject::isBroken() const {
    return currentState == BROKEN;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void ProxyObject::changeState(std::string newState) {
    currentState = newState;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ProxyObject::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// HAS AN OWNER
//------------------------------------------------------------------------------
bool ProxyObject::hasAnOwner() const {
    return ownerId != 0;
}
//------------------------------------------------------------------------------
// SET OWNER ID
//------------------------------------------------------------------------------
void ProxyObject::setOwnerId(ssize_t ownerId) {
    this->ownerId = ownerId;
}
//------------------------------------------------------------------------------
// GET OWNER ID
//------------------------------------------------------------------------------
const ssize_t ProxyObject::getOwnerId() const {
    return ownerId;
}
//------------------------------------------------------------------------------
// GET PRINCIPAL POSITION
//------------------------------------------------------------------------------
const ProxyNode& ProxyObject::getPrincipalPosition() const {
    return principalPosition;
}
//------------------------------------------------------------------------------
//  HAS BEEN UPDATED
//------------------------------------------------------------------------------
bool ProxyObject::hasBeenUpdated() {
    bool aux = updated;
    updated = false;
    return aux;
}
//------------------------------------------------------------------------------
//  SET IS UPDATED
//------------------------------------------------------------------------------
void ProxyObject::setIsUpdated(bool updated) {
    this->updated = updated;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool ProxyObject::isBuilding() const {
    return type == FORT || type == VEHICLE_FACTORIE || type == ROBOT_FACTORIE;
}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool ProxyObject::isFort() const {
    return type == FORT;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool ProxyObject::isVehicleFactorie() const {
    return type == VEHICLE_FACTORIE;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool ProxyObject::isRobotFactorie() const {
    return type == ROBOT_FACTORIE;
}
//------------------------------------------------------------------------------
// IS FLAG
//------------------------------------------------------------------------------
bool ProxyObject::isFlag() const {
    return type == FLAG;
}
//------------------------------------------------------------------------------
// IS STONE
//------------------------------------------------------------------------------
bool ProxyObject::isStone() const {
    return type == STONE;
}
//------------------------------------------------------------------------------
// IS ICE BLOCK
//------------------------------------------------------------------------------
bool ProxyObject::isIceBlock() const {
    return type == ICE_BLOCK;
}
//------------------------------------------------------------------------------
// IS BRIDGE
//------------------------------------------------------------------------------
bool ProxyObject::isBridge() const {
    return type == WOODEN_BRIDGE || type == CONCRETE_BRIDGE;
}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool ProxyObject::isWoodenBridge() const {
    return type == WOODEN_BRIDGE;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool ProxyObject::isConcreteBridge() const {
    return type == CONCRETE_BRIDGE;
}
//------------------------------------------------------------------------------
