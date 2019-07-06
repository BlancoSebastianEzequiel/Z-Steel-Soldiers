#ifndef DIE_ACTION_H
#define DIE_ACTION_H
//------------------------------------------------------------------------------
#include "../game_objects/units/unit.h"
#include "unitAction.h"
//------------------------------------------------------------------------------
class Unit;
//------------------------------------------------------------------------------
class DieAction: public UnitAction {
 public :
    //--------------------------------------------------------------------------
    explicit DieAction(Unit* unit);
    //--------------------------------------------------------------------------
    // Simplemente hace invisible a la unidad
    void execute();
    //--------------------------------------------------------------------------
    // Libera los recursos utilizados por la unidad
    void finish();
    //--------------------------------------------------------------------------
};
#endif  // DIE_ACTION_H
