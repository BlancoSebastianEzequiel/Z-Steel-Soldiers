// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEMEDIUMTANK_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEMEDIUMTANK_H_
//------------------------------------------------------------------------------
class Game;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "task.h"
//------------------------------------------------------------------------------
class TaskCreateMediumTank: public Task {
 private :
    size_t idBuilding;
 public :
    //--------------------------------------------------------------------------
    TaskCreateMediumTank(Game& aGame, size_t idBuilding);
    //--------------------------------------------------------------------------
    ~TaskCreateMediumTank();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATEMEDIUMTANK_H_
