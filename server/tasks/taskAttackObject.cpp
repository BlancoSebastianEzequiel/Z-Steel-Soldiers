// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskAttackObject.h"
#include "../games/game.h"
#include "../units/unit.h"
#include "../objects/object.h"
#include "../states/stateAttackingUnit.h"
#include "../armament/armament.h"
#include "../states/stateBroken.h"
//------------------------------------------------------------------------------
// SERVER TASK ATTACK GROUNDOBJECT CONSTRUCTOR
//------------------------------------------------------------------------------
TaskAttackObject::TaskAttackObject(
        Game& aGame, size_t idMunition, size_t idTarget):
        Task::Task(aGame), idMunition(idMunition),
        idTarget(idTarget) {
}
//------------------------------------------------------------------------------
// SERVER TASK ATTACK GROUNDOBJECT DESTRUCTOR
//------------------------------------------------------------------------------
TaskAttackObject::~TaskAttackObject() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskAttackObject::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskAttackObject::execute() {
    Armament* munition = aGame.getMunition(idMunition);
    Object* receiver = aGame.gameMap.getObject(idTarget);
    munition->attack(*receiver);
    munition->changeState(*new StateBroken());
}
//------------------------------------------------------------------------------
