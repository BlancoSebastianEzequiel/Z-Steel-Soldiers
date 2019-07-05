// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskCreatePyro.h"
#include "../games/game.h"
#include "../objects/buildings/buildings.h"
#include "../players/player.h"
#include "../terrains/node.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE PYRO CONSTRUCTOR
//------------------------------------------------------------------------------
TaskCreatePyro::TaskCreatePyro(Game& aGame, size_t idBuilding):
        Task::Task(aGame), idBuilding(idBuilding) {
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->PyroManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE PYRO DESTRUCTOR
//------------------------------------------------------------------------------
TaskCreatePyro::~TaskCreatePyro() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskCreatePyro::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskCreatePyro::execute() {
    size_t id = ++aGame.unitsQuant;
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    Player* owner = (Player *)building->getOwner();
    owner->createRobotPyro(x, y, id);
    Unit* newUnit =  owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------
