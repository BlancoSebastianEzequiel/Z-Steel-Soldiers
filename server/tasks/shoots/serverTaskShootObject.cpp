// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverTaskShootObject.h"
#include "../../games/serverGame.h"
#include "../../units/serverUnit.h"
#include "../serverTaskMoveMunition.h"
#include "../serverTaskAttackObject.h"
#include "../../states/serverStateAttackingObject.h"
#include "../../armament/serverArmament.h"
#include "../../objects/serverObject.h"
//------------------------------------------------------------------------------
// SERVER TASK SHOOT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskShootObject::ServerTaskShootObject(
        ServerGame &aGame, size_t idShooter, size_t idTarget,
        double waitingTime):
        ServerTaskShoot::ServerTaskShoot(
                aGame, idShooter, idTarget, waitingTime) {
    if (waitingTime == 0) {
        ServerUnit* shooter = aGame.getUnit(idShooter);
        shooter->changeState(*new ServerStateAttackingObject(idTarget));
    }
}
//------------------------------------------------------------------------------
// SERVER TASK SHOOT DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskShootObject::~ServerTaskShootObject() {}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void ServerTaskShootObject::execute() {
    ServerObject* target = aGame.gameMap.getObject(idTarget);
    const ServerNode& dst = target->getPrincipalPosition();
    builtMunitionTasks(dst);
    ServerTask* attack;
    attack = new ServerTaskAttackObject(aGame, idMunition, idTarget);
    attack->changeWaitingTime(finalWaitingTime);
    ServerUnit* unitForward = aGame.getUnit(idForward);
    ServerArmament* munition = aGame.getMunition(idMunition);
    munition->setTarget(*target);
    munition->addTask(attack);
    unitForward->changeState(*new ServerStateAttackingObject(idTarget));
    changeWaitingTime(unitForward->getShootingFrequency());
}
//------------------------------------------------------------------------------
