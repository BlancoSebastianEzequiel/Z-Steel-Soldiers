// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "concreteBridge.h"
//------------------------------------------------------------------------------
// CONCRETE BRIDGE CONSTRUCTOR
//------------------------------------------------------------------------------
ConcreteBridge::ConcreteBridge(
        Node &position, size_t id):
        Bridges::Bridges(position, id) {}
//------------------------------------------------------------------------------
// CONCRETE BRIDGE DESTRUCTOR
//------------------------------------------------------------------------------
ConcreteBridge::~ConcreteBridge() {}
//------------------------------------------------------------------------------
// IS WOODEN BRIDGE
//------------------------------------------------------------------------------
bool ConcreteBridge::isWoodenBridge() const {
    return false;
}
//------------------------------------------------------------------------------
// IS CONCRETE BRIDGE
//------------------------------------------------------------------------------
bool ConcreteBridge::isConcreteBridge() const {
    return true;
}
//------------------------------------------------------------------------------