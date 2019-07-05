// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEMOVING_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEMOVING_H_
//------------------------------------------------------------------------------
class Node;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "state.h"
//------------------------------------------------------------------------------
class StateMoving: public State {
 private :
    const Node& nextPosition;
 public :
    //--------------------------------------------------------------------------
    explicit StateMoving(const Node& nextPosition);
    //--------------------------------------------------------------------------
    ~StateMoving();
    //--------------------------------------------------------------------------
    const Node& movingTo()const;
    //--------------------------------------------------------------------------
    bool isMoving()const;
    //--------------------------------------------------------------------------
    virtual bool isAttackingUnit()const;
    //--------------------------------------------------------------------------
    virtual bool isAttackingObject()const;
    //--------------------------------------------------------------------------
    virtual bool isDead()const;
    //--------------------------------------------------------------------------
    virtual bool isStill()const;
    //--------------------------------------------------------------------------
    virtual bool isBroken()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEMOVING_H_
