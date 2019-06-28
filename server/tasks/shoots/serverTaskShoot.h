// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOT_H_
//------------------------------------------------------------------------------
class ServerGame;
class ServerTaskAttackUnit;
class ServerNodePath;
class ServerNode;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include <queue>
#include "../serverTask.h"
//------------------------------------------------------------------------------
typedef std::queue<ServerNodePath*> Path;
//------------------------------------------------------------------------------
class ServerTaskShoot: public ServerTask {
 protected :
    size_t idForward;
    size_t idTarget;
    double finalWaitingTime;
    size_t idMunition;
 public :
    //--------------------------------------------------------------------------
    ServerTaskShoot(
            ServerGame &aGame, size_t idShooter, size_t idTarget, double waitingTime);
    //--------------------------------------------------------------------------
    void builtMunitionTasks(const ServerNode& dst);
    //--------------------------------------------------------------------------
    virtual ~ServerTaskShoot();
    //--------------------------------------------------------------------------
    virtual void execute() = 0;
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOT_H_
