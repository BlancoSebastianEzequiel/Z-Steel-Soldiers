// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTOBJECT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTOBJECT_H_
//------------------------------------------------------------------------------
class ServerGame;
class ServerTaskAttackUnit;
class ServerNodePath;
class ServerNode;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include <queue>
#include "serverTaskShoot.h"
//------------------------------------------------------------------------------
class ServerTaskShootObject: public ServerTaskShoot {
 public :
    //--------------------------------------------------------------------------
    ServerTaskShootObject(
            ServerGame &aGame, size_t idShooter, size_t idTarget, double waitingTime);
    //--------------------------------------------------------------------------
    ~ServerTaskShootObject();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTOBJECT_H_
