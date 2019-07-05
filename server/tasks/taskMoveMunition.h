// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVEMUNITION_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVEMUNITION_H_
//------------------------------------------------------------------------------
class Game;
class Node;
class State;
class NodePath;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "task.h"
//------------------------------------------------------------------------------
class TaskMoveMunition: public Task {
 private :
    NodePath* nodePath;
    size_t idMunition;
    bool hasExecuted;
 public :
    //--------------------------------------------------------------------------
    TaskMoveMunition(
            Game& aGame, NodePath& nodePath, size_t idMunition);
    //--------------------------------------------------------------------------
    ~TaskMoveMunition();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVEMUNITION_H_
