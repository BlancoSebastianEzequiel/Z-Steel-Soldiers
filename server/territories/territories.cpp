// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include "territories.h"
#include "../terrains/node.h"
#include "../objects/object.h"
#include "../players/player.h"
#include "../objects/flags/flag.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// SERVER TERRAIN CONSTRUCTOR
//------------------------------------------------------------------------------
Territories::Territories(const size_t id): id(id) {
    player = nullptr;
}
//------------------------------------------------------------------------------
// SERVER TERRAIN DESTRUCTOR
//------------------------------------------------------------------------------
Territories::~Territories() {}
//------------------------------------------------------------------------------
// ADD NODE
//------------------------------------------------------------------------------
void Territories::addNode(Node &aNode) {
    aNode.addTerritory(*this);
    nodes.push_back(&aNode);
}
//------------------------------------------------------------------------------
// GET NODES
//------------------------------------------------------------------------------
std::vector<Node*>& Territories::getNodes(){
    return nodes;
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
const size_t& Territories::getId() const {
    return id;
}
//------------------------------------------------------------------------------
// ADD PLAYER
//------------------------------------------------------------------------------
void Territories::changePlayer(Player& aPlayer) {
    if (hasAPlayer()) player->deleteTerritory(id);
    player = &aPlayer;
    player->addTerritory(*this);
}
//------------------------------------------------------------------------------
// HAS A FORT
//------------------------------------------------------------------------------
bool Territories::hasAFort() const {
    for (const Node* aNode : nodes) {
        if (!aNode->hasAGroundObject()) continue;
        if (!aNode->getGroundObject()->isFort()) continue;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
// GET BUILDING
//------------------------------------------------------------------------------
Buildings* Territories::getBuilding() const {
    for (const Node* aNode : nodes) {
        if (!aNode->hasAGroundObject()) continue;
        if (!aNode->getGroundObject()->isFort()) continue;
        return (Buildings*)aNode->getGroundObject();
    }
    return nullptr;
}
//------------------------------------------------------------------------------
//  HAS A PLAYER
//------------------------------------------------------------------------------
bool Territories::hasAPlayer() const {
    return player != nullptr;
}
//------------------------------------------------------------------------------
// GET PLAYER
//------------------------------------------------------------------------------
const Player* Territories::getOwner() const {
    return player;
}
//------------------------------------------------------------------------------
