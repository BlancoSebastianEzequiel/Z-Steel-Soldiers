// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverTaskCreatePsycho.h"
#include "../games/serverGame.h"
#include "../objects/buildings/serverBuildings.h"
#include "../players/serverPlayer.h"
#include "../terrains/serverNode.h"
//------------------------------------------------------------------------------
// SERVER TASK CREATE PSYCHO CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreatePsycho::ServerTaskCreatePsycho(ServerGame& aGame, size_t idBuilding):
        ServerTask::ServerTask(aGame), idBuilding(idBuilding) {
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    size_t takenTerritories = building->getOwner()->getTakenTerritories();
    waitingTime = building->PsychoManufacturingTime(takenTerritories);
}
//------------------------------------------------------------------------------
// SERVER TASK CREATE PSYCHO DESTRUCTOR
//------------------------------------------------------------------------------
ServerTaskCreatePsycho::~ServerTaskCreatePsycho() {}
//------------------------------------------------------------------------------
// IS RELOCABLE
//------------------------------------------------------------------------------
bool ServerTaskCreatePsycho::isRelocable() const {
    return false;
}
//------------------------------------------------------------------------------
// EXECUTE
//------------------------------------------------------------------------------
void ServerTaskCreatePsycho::execute() {
    size_t id = ++aGame.unitsQuant;
    ServerBuildings* building = aGame.gameMap.getBuilding(idBuilding);
    uint32_t x = building->getCreationPosition()->x;
    uint32_t y = building->getCreationPosition()->y;
    ServerPlayer* owner = (ServerPlayer *)building->getOwner();
    owner->createRobotPsycho(x, y, id);
    ServerUnit* newUnit = owner->getUnit(id);
    aGame.addNewUnit(id, newUnit);
}
//------------------------------------------------------------------------------
