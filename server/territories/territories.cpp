#include <vector>
#include "territories.h"
#include "../terrains/node.h"
#include "../objects/object.h"
#include "../players/player.h"

Territories::Territories(const size_t id): id(id) {
    player = nullptr;
}

Territories::~Territories() {}

void Territories::addNode(Node &aNode) {
    aNode.addTerritory(*this);
    nodes.push_back(&aNode);
}

std::vector<Node*>& Territories::getNodes(){
    return nodes;
}

const size_t& Territories::getId() const {
    return id;
}

void Territories::changePlayer(Player& aPlayer) {
    if (hasAPlayer()) player->deleteTerritory(id);
    player = &aPlayer;
    player->addTerritory(*this);
}

bool Territories::hasAFort() const {
    for (const Node* aNode : nodes) {
        if (!aNode->hasAGroundObject()) continue;
        if (!aNode->getGroundObject()->isFort()) continue;
        return true;
    }
    return false;
}

Object* Territories::getBuilding() const {
    for (const Node* aNode : nodes) {
        if (!aNode->hasAGroundObject()) continue;
        if (!aNode->getGroundObject()->isFort()) continue;
        auto* object = (Object*) aNode->getGroundObject();
        return object;
    }
    return nullptr;
}

bool Territories::hasAPlayer() const {
    return player != nullptr;
}

const Player* Territories::getOwner() const {
    return player;
}
