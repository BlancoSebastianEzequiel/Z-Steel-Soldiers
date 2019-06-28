// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverStateAttackingUnit.h"
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerStateAttackingUnit::ServerStateAttackingUnit(size_t idReceiver):
        idReceiver(idReceiver) {}
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT DESTRUCTOR
//------------------------------------------------------------------------------
ServerStateAttackingUnit::~ServerStateAttackingUnit() {}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool ServerStateAttackingUnit::isMoving() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ATTACKING UNIT
//------------------------------------------------------------------------------
bool ServerStateAttackingUnit::isAttackingUnit() const {
    return true;
}
//------------------------------------------------------------------------------
// IS ATTACKING OBJECT
//------------------------------------------------------------------------------
bool ServerStateAttackingUnit::isAttackingObject() const {
    return false;
}
//------------------------------------------------------------------------------
// IS STILL
//------------------------------------------------------------------------------
bool ServerStateAttackingUnit::isStill() const {
    return false;
}
//------------------------------------------------------------------------------
// IS DEAD
//------------------------------------------------------------------------------
bool ServerStateAttackingUnit::isDead() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool ServerStateAttackingUnit::isBroken() const {
    return false;
}
//------------------------------------------------------------------------------
// GET ID RECEIVER
//------------------------------------------------------------------------------
const size_t& ServerStateAttackingUnit::getIdReceiver() const {
    return idReceiver;
}
//------------------------------------------------------------------------------
