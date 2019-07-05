// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTUNIT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTUNIT_H_
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKSHOOTUNIT_H_
