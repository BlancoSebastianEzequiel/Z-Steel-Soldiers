// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverTaskCreateMediumTank.h"
#include "../games/serverGame.h"
#include "../objects/buildings/serverBuildings.h"
#include "../players/serverPlayer.h"
#include "../terrains/serverNode.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE MEDIUM TANK CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreateMediumTank::ServerTaskCreateMediumTank(
        ServerGame& aGame, size_t idBuilding):
        ServerTask::ServerTask(aGame), idBuilding(idBuilding) {
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->MediumTankManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE MEDIUM TANK DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreateMediumTank::~ServerTaskCreateMediumTank() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool ServerTaskCreateMediumTank::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void ServerTaskCreateMediumTank::execute() {
    size_t id = ++aGame.unitsQuant;
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    ServerPlayer* owner = (ServerPlayer *)building->getOwner();
    owner->createVehicleMediumTank(x, y, id);
    ServerUnit* newUnit =  owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------
