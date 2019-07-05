// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATETOUGH_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATETOUGH_H_
//------------------------------------------------------------------------------
class Game;
//------------------------------------------------------------------------------
#include <ctime>
#include <string>
#include "task.h"
//------------------------------------------------------------------------------
class TaskCreateTough: public Task {
 private :
    size_t idBuilding;
public :
    //--------------------------------------------------------------------------
    TaskCreateTough(Game& aGame, size_t idBuilding);
    //--------------------------------------------------------------------------
    ~TaskCreateTough();
    //--------------------------------------------------------------------------
    virtual void execute();
    //--------------------------------------------------------------------------
    virtual bool isRelocable()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTASKCREATETOUGH_H_
