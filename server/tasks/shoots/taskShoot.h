// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOT_H_
//------------------------------------------------------------------------------
class Game;
class TaskAttackUnit;
class NodePath;
class Node;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include <queue>
#include "../task.h"
//------------------------------------------------------------------------------
typedef std::queue<NodePath*> Path;
//------------------------------------------------------------------------------
class TaskShoot: public Task {
 protected :
    size_t idForward;
    size_t idTarget;
    double finalWaitingTime;
    size_t idMunition;
 public :
    //--------------------------------------------------------------------------
    TaskShoot(
            Game &aGame, size_t idShooter, size_t idTarget, double waitingTime);
    //--------------------------------------------------------------------------
    void builtMunitionTasks(const Node& dst);
    //--------------------------------------------------------------------------
    virtual ~TaskShoot();
    //--------------------------------------------------------------------------
    virtual void execute() = 0;
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOT_H_
