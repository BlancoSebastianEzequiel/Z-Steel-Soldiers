// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTOBJECT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTOBJECT_H_
//------------------------------------------------------------------------------
class Game;
class TaskAttackUnit;
class NodePath;
class Node;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include <queue>
#include "taskShoot.h"
//------------------------------------------------------------------------------
class TaskShootObject: public TaskShoot {
 public :
    //--------------------------------------------------------------------------
    TaskShootObject(
            Game &aGame, size_t idShooter, size_t idTarget, double waitingTime);
    //--------------------------------------------------------------------------
    ~TaskShootObject();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTOBJECT_H_
