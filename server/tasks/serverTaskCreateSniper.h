// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATESNIPER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATESNIPER_H_
//------------------------------------------------------------------------------
class ServerGame;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverTask.h"
//------------------------------------------------------------------------------
class ServerTaskCreateSniper: public ServerTask {
 private :
    size_t idBuilding;
 public :
    //--------------------------------------------------------------------------
    ServerTaskCreateSniper(ServerGame& aGame, size_t idBuilding);
    //--------------------------------------------------------------------------
    ~ServerTaskCreateSniper();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATESNIPER_H_
