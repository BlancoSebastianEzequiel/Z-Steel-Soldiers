// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverTaskAttackUnit.h"
#include "../games/serverGame.h"
#include "../units/serverUnit.h"
#include "../armament/serverArmament.h"
#include "../states/serverStateBroken.h"

//------------------------------------------------------------------------------
// SERVER TASK ATTACK UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskAttackUnit::ServerTaskAttackUnit(
        ServerGame& aGame, size_t idMunition, size_t idTarget):
        ServerTask::ServerTask(aGame), idMunition(idMunition),
        idTarget(idTarget) {}
//------------------------------------------------------------------------------
// SERVER TASK ATTACK UNIT DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskAttackUnit::~ServerTaskAttackUnit() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool ServerTaskAttackUnit::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void ServerTaskAttackUnit::execute() {
    ServerArmament* munition = aGame.getMunition(idMunition);
    ServerUnit* receiver = aGame.getUnit(idTarget);
    munition->attack(*receiver);
    munition->changeState(*new ServerStateBroken());
}
//------------------------------------------------------------------------------
