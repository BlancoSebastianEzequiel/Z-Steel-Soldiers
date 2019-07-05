// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskMove.h"
#include "../games/game.h"
#include "../players/player.h"
#include "../terrains/node.h"
#include "../terrains/paths/nodePath.h"
#include "../states/state.h"
//------------------------------------------------------------------------------
// SERVER TASK MOVE UNIT CONSTRUCTOR
//------------------------------------------------------------------------------
TaskMove::TaskMove(
        Game& aGame, NodePath& nodePath, size_t idUnit):
        Task::Task(aGame), idUnit(idUnit) {
    hasExecuted = false;
    this->nodePath = &nodePath;
    waitingTime = this->nodePath->getCumulativeWaitingTime();
}
//------------------------------------------------------------------------------
// SERVER TASK MOVE UNIT DESTRUCTOR
//------------------------------------------------------------------------------
TaskMove::~TaskMove() {
    if (!hasExecuted) {
        const State* state = nodePath->getState();
        delete state;
    }
    delete nodePath;
}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskMove::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskMove::execute() {
    hasExecuted = true;
    aGame.getUnit(idUnit)->changePosition(nodePath->getNode());
    // printf("waitingTime: %f - ", waitingTime);
    // nodePath->getNode().showNode();
    aGame.getUnit(idUnit)->changeState(*nodePath->getState());
}
//------------------------------------------------------------------------------
