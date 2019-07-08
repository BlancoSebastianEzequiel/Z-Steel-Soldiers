// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef TASK_SHOOT_UNIT_H
#define TASK_SHOOT_UNIT_H
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
class TaskShootUnit: public TaskShoot {
 public :
    //--------------------------------------------------------------------------
    TaskShootUnit(
            Game &aGame, size_t idShooter, size_t idTarget,
            double waitingTime);
    //--------------------------------------------------------------------------
    ~TaskShootUnit();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif // TASK_SHOOT_UNIT_H
