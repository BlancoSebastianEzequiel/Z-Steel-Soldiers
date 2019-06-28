// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverConcreteBridge.h"
//------------------------------------------------------------------------------
// CONCRETE BRIDGE CONSTRUCTOR
//------------------------------------------------------------------------------
ServerConcreteBridge::ServerConcreteBridge(
        ServerNode &position, size_t id):
        ServerBridges::ServerBridges(position, id) {}
//------------------------------------------------------------------------------
// CONCRETE BRIDGE DESTRUCTOR
//------------------------------------------------------------------------------
ServerConcreteBridge::~ServerConcreteBridge() {}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool ServerConcreteBridge::isWoodenBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool ServerConcreteBridge::isConcreteBridge() const {
    return true;
}
//------------------------------------------------------------------------------
