// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskMoveMunition.h"
#include "../games/game.h"
#include "../players/player.h"
#include "../terrains/node.h"
#include "../terrains/paths/nodePath.h"
#include "../states/state.h"
#include "../armament/armament.h"
//------------------------------------------------------------------------------
// SERVER TASK MOVE MUNITION CONSTRUCTOR
//------------------------------------------------------------------------------
TaskMoveMunition::TaskMoveMunition(
        Game& aGame, NodePath& nodePath, size_t idMunition):
        Task::Task(aGame), idMunition(idMunition) {
    hasExecuted = false;
    this->nodePath = &nodePath;
    this->waitingTime = this->nodePath->getCumulativeWaitingTime();
}
//------------------------------------------------------------------------------
// SERVER TASK MOVE MUNITION DESTRUCTOR
//------------------------------------------------------------------------------
TaskMoveMunition::~TaskMoveMunition() {
    if (!hasExecuted) {
        const State* state = nodePath->getState();
        delete state;
    }
    delete nodePath;
}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskMoveMunition::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskMoveMunition::execute() {
    hasExecuted = true;
    aGame.getMunition(idMunition)->changePosition(nodePath->getNode());
    // printf("Munition id: %zu - waitingTime: %f - ", idMunition, waitingTime);
    // nodePath->getNode().showNode();
    aGame.getMunition(idMunition)->changeState(*nodePath->getState());
}
//------------------------------------------------------------------------------
