#include "objectBehavior.h"
#include "../../terrains/node.h"
#include "../../armament/armament.h"
#include "buildingBehavior.h"
#include "fortBehavior.h"
#include "flagBehavior.h"
#include "../../states/stateBroken.h"

ObjectBehavior::ObjectBehavior(const object_t &settings, size_t type):
    objectSettings(settings), type(type) {
    wasAdded = false;
    damageReceived = 0;
}

ObjectBehavior::~ObjectBehavior() {}

void ObjectBehavior::addObjectToNodes(
        Node &mainPos, Object &anObject, positions_t &positions) {
    mainPos.addGroundObject(&anObject);
    positions.push_back(&mainPos);
    wasAdded = true;
}

bool ObjectBehavior::canPassThrough() {
    return !isBroken();
}

float ObjectBehavior::getDamageStructureRel() const {
    return damageReceived / objectSettings["structurePoints"];
}

bool ObjectBehavior::isBroken() const {
    return damageReceived >= objectSettings["structurePoints"];
}

bool ObjectBehavior::wasAddedOnNode() const {
    return wasAdded;
}

size_t ObjectBehavior::getType() {
    return type;
}

void ObjectBehavior::receivedDamage(const Armament &aMunition, Object& anObject) {
    if (isBroken()) return;
    damageReceived += aMunition.getDamage();
    if (isBroken()) {
        anObject.changeState(*new StateBroken());
    }
}

void ObjectBehavior::addAttributes(object_t attr, Map &aMap, Object &anObject) {}

object_t ObjectBehavior::getAttributes() {
    return object_t();
}

double ObjectBehavior::manufacturingTime(size_t takenTerritories, size_t type) {
    throw Exception("this object does not manufacture units");
}

bool ObjectBehavior::isBuilding() {
    return false;
}

bool ObjectBehavior::isFlag() {
    return false;
}

bool ObjectBehavior::isFort() {
    return false;
}

ObjectBehavior* ObjectBehavior::getInstance(
        const object_t &settings, size_t type) {
    size_t behavior = (size_t) settings["behavior"];
    if (behavior == FORT_BEHAVIOR) {
        return new FortBehavior(settings, type);
    } else if (behavior == BUILDING_BEHAVIOR) {
        return new BuildingBehavior(settings, type);
    } else if (behavior == SOLIDS_BEHAVIOR) {
        return new ObjectBehavior(settings, type);
    } else if (behavior == BRIDGES_BEHAVIOR) {
        return new ObjectBehavior(settings, type);
    } else if (behavior == FLAG_BEHAVIOR) {
        return new FlagBehavior(settings, type);
    } else {
        throw Exception("wrong type behavior");
    }
}
