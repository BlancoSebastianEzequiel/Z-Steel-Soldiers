// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef STATE_ATTACKING_OBJECT_H
#define STATE_ATTACKING_OBJECT_H
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "state.h"
//------------------------------------------------------------------------------
class StateAttackingObject: public State {
 private :
    const size_t idReceiver;
 public :
    //--------------------------------------------------------------------------
    explicit StateAttackingObject(size_t idReceiver);
    //--------------------------------------------------------------------------
    ~StateAttackingObject();
    //--------------------------------------------------------------------------
    virtual bool isMoving()const;
    //--------------------------------------------------------------------------
    virtual bool isAttackingUnit()const;
    //--------------------------------------------------------------------------
    virtual bool isAttackingObject()const;
    //--------------------------------------------------------------------------
    virtual bool isStill()const;
    //--------------------------------------------------------------------------
    virtual bool isDead()const;
    //--------------------------------------------------------------------------
    virtual bool isBroken()const;
    //--------------------------------------------------------------------------
    const size_t& getIdReceiver()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // STATE_ATTACKING_OBJECT_H
