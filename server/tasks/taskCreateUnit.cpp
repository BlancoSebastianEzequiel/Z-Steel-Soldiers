#include <iostream>
#include "taskCreateUnit.h"
#include "../games/game.h"
#include "../objects/object.h"
#include "../players/player.h"
#include "../terrains/node.h"

TaskCreateUnit::TaskCreateUnit(
        Game &aGame, size_t idBuilding, size_t type):
        Task::Task(aGame), idBuilding(idBuilding), type(type) {
    Object* building = aGame.gameMap.getObject(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->manufacturingTime(takenTerritories, type);
}

TaskCreateUnit::~TaskCreateUnit() {}

bool TaskCreateUnit::isRelocable() const {
    return false;
}

void TaskCreateUnit::execute() {
    size_t unitId = ++aGame.unitsQuant;
    Object* building = aGame.gameMap.getObject(idBuilding);
    uint32_t x = building->getWalkableNode()->x;
    uint32_t y = building->getWalkableNode()->y;
    auto* owner = (Player *)building->getOwner();
    owner->createUnit(x, y, unitId, type);
    Unit* newUnit =  owner->getUnit(unitId);
    aGame.addNewUnit(unitId, newUnit);
}
