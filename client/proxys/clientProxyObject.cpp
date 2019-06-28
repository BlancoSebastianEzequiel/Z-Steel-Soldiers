// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <iostream>
#include <utility>
#include "clientProxyObject.h"
#include "clientProxyNode.h"
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
ClientProxyObject::ClientProxyObject(
        ClientProxyNode& position, size_t id, std::string type):
        principalPosition(position), id(id), type(type) {
    updated = false;
}
//------------------------------------------------------------------------------
// OBJECT DESTRUCTOR
//------------------------------------------------------------------------------
ClientProxyObject::~ClientProxyObject() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ClientProxyObject::operator==(const ClientProxyObject& otherObject) {
    return id == otherObject.getId();
}
//------------------------------------------------------------------------------
// SET TECNOLOGY LEVEL
//------------------------------------------------------------------------------
void ClientProxyObject::setTecnologyLevel(size_t tecnologyLevel) {
    this->tecnologyLevel = tecnologyLevel;
}
//------------------------------------------------------------------------------
// GET TECNOLOGY LEVEL
//------------------------------------------------------------------------------
const size_t& ClientProxyObject::getTecnologyLevel() const {
    return tecnologyLevel;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool ClientProxyObject::isBroken() const {
    return currentState == BROKEN;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void ClientProxyObject::changeState(std::string newState) {
    currentState = newState;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ClientProxyObject::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// HAS AN OWNER
//------------------------------------------------------------------------------
bool ClientProxyObject::hasAnOwner() const {
    return ownerId != 0;
}
//------------------------------------------------------------------------------
// SET OWNER ID
//------------------------------------------------------------------------------
void ClientProxyObject::setOwnerId(ssize_t ownerId) {
    this->ownerId = ownerId;
}
//------------------------------------------------------------------------------
// GET OWNER ID
//------------------------------------------------------------------------------
const ssize_t ClientProxyObject::getOwnerId() const {
    return ownerId;
}
//------------------------------------------------------------------------------
// GET PRINCIPAL POSITION
//------------------------------------------------------------------------------
const ClientProxyNode& ClientProxyObject::getPrincipalPosition() const {
    return principalPosition;
}
//------------------------------------------------------------------------------
//  HAS BEEN UPDATED
//------------------------------------------------------------------------------
bool ClientProxyObject::hasBeenUpdated() {
    bool aux = updated;
    updated = false;
    return aux;
}
//------------------------------------------------------------------------------
//  SET IS UPDATED
//------------------------------------------------------------------------------
void ClientProxyObject::setIsUpdated(bool updated) {
    this->updated = updated;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool ClientProxyObject::isBuilding() const {
    return type == FORT || type == VEHICLE_FACTORIE || type == ROBOT_FACTORIE;
}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool ClientProxyObject::isFort() const {
    return type == FORT;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool ClientProxyObject::isVehicleFactorie() const {
    return type == VEHICLE_FACTORIE;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool ClientProxyObject::isRobotFactorie() const {
    return type == ROBOT_FACTORIE;
}
//------------------------------------------------------------------------------
// IS FLAG
//------------------------------------------------------------------------------
bool ClientProxyObject::isFlag() const {
    return type == FLAG;
}
//------------------------------------------------------------------------------
// IS STONE
//------------------------------------------------------------------------------
bool ClientProxyObject::isStone() const {
    return type == STONE;
}
//------------------------------------------------------------------------------
// IS ICE BLOCK
//------------------------------------------------------------------------------
bool ClientProxyObject::isIceBlock() const {
    return type == ICE_BLOCK;
}
//------------------------------------------------------------------------------
// IS BRIDGE
//------------------------------------------------------------------------------
bool ClientProxyObject::isBridge() const {
    return type == WOODEN_BRIDGE || type == CONCRETE_BRIDGE;
}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool ClientProxyObject::isWoodenBridge() const {
    return type == WOODEN_BRIDGE;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool ClientProxyObject::isConcreteBridge() const {
    return type == CONCRETE_BRIDGE;
}
//------------------------------------------------------------------------------
