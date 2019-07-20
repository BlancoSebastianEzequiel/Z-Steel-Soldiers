// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskShootObject.h"
#include "../../games/game.h"
#include "../../units/unit.h"
#include "../taskMoveMunition.h"
#include "../taskAttackObject.h"
#include "../../states/stateAttackingObject.h"
#include "../../armament/armament.h"
#include "../../objects/object.h"
//------------------------------------------------------------------------------
// SERVER TASK SHOOT CONSTRUCTOR
//------------------------------------------------------------------------------
TaskShootObject::TaskShootObject(
        Game &aGame, size_t idShooter, size_t idTarget,
        double waitingTime):
        TaskShoot::TaskShoot(
                aGame, idShooter, idTarget, waitingTime) {
    if (waitingTime == 0) {
        Unit* shooter = aGame.getUnit(idShooter);
        shooter->changeState(*new StateAttackingObject(idTarget));
    }
}
//------------------------------------------------------------------------------
// SERVER TASK SHOOT DESTRUCTOR
//------------------------------------------------------------------------------
TaskShootObject::~TaskShootObject() {}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskShootObject::execute() {
    Object* target = aGame.gameMap.getObject(idTarget);
    const Node& dst = target->getMainPos();
    builtMunitionTasks(dst);
    Task* attack;
    attack = new TaskAttackObject(aGame, idMunition, idTarget);
    attack->changeWaitingTime(finalWaitingTime);
    Unit* unitForward = aGame.getUnit(idForward);
    Armament* munition = aGame.getMunition(idMunition);
    munition->setTarget(*target);
    munition->addTask(attack);
    unitForward->changeState(*new StateAttackingObject(idTarget));
    changeWaitingTime(unitForward->getShootingFrequency());
}
//------------------------------------------------------------------------------
