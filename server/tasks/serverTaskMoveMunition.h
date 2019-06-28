// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVEMUNITION_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVEMUNITION_H_
//------------------------------------------------------------------------------
class ServerGame;
class ServerNode;
class ServerState;
class ServerNodePath;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverTask.h"
//------------------------------------------------------------------------------
class ServerTaskMoveMunition: public ServerTask {
 private :
    ServerNodePath* nodePath;
    size_t idMunition;
    bool hasExecuted;
 public :
    //--------------------------------------------------------------------------
    ServerTaskMoveMunition(
            ServerGame& aGame, ServerNodePath& nodePath, size_t idMunition);
    //--------------------------------------------------------------------------
    ~ServerTaskMoveMunition();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVEMUNITION_H_
