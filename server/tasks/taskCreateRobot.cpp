#include <iostream>
#include "taskCreateRobot.h"
#include "../games/game.h"
#include "../objects/buildings/buildings.h"
#include "../players/player.h"
#include "../terrains/node.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE GRUNT CONSTRUCTOR
//------------------------------------------------------------------------------
TaskCreateRobot::TaskCreateRobot(
        Game &aGame, size_t idBuilding, size_t type):
        Task::Task(aGame), idBuilding(idBuilding), type(type) {
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->GruntManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE GRUNT DESTRUCTOR
//------------------------------------------------------------------------------
TaskCreateRobot::~TaskCreateRobot() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskCreateRobot::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskCreateRobot::execute() {
    size_t id = ++aGame.unitsQuant;
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    auto* owner = (Player *)building->getOwner();
    owner->createRobot(x, y, id, type);
    Unit* newUnit =  owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------