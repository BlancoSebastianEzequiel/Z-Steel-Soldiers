#include "fortBehavior.h"
#include "../object.h"
#include "../../terrains/node.h"
#include "../../maps/map.h"

FortBehavior::FortBehavior(const object_t &settings, size_t type):
    BuildingBehavior(settings, type) {
}

Node *FortBehavior::getFlagNode(const positions_t &positions) const {
    for (Node* node: positions) {
        for (Node* anAdjacent: node->getAdjacent()) {
            if (anAdjacent->hasAGroundObject()) continue;
            if (!anAdjacent->vehiclePassThrough()) continue;
            if (!anAdjacent->robotPassThrough()) continue;
            return anAdjacent;
        }
    }
    throw Exception("The walkable node of the ground object returned null\n");
}

void FortBehavior::showFlag() {
    flag->addObjectToNodes();
}

void FortBehavior::receivedDamage(const Armament &aMunition, Object &anObject) {
    ObjectBehavior::receivedDamage(aMunition, anObject);
    if (isBroken()) {
        showFlag();
    }
}

void FortBehavior::addAttributes(object_t attr, Map &aMap, Object &anObject) {
    BuildingBehavior::addAttributes(attr, aMap, anObject);
    aMap.maximumQuantityOfPlayers++;
    Node* flagPos = getFlagNode(anObject.getPositions());
    size_t idFlag = aMap.getNewObjectId();
    flag = new Object(*flagPos, idFlag, FLAG_TYPE);
    aMap.addObject(flag);
}

bool FortBehavior::isFort() {
    return true;
}
