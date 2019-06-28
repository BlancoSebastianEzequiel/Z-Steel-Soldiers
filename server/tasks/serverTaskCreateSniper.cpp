// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverTaskCreateSniper.h"
#include "../games/serverGame.h"
#include "../objects/buildings/serverBuildings.h"
#include "../players/serverPlayer.h"
#include "../terrains/serverNode.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE SNIPER CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreateSniper::ServerTaskCreateSniper(ServerGame& aGame, size_t idBuilding):
        ServerTask::ServerTask(aGame), idBuilding(idBuilding) {
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->SniperManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE SNIPER DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreateSniper::~ServerTaskCreateSniper() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool ServerTaskCreateSniper::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void ServerTaskCreateSniper::execute() {
    size_t id = ++aGame.unitsQuant;
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    ServerPlayer* owner = (ServerPlayer *)building->getOwner();
    owner->createRobotSniper(x, y, id);
    ServerUnit* newUnit =  owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------
