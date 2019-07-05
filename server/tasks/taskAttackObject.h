// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKOBJECT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKOBJECT_H_
//------------------------------------------------------------------------------
class Game;
class Node;
class State;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "task.h"
//------------------------------------------------------------------------------
class TaskAttackObject : public Task {
 private :
    size_t idMunition;
    size_t idTarget;
 public :
    //--------------------------------------------------------------------------
    TaskAttackObject(Game& aGame, size_t idMunition, size_t idTarget);
    //--------------------------------------------------------------------------
    ~TaskAttackObject();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKOBJECT_H_
