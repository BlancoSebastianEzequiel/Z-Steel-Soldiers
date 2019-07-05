// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskCreateLightTank.h"
#include "../games/game.h"
#include "../objects/buildings/buildings.h"
#include "../players/player.h"
#include "../terrains/node.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE LIGHT TANK CONSTRUCTOR
//------------------------------------------------------------------------------
TaskCreateLightTank::TaskCreateLightTank(
        Game& aGame, size_t idBuilding):
        Task::Task(aGame), idBuilding(idBuilding) {
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->LightTankManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE LIGHT TANK DESTRUCTOR
//------------------------------------------------------------------------------
TaskCreateLightTank::~TaskCreateLightTank() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskCreateLightTank::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskCreateLightTank::execute() {
    size_t id = ++aGame.unitsQuant;
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    Player* owner = (Player *)building->getOwner();
    owner->createVehicleLightTank(x, y, id);
    Unit* newUnit =  owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------
