// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverBridges.h"
#include "../../settings/serverSettings.h"
#include "../../terrains/serverNode.h"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// CONCRETE AND WOODEN BRIDGES CONSTRUCTOR
//------------------------------------------------------------------------------
ServerBridges::ServerBridges(ServerNode &position, size_t id):
        ServerObject::ServerObject(position, id) {
    structurePoints = settings.ConcreteAndWoodenBridges["structurePoints"];
}
//------------------------------------------------------------------------------
// CONCRETE AND WOODEN BRIDGES DESTRUCTOR
//------------------------------------------------------------------------------
ServerBridges::~ServerBridges() {}
//------------------------------------------------------------------------------
// ADD OBJECT TO NODES
//------------------------------------------------------------------------------
void ServerBridges::addObjectToNodes(ServerMap& aMap) {
    principalPosition.addGroundObject(this);
    positions.push_back(&principalPosition);
    wasAdded = true;
}
//------------------------------------------------------------------------------
// CAN PASS THROUGH
//------------------------------------------------------------------------------
bool ServerBridges::canPassThrough() const {
    return !isBroken();
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool ServerBridges::isBuilding() const {
    return false;
}
//------------------------------------------------------------------------------
// IS FORT
//------------------------------------------------------------------------------
bool ServerBridges::isFort() const {
    return false;
}
//------------------------------------------------------------------------------
// IS VEHICLE FACTORIE
//------------------------------------------------------------------------------
bool ServerBridges::isVehicleFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ROBOT FACTORIE
//------------------------------------------------------------------------------
bool ServerBridges::isRobotFactorie() const {
    return false;
}
//------------------------------------------------------------------------------
// IS FLAG
//------------------------------------------------------------------------------
bool ServerBridges::isFlag() const {
    return false;
}
//------------------------------------------------------------------------------
// IS STONE
//------------------------------------------------------------------------------
bool ServerBridges::isStone() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ICE BLOCK
//------------------------------------------------------------------------------
bool ServerBridges::isIceBlock() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BRIDGE
//------------------------------------------------------------------------------
bool ServerBridges::isBridge() const {
    return true;
}
//------------------------------------------------------------------------------
