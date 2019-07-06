// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include "proxyTerritories.h"
#include "proxyNode.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// SERVER TERRAIN CONSTRUCTOR
//------------------------------------------------------------------------------
ProxyTerritories::ProxyTerritories(const size_t id): id(id) {}
//------------------------------------------------------------------------------
// SERVER TERRAIN DESTRUCTOR
//------------------------------------------------------------------------------
ProxyTerritories::~ProxyTerritories() {}
//------------------------------------------------------------------------------
// OPERATOR ==
//------------------------------------------------------------------------------
bool ProxyTerritories::operator==(
        const ProxyTerritories& otherTerritory) {
    return id == otherTerritory.getId();
}
//------------------------------------------------------------------------------
// ADD NODE
//------------------------------------------------------------------------------
void ProxyTerritories::addNode(ProxyNode& aNode) {
    aNode.addTerritory(*this);
    nodes.push_back(&aNode);
}
//------------------------------------------------------------------------------
// GET NODES
//------------------------------------------------------------------------------
std::vector<ProxyNode*>& ProxyTerritories::getNodes(){
    return nodes;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& ProxyTerritories::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// CHANGE PLAYER
//------------------------------------------------------------------------------
void ProxyTerritories::changePlayer(size_t newOwnerId) {
    ownerId = newOwnerId;
}
//------------------------------------------------------------------------------
// GET PLAYER
//------------------------------------------------------------------------------
const size_t& ProxyTerritories::getOwnerId() const {
    return ownerId;
}
//------------------------------------------------------------------------------