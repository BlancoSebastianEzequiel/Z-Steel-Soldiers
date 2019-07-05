// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKUNIT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKUNIT_H_
//------------------------------------------------------------------------------
class Game;
class Node;
class State;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "task.h"
//------------------------------------------------------------------------------
class TaskAttackUnit : public Task {
 private :
    size_t idMunition;
    size_t idTarget;
 public :
    //--------------------------------------------------------------------------
    TaskAttackUnit(Game& aGame, size_t idMunition, size_t idTarget);
    //--------------------------------------------------------------------------
    ~TaskAttackUnit();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKATTACKUNIT_H_
