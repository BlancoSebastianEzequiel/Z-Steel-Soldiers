// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVE_H_
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
class ServerTaskMove: public ServerTask {
 private :
    ServerNodePath* nodePath;
    size_t idUnit;
    bool hasExecuted;
 public :
    //--------------------------------------------------------------------------
    ServerTaskMove(ServerGame& aGame, ServerNodePath& nodePath, size_t idUnit);
    //--------------------------------------------------------------------------
    ~ServerTaskMove();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVE_H_
