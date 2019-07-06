#ifndef WALK_ACTION_H
#define WALK_ACTION_H
//------------------------------------------------------------------------------
#include "../game_objects/units/unit.h"
#include "unitAction.h"
//------------------------------------------------------------------------------
class Unit;
//------------------------------------------------------------------------------
class WalkAction: public UnitAction {
 private :
    unsigned int dest_x;
    unsigned int dest_y;
    double speed;
 public :
    //--------------------------------------------------------------------------
    WalkAction(
            Unit* unit, unsigned int dest_x, unsigned int dest_y, double speed);
    //--------------------------------------------------------------------------
    void execute();
    //--------------------------------------------------------------------------
    // Fuerza la posicion final del movimiento
    void finish();
    //--------------------------------------------------------------------------
};
#endif  // WALK_ACTION_H
