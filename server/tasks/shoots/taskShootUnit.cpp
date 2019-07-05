// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskShootUnit.h"
#include "../../games/game.h"
#include "../../units/unit.h"
#include "../taskMoveMunition.h"
#include "../../states/stateAttackingUnit.h"
#include "../taskAttackUnit.h"
#include "../../armament/armament.h"
//------------------------------------------------------------------------------
// SERVER TASK SHOOT CONSTRUCTOR
//------------------------------------------------------------------------------
TaskShootUnit::TaskShootUnit(
        Game &aGame, size_t idShooter, size_t idTarget,
        double waitingTime): TaskShoot::TaskShoot(
        aGame, idShooter, idTarget, waitingTime) {
    if (waitingTime == 0) {
        Unit* shooter = aGame.getUnit(idShooter);
        shooter->changeState(*new StateAttackingUnit(idTarget));
    }
}
//------------------------------------------------------------------------------
// SERVER TASK SHOOT DESTRUCTOR
//------------------------------------------------------------------------------
TaskShootUnit::~TaskShootUnit() {}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskShootUnit::execute() {
    Unit* target = aGame.getUnit(idTarget);
    const Node* dst = target->getPosition();
    builtMunitionTasks(*dst);
    Task* attack = new TaskAttackUnit(aGame, idMunition, idTarget);
    attack->changeWaitingTime(finalWaitingTime);
    Unit* unitForward = aGame.getUnit(idForward);
    Armament* munition = aGame.getMunition(idMunition);
    munition->setTarget(*target);
    munition->addTask(attack);
    unitForward->changeState(*new StateAttackingUnit(idTarget));
    changeWaitingTime(unitForward->getShootingFrequency());
}
//------------------------------------------------------------------------------
