// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEHEAVYTANK_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEHEAVYTANK_H_
//------------------------------------------------------------------------------
class Game;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "task.h"
//------------------------------------------------------------------------------
class TaskCreateHeavyTank: public Task {
 private :
    size_t idBuilding;
 public :
    //--------------------------------------------------------------------------
    TaskCreateHeavyTank(Game& aGame, size_t idBuilding);
    //--------------------------------------------------------------------------
    ~TaskCreateHeavyTank();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEHEAVYTANK_H_
