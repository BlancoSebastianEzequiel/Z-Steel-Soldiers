#include <iostream>
#include <utility>
#include "object.h"
#include "../states/stateStill.h"
#include "../terrains/node.h"
#include "../settings/settings.h"
#include "behavior/objectBehavior.h"
#include "../../libs/definitions.h"

extern Settings settings;

Object::Object(Node &position, size_t id, size_t type):
        mainPos(position), id(id) {
    object_t* objectSettings = settings.objects[type];
    behavior = ObjectBehavior::getInstance(*objectSettings, type);
    currentState = new StateStill;
}

Object::~Object() {
    delete currentState;
    delete behavior;
}

bool Object::isBroken() const {
    return behavior->isBroken();
}

void Object::receivedDamage(const Armament &aMunition) {
    behavior->receivedDamage(aMunition, *this);
}

const State* Object::getCurrentState() const {
     return currentState;
}

void Object::changeState(const State& newState) {
    delete currentState;
    currentState = &newState;
}

const size_t& Object::getId() const {
    return id;
}

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

bool Object::hasAnOwner() const {
    return getOwner() != nullptr;
}

const Player* Object::getOwner() const {
    return mainPos.getOwner();
}

const Node& Object::getMainPos() const {
    return mainPos;
}

bool Object::wasAddedOnNode() const {
    return behavior->wasAddedOnNode();
}

size_t Object::getType() {
    return behavior->getType();
}

bool Object::canPassThrough() const {
    return behavior->canPassThrough();
}

void Object::addObjectToNodes() {
    behavior->addObjectToNodes(mainPos, *this, positions);
}

float Object::getDamageStructureRel() const {
    return behavior->getDamageStructureRel();
}

void Object::addAttributes(const object_t &attr, Map &aMap) {
    behavior->addAttributes(attr, aMap, *this);
}

object_t Object::getAttributes() {
    return behavior->getAttributes();
}

double Object::manufacturingTime(size_t takenTerritories, size_t type) {
    return behavior->manufacturingTime(takenTerritories, type);
}

bool Object::isBuilding() const {
    return behavior->isBuilding();
}

bool Object::isFlag() const {
    return behavior->isFlag();
}

bool Object::isFort() const {
    return behavior->isFort();
}

const positions_t &Object::getPositions() {
    return positions;
}
