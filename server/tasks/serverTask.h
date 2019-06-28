// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASK_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASK_H_
//------------------------------------------------------------------------------
class ServerGame;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
//------------------------------------------------------------------------------
class ServerTask {
 protected :
    ServerGame& aGame;
 public :
    time_t timer;
    double waitingTime;
 public :
    //--------------------------------------------------------------------------
    explicit ServerTask(ServerGame& aGame);
    //--------------------------------------------------------------------------
    virtual ~ServerTask();
    //--------------------------------------------------------------------------
    virtual void execute() = 0;
    //--------------------------------------------------------------------------
    bool executable();
    //--------------------------------------------------------------------------
    void changeWaitingTime(double newWaitingTime);
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const = 0;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASK_H_
