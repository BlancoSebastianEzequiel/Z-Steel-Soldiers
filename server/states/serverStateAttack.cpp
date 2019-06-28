// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverStateAttack.h"
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerStateAttack::ServerStateAttack() {}
//------------------------------------------------------------------------------
// SERVER STATE ATTACKING UNIT DESTRUCTOR
//------------------------------------------------------------------------------
ServerStateAttack::~ServerStateAttack() {}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool ServerStateAttack::isMoving() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ATTACKING UNIT
//------------------------------------------------------------------------------
bool ServerStateAttack::isAttackingUnit() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ATTACKING OBJECT
//------------------------------------------------------------------------------
bool ServerStateAttack::isAttackingObject() const {
    return false;
}
//------------------------------------------------------------------------------
// IS STILL
//------------------------------------------------------------------------------
bool ServerStateAttack::isStill() const {
    return false;
}
//------------------------------------------------------------------------------
// IS DEAD
//------------------------------------------------------------------------------
bool ServerStateAttack::isDead() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool ServerStateAttack::isBroken() const {
    return false;
}
//------------------------------------------------------------------------------
