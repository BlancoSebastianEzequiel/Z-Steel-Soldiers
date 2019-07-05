// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include "fort.h"
#include "../flags/flag.h"
#include "../../terrains/node.h"
//------------------------------------------------------------------------------
// FORT CONSTRUCTOR
//------------------------------------------------------------------------------
Fort::Fort(
        Node &position, size_t id, size_t tecnologyLevel):
        Buildings::Buildings(position, id, tecnologyLevel) {
}
//------------------------------------------------------------------------------
// FORT DESTRUCTOR
//------------------------------------------------------------------------------
Fort::~Fort() {}
//------------------------------------------------------------------------------
// GET FLAG NODE
//------------------------------------------------------------------------------
Node* Fort::getFlagNode() const {
    for (Node* node : positions) {
        for (Node* anAdjacent : node->getAdjacent()) {
            if (anAdjacent->hasAGroundObject()) continue;
            if (!anAdjacent->vehiclePassThrough()) continue;
            if (!anAdjacent->robotPassThrough()) continue;
            return anAdjacent;
        }
    }
    throw Exception("The walkable node of the ground object returned null\n");
}
//------------------------------------------------------------------------------
// ADD FLAG
//------------------------------------------------------------------------------
void Fort::addFlag(Flag &flag) {
    this->flag = &flag;
}
//------------------------------------------------------------------------------
// SHOW FLAG
//------------------------------------------------------------------------------
void Fort::showFlag() {
    flag->addOnPositions();
}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool Fort::isFort() const {
    return true;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool Fort::isVehicleFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool Fort::isRobotFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
