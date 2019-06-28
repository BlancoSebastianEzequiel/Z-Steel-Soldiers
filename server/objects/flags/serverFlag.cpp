// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverFlag.h"
#include "../../terrains/serverNode.h"
//------------------------------------------------------------------------------
// FLAG CONSTRUCTOR
//------------------------------------------------------------------------------
ServerFlag::ServerFlag(ServerNode &position, size_t id):
        ServerObject::ServerObject(position, id) {}
//------------------------------------------------------------------------------
// FLAG DESTRUCTOR
//------------------------------------------------------------------------------
ServerFlag::~ServerFlag() {}
//------------------------------------------------------------------------------
// ADD OBJECT TO NODES
//------------------------------------------------------------------------------
void ServerFlag::addObjectToNodes(ServerMap& aMap) {
    principalPosition.addGroundObject(this);
    positions.push_back(&principalPosition);
    wasAdded = true;
}
//------------------------------------------------------------------------------
// CAN PASS THROUGH
//------------------------------------------------------------------------------
bool ServerFlag::canPassThrough() const {
    return true;
}
//------------------------------------------------------------------------------
// ADD ON POSITIONS
//------------------------------------------------------------------------------
void ServerFlag::addOnPositions() {
    principalPosition.addGroundObject(this);
    positions.push_back(&principalPosition);
    wasAdded = true;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool ServerFlag::isBuilding() const {
    return false;
}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool ServerFlag::isFort() const {
    return false;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool ServerFlag::isVehicleFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool ServerFlag::isRobotFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
// IS FLAG
//------------------------------------------------------------------------------
bool ServerFlag::isFlag() const {
    return true;
}
//------------------------------------------------------------------------------
// IS STONE
//------------------------------------------------------------------------------
bool ServerFlag::isStone() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ICE BLOCK
//------------------------------------------------------------------------------
bool ServerFlag::isIceBlock() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BRIDGE
//------------------------------------------------------------------------------
bool ServerFlag::isBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool ServerFlag::isWoodenBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool ServerFlag::isConcreteBridge() const {
    return false;
}
//------------------------------------------------------------------------------
