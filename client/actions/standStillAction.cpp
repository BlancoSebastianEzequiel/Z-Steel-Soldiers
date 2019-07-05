#include "unitAction.h"
#include "walkAction.h"
#include "../game_objects/units/unit.h"
#include "standStillAction.h"

StandStillAction::StandStillAction(Unit* unit):
   UnitAction(unit){
}

void StandStillAction::execute() {
    if (unit != nullptr){
        this->unit->stand_still();
    }
}

void StandStillAction::finish() {
    //no hace nada
}
