// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef TASK_SHOOT_OBJECT_H
#define TASK_SHOOT_OBJECT_H
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
#endif  // TASK_SHOOT_OBJECT_H
