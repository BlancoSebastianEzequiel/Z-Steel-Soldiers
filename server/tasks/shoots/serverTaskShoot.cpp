// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverTaskShoot.h"
#include "../../armament/serverArmament.h"
#include "../../games/serverGame.h"
#include "../../units/serverUnit.h"
#include "../serverTaskMoveMunition.h"
#include "../../terrains/paths/serverNodePath.h"
//------------------------------------------------------------------------------
// SERVER TASK SHOOT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskShoot::ServerTaskShoot(
        ServerGame &aGame, size_t idShooter, size_t idTarget,
        double waitingTime):
        ServerTask::ServerTask(aGame), idForward(idShooter),
        idTarget(idTarget) {
    this->waitingTime = waitingTime;
    finalWaitingTime = 0;
}
//------------------------------------------------------------------------------
// SERVER TASK SHOOT DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskShoot::~ServerTaskShoot() {}
//------------------------------------------------------------------------------
// BUILT MUNITION TASKS
//------------------------------------------------------------------------------
void ServerTaskShoot::builtMunitionTasks(const ServerNode& dst) {
    ServerUnit* unitForward = aGame.getUnit(idForward);
    unitForward->createMunition(aGame);
    idMunition = unitForward->getCurrentIdMunition();
    ServerArmament* munition = aGame.getMunition(idMunition);
    Path munitionPath = munition->goTo(dst);
    ServerNodePath* nodePath;
    ServerTaskMoveMunition* task;
    // double cumulativeTime = 0;
    while (!munitionPath.empty()) {
        nodePath = munitionPath.front();
        munitionPath.pop();
        task = new ServerTaskMoveMunition(aGame, *nodePath, idMunition);
        munition->addTask(task);
        if (munitionPath.empty()) finalWaitingTime = task->waitingTime + 1;
    }
}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool ServerTaskShoot::isRelocable() const {
    return true;
}
//------------------------------------------------------------------------------
