// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTUNIT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTUNIT_H_
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
class ServerTaskShootUnit: public ServerTaskShoot {
 public :
    //--------------------------------------------------------------------------
    ServerTaskShootUnit(
            ServerGame &aGame, size_t idShooter, size_t idTarget,
            double waitingTime);
    //--------------------------------------------------------------------------
    ~ServerTaskShootUnit();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTUNIT_H_
