// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverWoodenBridge.h"
//------------------------------------------------------------------------------
// WOODEN BRIDGE CONSTRUCTOR
//------------------------------------------------------------------------------
ServerWoodenBridge::ServerWoodenBridge(ServerNode &position, size_t id):
        ServerBridges::ServerBridges(position, id) {}
//------------------------------------------------------------------------------
// WOODEN BRIDGE DESTRUCTOR
//------------------------------------------------------------------------------
ServerWoodenBridge::~ServerWoodenBridge() {}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool ServerWoodenBridge::isWoodenBridge() const {
    return true;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool ServerWoodenBridge::isConcreteBridge() const {
    return false;
}
//------------------------------------------------------------------------------
