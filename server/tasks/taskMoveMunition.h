// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef TASK_MOVE_MUNITION_H
#define TASK_MOVE_MUNITION_H
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
#endif // TASK_MOVE_MUNITION_H
