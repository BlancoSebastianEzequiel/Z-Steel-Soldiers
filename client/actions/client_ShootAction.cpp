#include "client_ShootAction.h"
#include "../game_objects/units/client_Unit.h"
#include "../game_objects/ammos/client_Ammo.h"
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
