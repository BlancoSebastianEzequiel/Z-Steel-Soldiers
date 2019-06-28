// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverStateMoving.h"
//------------------------------------------------------------------------------
// SERVER STATE MOVING CONSTRUCTOR
//------------------------------------------------------------------------------
ServerStateMoving::ServerStateMoving(const ServerNode& nextPosition):
        nextPosition(nextPosition) {}
//------------------------------------------------------------------------------
// SERVER STATE MOVING DESTRUCTOR
//------------------------------------------------------------------------------
ServerStateMoving::~ServerStateMoving() {}
//------------------------------------------------------------------------------
// MOVING TO
//------------------------------------------------------------------------------
const ServerNode& ServerStateMoving::movingTo()const {
    return nextPosition;
}
//------------------------------------------------------------------------------
// IS MOVING
//------------------------------------------------------------------------------
bool ServerStateMoving::isMoving()const {
    return true;
}
//------------------------------------------------------------------------------
// IS ATTACKING UNIT
//------------------------------------------------------------------------------
bool ServerStateMoving::isAttackingUnit() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ATTACKING OBJECT
//------------------------------------------------------------------------------
bool ServerStateMoving::isAttackingObject() const {
    return false;
}
//------------------------------------------------------------------------------
// IS STILL
//------------------------------------------------------------------------------
bool ServerStateMoving::isStill() const {
    return false;
}
//------------------------------------------------------------------------------
// IS DEAD
//------------------------------------------------------------------------------
bool ServerStateMoving::isDead() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BROKEN
//------------------------------------------------------------------------------
bool ServerStateMoving::isBroken() const {
    return false;
}
//------------------------------------------------------------------------------
