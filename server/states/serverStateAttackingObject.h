// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEATTACKINGOBJECT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEATTACKINGOBJECT_H_
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverState.h"
//------------------------------------------------------------------------------
class ServerStateAttackingObject: public ServerState {
 private :
    const size_t idReceiver;
 public :
    //--------------------------------------------------------------------------
    explicit ServerStateAttackingObject(size_t idReceiver);
    //--------------------------------------------------------------------------
    ~ServerStateAttackingObject();
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEATTACKINGOBJECT_H_
