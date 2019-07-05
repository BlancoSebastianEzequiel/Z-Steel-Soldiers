#ifndef CLIENT_UNITACTION_H_INCLUDED
#define CLIENT_UNITACTION_H_INCLUDED
//------------------------------------------------------------------------------
#include "../game_objects/units/unit.h"
//------------------------------------------------------------------------------
class Unit;
//------------------------------------------------------------------------------
class UnitAction {
 protected :
    Unit* unit;
 public :
    //--------------------------------------------------------------------------
    explicit UnitAction(Unit* unit);
    //--------------------------------------------------------------------------
    // La unidad ejecuta la accion
    virtual void execute() = 0;
    //--------------------------------------------------------------------------
    // La unidad detiene la accion
    virtual void finish() = 0;
    //--------------------------------------------------------------------------
    virtual ~UnitAction();
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_UNITACTION_H_INCLUDED
