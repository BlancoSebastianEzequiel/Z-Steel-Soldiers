// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVE_H_
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
class TaskMove: public Task {
 private :
    NodePath* nodePath;
    size_t idUnit;
    bool hasExecuted;
 public :
    //--------------------------------------------------------------------------
    TaskMove(Game& aGame, NodePath& nodePath, size_t idUnit);
    //--------------------------------------------------------------------------
    ~TaskMove();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKMOVE_H_
