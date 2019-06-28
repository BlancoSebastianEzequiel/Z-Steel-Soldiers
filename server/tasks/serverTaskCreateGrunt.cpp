// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <iostream>
#include "serverTaskCreateGrunt.h"
#include "../games/serverGame.h"
#include "../objects/buildings/serverBuildings.h"
#include "../players/serverPlayer.h"
#include "../terrains/serverNode.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE GRUNT CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreateGrunt::ServerTaskCreateGrunt(ServerGame& aGame, size_t idBuilding):
        ServerTask::ServerTask(aGame), idBuilding(idBuilding) {
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->GruntManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE GRUNT DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreateGrunt::~ServerTaskCreateGrunt() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool ServerTaskCreateGrunt::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void ServerTaskCreateGrunt::execute() {
    size_t id = ++aGame.unitsQuant;
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    ServerPlayer* owner = (ServerPlayer *)building->getOwner();
    owner->createRobotGrunt(x, y, id);
    ServerUnit* newUnit =  owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------
