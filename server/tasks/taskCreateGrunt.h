// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEGRUNT_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEGRUNT_H_
//------------------------------------------------------------------------------
class Game;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "task.h"
//------------------------------------------------------------------------------
class TaskCreateGrunt: public Task {
 private :
    size_t idBuilding;
 public :
    //--------------------------------------------------------------------------
    TaskCreateGrunt(Game& aGame, size_t idBuilding);
    //--------------------------------------------------------------------------
    ~TaskCreateGrunt();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEGRUNT_H_
