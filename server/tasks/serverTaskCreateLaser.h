// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATELASER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATELASER_H_
//------------------------------------------------------------------------------
class ServerGame;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverTask.h"
//------------------------------------------------------------------------------
class ServerTaskCreateLaser: public ServerTask {
 private :
    size_t idBuilding;
 public :
    //--------------------------------------------------------------------------
    ServerTaskCreateLaser(ServerGame& aGame, size_t idBuilding);
    //--------------------------------------------------------------------------
    ~ServerTaskCreateLaser();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATELASER_H_
