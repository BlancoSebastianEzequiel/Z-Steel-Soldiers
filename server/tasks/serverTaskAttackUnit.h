// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKUNIT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKUNIT_H_
//------------------------------------------------------------------------------
class ServerGame;
class ServerNode;
class ServerState;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "serverTask.h"
//------------------------------------------------------------------------------
class ServerTaskAttackUnit : public ServerTask {
 private :
    size_t idMunition;
    size_t idTarget;
 public :
    //--------------------------------------------------------------------------
    ServerTaskAttackUnit(ServerGame& aGame, size_t idMunition, size_t idTarget);
    //--------------------------------------------------------------------------
    ~ServerTaskAttackUnit();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKUNIT_H_
