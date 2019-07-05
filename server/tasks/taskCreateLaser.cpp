// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "taskCreateLaser.h"
#include "../games/game.h"
#include "../objects/buildings/buildings.h"
#include "../players/player.h"
#include "../terrains/node.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE LASER CONSTRUCTOR
//------------------------------------------------------------------------------
TaskCreateLaser::TaskCreateLaser(Game& aGame, size_t idBuilding):
        Task::Task(aGame), idBuilding(idBuilding) {
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->LaserManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE LASER DESTRUCTOR
//------------------------------------------------------------------------------
TaskCreateLaser::~TaskCreateLaser() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool TaskCreateLaser::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void TaskCreateLaser::execute() {
    size_t id = ++aGame.unitsQuant;
    Buildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    Player* owner = (Player *)building->getOwner();
    owner->createRobotLaser(x, y, id);
    Unit* newUnit = owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------
