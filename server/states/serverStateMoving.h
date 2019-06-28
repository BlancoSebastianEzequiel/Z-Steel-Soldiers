// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEMOVING_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTATEMOVING_H_
//------------------------------------------------------------------------------
class ServerNode;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverState.h"
//------------------------------------------------------------------------------
class ServerStateMoving: public ServerState {
 private :
    const ServerNode& nextPosition;
 public :
    //--------------------------------------------------------------------------
    explicit ServerStateMoving(const ServerNode& nextPosition);
    //--------------------------------------------------------------------------
    ~ServerStateMoving();
    //--------------------------------------------------------------------------
    const ServerNode& movingTo()const;
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
