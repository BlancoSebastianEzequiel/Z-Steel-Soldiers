#include "shootAction.h"
#include "../game_objects/units/unit.h"
#include "../game_objects/ammos/ammo.h"
ShootAction::ShootAction(Unit* unit,GameObject* target):
   UnitAction(unit), target(target){
}

void ShootAction::execute(){
    if (unit != nullptr){
      this->unit->shoot(target);
    }
}

void ShootAction::finish(){
}
