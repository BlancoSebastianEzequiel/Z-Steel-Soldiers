// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <iostream>
#include <utility>
#include "../armament/armament.h"
#include "object.h"
#include "../states/stateBroken.h"
#include "../states/stateStill.h"
#include "../terrains/node.h"
#include "buildings/fort.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// OBJECT CONSTRUCTOR
//------------------------------------------------------------------------------
Object::Object(Node& position, size_t id):
        principalPosition(position), id(id) {
    damageReceived = 0;
    currentState = new StateStill;
    wasAdded = false;
}
//------------------------------------------------------------------------------
// OBJECT DESTRUCTOR
//------------------------------------------------------------------------------
Object::~Object() {
    delete currentState;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool Object::isBroken() const {
    return damageReceived >= structurePoints;
}
//------------------------------------------------------------------------------
// RECEIVED DAMAGE
//------------------------------------------------------------------------------
void Object::receivedDamage(const Armament& anArmament) {
    if (isBroken()) return;
    damageReceived += anArmament.getDamage();
    if (isBroken()) {
        changeState(*new StateBroken());
    }
}
//------------------------------------------------------------------------------
// GET CURRENT STATE
//------------------------------------------------------------------------------
const State* Object::getCurrentState() const {
     return currentState;
}
//------------------------------------------------------------------------------
// CHANGE STATE
//------------------------------------------------------------------------------
void Object::changeState(const State& newState) {
    delete currentState;
    currentState = &newState;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& Object::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// GET WALKABLE NODE
//------------------------------------------------------------------------------
Node* Object::getWalkableNode() {
    for (Node* node : positions) {
        for (Node* anAdjacent : node->getAdjacent()) {
            if (anAdjacent->hasAGroundObject()) {
                if (!anAdjacent->getGroundObject()->canPassThrough()) {
                    continue;
                }
            }
            if (!anAdjacent->vehiclePassThrough()) continue;
            if (!anAdjacent->robotPassThrough()) continue;
            return anAdjacent;
        }
    }
    throw Exception("The walkable node of the ground object returned null\n");
}
//------------------------------------------------------------------------------
// HAS AN OWNER
//------------------------------------------------------------------------------
bool Object::hasAnOwner() const {
    return getOwner() != nullptr;
}
//------------------------------------------------------------------------------
// GET OWNER
//------------------------------------------------------------------------------
const Player* Object::getOwner() const {
    return principalPosition.getOwner();
}
//------------------------------------------------------------------------------
// GET PRINCIPAL POSITION
//------------------------------------------------------------------------------
const Node& Object::getPrincipalPosition() const {
    return principalPosition;
}
//------------------------------------------------------------------------------
// WAS ADDED ON NODE
//------------------------------------------------------------------------------
bool Object::wasAddedOnNode() const {
    return wasAdded;
}
//------------------------------------------------------------------------------
