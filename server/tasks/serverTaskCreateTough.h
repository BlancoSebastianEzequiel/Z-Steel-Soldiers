// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATETOUGH_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATETOUGH_H_
//------------------------------------------------------------------------------
class ServerGame;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverTask.h"
//------------------------------------------------------------------------------
class ServerTaskCreateTough: public ServerTask {
 private :
    size_t idBuilding;
public :
    //--------------------------------------------------------------------------
    ServerTaskCreateTough(ServerGame& aGame, size_t idBuilding);
    //--------------------------------------------------------------------------
    ~ServerTaskCreateTough();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATETOUGH_H_
