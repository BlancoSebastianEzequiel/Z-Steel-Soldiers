// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "stateAttackingUnit.h"
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
StateAttackingUnit::StateAttackingUnit(size_t idReceiver):
        idReceiver(idReceiver) {}
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT DESTRUCTOR
//------------------------------------------------------------------------------
StateAttackingUnit::~StateAttackingUnit() {}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool StateAttackingUnit::isMoving() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ATTACKING UNIT
//------------------------------------------------------------------------------
bool StateAttackingUnit::isAttackingUnit() const {
    return true;
}
//------------------------------------------------------------------------------
// IS ATTACKING OBJECT
//------------------------------------------------------------------------------
bool StateAttackingUnit::isAttackingObject() const {
    return false;
}
//------------------------------------------------------------------------------
// IS STILL
//------------------------------------------------------------------------------
bool StateAttackingUnit::isStill() const {
    return false;
}
//------------------------------------------------------------------------------
// IS DEAD
//------------------------------------------------------------------------------
bool StateAttackingUnit::isDead() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool StateAttackingUnit::isBroken() const {
    return false;
}
//------------------------------------------------------------------------------
// GET ID RECEIVER
//------------------------------------------------------------------------------
const size_t& StateAttackingUnit::getIdReceiver() const {
    return idReceiver;
}
//------------------------------------------------------------------------------