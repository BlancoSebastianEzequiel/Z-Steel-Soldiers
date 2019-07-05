// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskAttackUnit.h"
#include "../games/game.h"
#include "../units/unit.h"
#include "../armament/armament.h"
#include "../states/stateBroken.h"

//------------------------------------------------------------------------------
// SERVER TASK ATTACK UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
TaskAttackUnit::TaskAttackUnit(
        Game& aGame, size_t idMunition, size_t idTarget):
        Task::Task(aGame), idMunition(idMunition),
        idTarget(idTarget) {}
//------------------------------------------------------------------------------
// SERVER TASK ATTACK UNIT DESTRUCTOR
//------------------------------------------------------------------------------
TaskAttackUnit::~TaskAttackUnit() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskAttackUnit::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskAttackUnit::execute() {
    Armament* munition = aGame.getMunition(idMunition);
    Unit* receiver = aGame.getUnit(idTarget);
    munition->attack(*receiver);
    munition->changeState(*new StateBroken());
}
//------------------------------------------------------------------------------
