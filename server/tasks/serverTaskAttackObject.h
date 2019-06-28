// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKOBJECT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKOBJECT_H_
//------------------------------------------------------------------------------
class ServerGame;
class ServerNode;
class ServerState;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverTask.h"
//------------------------------------------------------------------------------
class ServerTaskAttackObject : public ServerTask {
 private :
    size_t idMunition;
    size_t idTarget;
 public :
    //--------------------------------------------------------------------------
    ServerTaskAttackObject(ServerGame& aGame, size_t idMunition, size_t idTarget);
    //--------------------------------------------------------------------------
    ~ServerTaskAttackObject();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKOBJECT_H_
