// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskShoot.h"
#include "../../armament/armament.h"
#include "../../games/game.h"
#include "../../units/unit.h"
#include "../taskMoveMunition.h"
#include "../../terrains/paths/nodePath.h"
//------------------------------------------------------------------------------
// SERVER TASK SHOOT CONSTRUCTOR
//------------------------------------------------------------------------------
TaskShoot::TaskShoot(
        Game &aGame, size_t idShooter, size_t idTarget,
        double waitingTime):
        Task::Task(aGame), idForward(idShooter),
        idTarget(idTarget) {
    this->waitingTime = waitingTime;
    finalWaitingTime = 0;
}
//------------------------------------------------------------------------------
// SERVER TASK SHOOT DESTRUCTOR
//------------------------------------------------------------------------------
TaskShoot::~TaskShoot() {}
//------------------------------------------------------------------------------
// BUILT MUNITION TASKS
//------------------------------------------------------------------------------
void TaskShoot::builtMunitionTasks(const Node& dst) {
    Unit* unitForward = aGame.getUnit(idForward);
    unitForward->createMunition(aGame);
    idMunition = unitForward->getCurrentIdMunition();
    Armament* munition = aGame.getMunition(idMunition);
    Path munitionPath = munition->goTo(dst);
    NodePath* nodePath;
    TaskMoveMunition* task;
    // double cumulativeTime = 0;
    while (!munitionPath.empty()) {
        nodePath = munitionPath.front();
        munitionPath.pop();
        task = new TaskMoveMunition(aGame, *nodePath, idMunition);
        munition->addTask(task);
        if (munitionPath.empty()) finalWaitingTime = task->waitingTime + 1;
    }
}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskShoot::isRelocable() const {
    return true;
}
//------------------------------------------------------------------------------
