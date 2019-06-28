#include "client_UnitAction.h"
#include "client_DieAction.h"
#include "../game_objects/units/client_Unit.h"
//------------------------------------------------------------------------------
// DIE ACTION CONSTRUCTOR
//------------------------------------------------------------------------------
DieAction::DieAction(Unit* unit): UnitAction(unit) {}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void DieAction::execute() {
    if (unit != nullptr) {
        this->unit->die();
    }
}
//------------------------------------------------------------------------------
// FINISH
//------------------------------------------------------------------------------
void DieAction::finish() {}
//------------------------------------------------------------------------------
