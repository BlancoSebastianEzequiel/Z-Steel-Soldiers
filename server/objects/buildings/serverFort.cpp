// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <string>
#include "serverFort.h"
#include "../flags/serverFlag.h"
#include "../../terrains/serverNode.h"
//------------------------------------------------------------------------------
// FORT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerFort::ServerFort(
        ServerNode &position, size_t id, size_t tecnologyLevel):
        ServerBuildings::ServerBuildings(position, id, tecnologyLevel) {
}
//------------------------------------------------------------------------------
// FORT DESTRUCTOR
//------------------------------------------------------------------------------
ServerFort::~ServerFort() {}
//------------------------------------------------------------------------------
// GET FLAG NODE
//------------------------------------------------------------------------------
ServerNode* ServerFort::getFlagNode() const {
    for (ServerNode* node : positions) {
        for (ServerNode* anAdjacent : node->getAdjacent()) {
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
void ServerFort::addFlag(ServerFlag &flag) {
    this->flag = &flag;
}
//------------------------------------------------------------------------------
// SHOW FLAG
//------------------------------------------------------------------------------
void ServerFort::showFlag() {
    flag->addOnPositions();
}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool ServerFort::isFort() const {
    return true;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool ServerFort::isVehicleFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool ServerFort::isRobotFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
