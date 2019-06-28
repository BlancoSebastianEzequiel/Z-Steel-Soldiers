// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverStateAttackingObject.h"
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerStateAttackingObject::ServerStateAttackingObject(size_t idReceiver):
        idReceiver(idReceiver) {}
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT DESTRUCTOR
//------------------------------------------------------------------------------
ServerStateAttackingObject::~ServerStateAttackingObject() {}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool ServerStateAttackingObject::isMoving() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ATTACKING UNIT
//------------------------------------------------------------------------------
bool ServerStateAttackingObject::isAttackingUnit() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ATTACKING OBJECT
//------------------------------------------------------------------------------
bool ServerStateAttackingObject::isAttackingObject() const {
    return true;
}
//------------------------------------------------------------------------------
// IS STILL
//------------------------------------------------------------------------------
bool ServerStateAttackingObject::isStill() const {
    return false;
}
//------------------------------------------------------------------------------
// IS DEAD
//------------------------------------------------------------------------------
bool ServerStateAttackingObject::isDead() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool ServerStateAttackingObject::isBroken() const {
    return false;
}
//------------------------------------------------------------------------------
// GET ID RECEIVER
//------------------------------------------------------------------------------
const size_t& ServerStateAttackingObject::getIdReceiver() const {
    return idReceiver;
}
//------------------------------------------------------------------------------
