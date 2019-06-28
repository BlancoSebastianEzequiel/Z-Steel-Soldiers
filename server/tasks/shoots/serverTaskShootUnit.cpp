// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverTaskShootUnit.h"
#include "../../games/serverGame.h"
#include "../../units/serverUnit.h"
#include "../serverTaskMoveMunition.h"
#include "../../states/serverStateAttackingUnit.h"
#include "../serverTaskAttackUnit.h"
#include "../../armament/serverArmament.h"
//------------------------------------------------------------------------------
// SERVER TASK SHOOT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskShootUnit::ServerTaskShootUnit(
        ServerGame &aGame, size_t idShooter, size_t idTarget,
        double waitingTime): ServerTaskShoot::ServerTaskShoot(
        aGame, idShooter, idTarget, waitingTime) {
    if (waitingTime == 0) {
        ServerUnit* shooter = aGame.getUnit(idShooter);
        shooter->changeState(*new ServerStateAttackingUnit(idTarget));
    }
}
//------------------------------------------------------------------------------
// SERVER TASK SHOOT DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskShootUnit::~ServerTaskShootUnit() {}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void ServerTaskShootUnit::execute() {
    ServerUnit* target = aGame.getUnit(idTarget);
    const ServerNode* dst = target->getPosition();
    builtMunitionTasks(*dst);
    ServerTask* attack = new ServerTaskAttackUnit(aGame, idMunition, idTarget);
    attack->changeWaitingTime(finalWaitingTime);
    ServerUnit* unitForward = aGame.getUnit(idForward);
    ServerArmament* munition = aGame.getMunition(idMunition);
    munition->setTarget(*target);
    munition->addTask(attack);
    unitForward->changeState(*new ServerStateAttackingUnit(idTarget));
    changeWaitingTime(unitForward->getShootingFrequency());
}
//------------------------------------------------------------------------------
