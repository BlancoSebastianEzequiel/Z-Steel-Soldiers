// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include "serverTerritories.h"
#include "../terrains/serverNode.h"
#include "../objects/serverObject.h"
#include "../players/serverPlayer.h"
#include "../objects/flags/serverFlag.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// SERVER TERRAIN CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTerritories::ServerTerritories(const size_t id): id(id) {
    player = nullptr;
}
//------------------------------------------------------------------------------
// SERVER TERRAIN DESTRUCTOR
//------------------------------------------------------------------------------
ServerTerritories::~ServerTerritories() {}
//------------------------------------------------------------------------------
// ADD NODE
//------------------------------------------------------------------------------
void ServerTerritories::addNode(ServerNode &aNode) {
    aNode.addTerritory(*this);
    nodes.push_back(&aNode);
}
//------------------------------------------------------------------------------
// GET NODES
//------------------------------------------------------------------------------
std::vector<ServerNode*>& ServerTerritories::getNodes(){
    return nodes;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ServerTerritories::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// ADD PLAYER
//------------------------------------------------------------------------------
void ServerTerritories::changePlayer(ServerPlayer& aPlayer) {
    if (hasAPlayer()) player->deleteTerritory(id);
    player = &aPlayer;
    player->addTerritory(*this);
}
//------------------------------------------------------------------------------
// HAS A FORT
//------------------------------------------------------------------------------
bool ServerTerritories::hasAFort() const {
    for (const ServerNode* aNode : nodes) {
        if (!aNode->hasAGroundObject()) continue;
        if (!aNode->getGroundObject()->isFort()) continue;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
// GET BUILDING
//------------------------------------------------------------------------------
ServerBuildings* ServerTerritories::getBuilding() const {
    for (const ServerNode* aNode : nodes) {
        if (!aNode->hasAGroundObject()) continue;
        if (!aNode->getGroundObject()->isFort()) continue;
        return (ServerBuildings*)aNode->getGroundObject();
    }
    return nullptr;
}
//------------------------------------------------------------------------------
//  HAS A PLAYER
//------------------------------------------------------------------------------
bool ServerTerritories::hasAPlayer() const {
    return player != nullptr;
}
//------------------------------------------------------------------------------
// GET PLAYER
//------------------------------------------------------------------------------
const ServerPlayer* ServerTerritories::getOwner() const {
    return player;
}
//------------------------------------------------------------------------------
