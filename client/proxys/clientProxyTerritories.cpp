// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include "clientProxyTerritories.h"
#include "clientProxyNode.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// SERVER TERRAIN CONSTRUCTOR
//------------------------------------------------------------------------------
ClientProxyTerritories::ClientProxyTerritories(const size_t id): id(id) {}
//------------------------------------------------------------------------------
// SERVER TERRAIN DESTRUCTOR
//------------------------------------------------------------------------------
ClientProxyTerritories::~ClientProxyTerritories() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ClientProxyTerritories::operator==(
        const ClientProxyTerritories& otherTerritory) {
    return id == otherTerritory.getId();
}
//------------------------------------------------------------------------------
// ADD NODE
//------------------------------------------------------------------------------
void ClientProxyTerritories::addNode(ClientProxyNode& aNode) {
    aNode.addTerritory(*this);
    nodes.push_back(&aNode);
}
//------------------------------------------------------------------------------
// GET NODES
//------------------------------------------------------------------------------
std::vector<ClientProxyNode*>& ClientProxyTerritories::getNodes(){
    return nodes;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ClientProxyTerritories::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// CHANGE PLAYER
//------------------------------------------------------------------------------
void ClientProxyTerritories::changePlayer(size_t newOwnerId) {
    ownerId = newOwnerId;
}
//------------------------------------------------------------------------------
// GET PLAYER
//------------------------------------------------------------------------------
const size_t& ClientProxyTerritories::getOwnerId() const {
    return ownerId;
}
//------------------------------------------------------------------------------
