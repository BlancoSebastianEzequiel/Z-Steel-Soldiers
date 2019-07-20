#include <vector>
#include <string>
#include <iostream>
#include "map.h"
#include "../../libs/Exception.h"
#include "../settings/settings.h"
#include "../players/player.h"
#include "../territories/territories.h"
#include "../terrains/node.h"
#include "../terrains/lava.h"
#include "../terrains/earth_prairie_snow/dust.h"
#include "../terrains/earth_prairie_snow/grass.h"
#include "../terrains/road_asphalt_road/road.h"
#include "../terrains/road_asphalt_road/asphaltRoad.h"
#include "../terrains/water_swamp/water.h"
#include "../terrains/water_swamp/swamp.h"
#include "../terrains/earth_prairie_snow/snow.h"
#include "../objects/object.h"
#include "../../libs/definitions.h"

extern Settings settings;

Map::Map(char* mapFileName) {
    maximumQuantityOfPlayers = 0;
    objectsQuant = 0;
    adjacentsAdded = false;
    fileParsed parsedFile = aParser.parseFile(mapFileName, NEW_LINE, DELIM);
    std::string command;
    Territories* aTerritory = nullptr;
    for (parsedLine_t line : parsedFile) {
        if (line.size() == 1) {
            command = line[0];
            if (command == TERRITORY) {
                aTerritory = createNewTerritory();
            }
            continue;
        }
        if (command == DIMENSIONS) setDimensions(line);
        if (command == MATRIX) createNode(line);
        if (command == OBJECTS) {
            addAdjacentToAllNodes();
            addObject(line);
        }
        if (command == TERRITORY) addNodesToTerritory(line, aTerritory);
    }
}

Map::~Map() {
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {
            delete gameMap[x][y];
        }
    }
    for (Territories* aTerritory : territories.getList()) {
        delete aTerritory;
    }
    for (Object* anObject : objects.getList()) {
        delete anObject;
    }
}

Node* Map::getNode(uint32_t x, uint32_t y) const {
    if (!belongs(x, y)) throw Exception("(%u, %u) does not belong\n", x, y);
    return gameMap[x][y];
}

bool Map::belongs(uint32_t x, uint32_t y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void Map::addAdjacentTo(Node &aNode) const {
    std::vector<Node*> adjacent;
    if (belongs(aNode.x-1, aNode.y-1)) {
        adjacent.push_back(getNode(aNode.x-1, aNode.y-1));
    }
    if (belongs(aNode.x-1, aNode.y)) {
        adjacent.push_back(getNode(aNode.x-1, aNode.y));
    }
    if (belongs(aNode.x-1, aNode.y+1)) {
        adjacent.push_back(getNode(aNode.x-1, aNode.y+1));
    }
    if (belongs(aNode.x+1, aNode.y-1)) {
        adjacent.push_back(getNode(aNode.x+1, aNode.y-1));
    }
    if (belongs(aNode.x+1, aNode.y)) {
        adjacent.push_back(getNode(aNode.x+1, aNode.y));
    }
    if (belongs(aNode.x+1, aNode.y+1)) {
        adjacent.push_back(getNode(aNode.x+1, aNode.y+1));
    }
    if (belongs(aNode.x, aNode.y-1)) {
        adjacent.push_back(getNode(aNode.x, aNode.y-1));
    }
    if (belongs(aNode.x, aNode.y+1)) {
        adjacent.push_back(getNode(aNode.x, aNode.y+1));
    }
    aNode.adjacent = adjacent;
}

objectsMap& Map::getObjects() {
    return objects;
}

Object* Map::getObject(size_t id) {
    return objects[id];
}

Buildings* Map::getBuilding(size_t id) {
    return buildings[id];
}

Territories* Map::getTerritory(size_t id) {
    return territories[id];
}

void Map::addInitialTerritoryToPlayer(Player& aPlayer) {
    for (Territories* aTerritory: territories.getList()) {
        if (!aTerritory->hasAFort()) continue;
        if (aTerritory->hasAPlayer()) continue;
        aTerritory->changePlayer(aPlayer);
        return;
    }
    size_t playerId = aPlayer.getId();
    throw Exception("could not find a territory for player %d", playerId);
}

const std::vector<Territories*>& Map::getTerritories() {
    return territories.getList();
}

void Map::createObject(Node &position, size_t type, const object_t &attr) {
    size_t id = ++objectsQuant;
    auto* object = new Object(position, id, type);
    object->addObjectToNodes();
    object->addAttributes(attr, *this);
    objects(id, object);
}

void Map::addNodesToTerritory(
        parsedLine_t aNode, Territories *aTerritory) {
    uint32_t x = aParser.stringToUint32_t(aNode[0]);
    uint32_t y = aParser.stringToUint32_t(aNode[1]);
    aTerritory->addNode(*getNode(x, y));
}

void Map::addObject(parsedLine_t object) {
    std::string objectType = object[0];
    Node* position = nullptr;
    size_t type = objectsNames.at(objectType);
    object_t attributes;
    if (object.size() == 4) {
        attributes("techLevel", aParser.stringToSize_t(object[3]));
    }
    position = getPosition(object);
    createObject(*position, type, attributes);
}

void Map::createNode(parsedLine_t node) {
    uint32_t x = aParser.stringToUint32_t(node[0]);
    uint32_t y = aParser.stringToUint32_t(node[1]);
    std::string nodeType = node[2];
    if (nodeType == DUST) {
        gameMap[x][y] = new Dust(x, y);
    } else if (nodeType == SNOW) {
        gameMap[x][y] = new Snow(x, y);
    } else if (nodeType == GRASS) {
        gameMap[x][y] = new Grass(x, y);
    } else if (nodeType == LAVA) {
        gameMap[x][y] = new Lava(x, y);
    } else if (nodeType == ROAD) {
        gameMap[x][y] = new Road(x, y);
    } else if (nodeType == ASPHALT_ROAD) {
        gameMap[x][y] = new AsphaltRoad(x, y);
    } else if (nodeType == WATER) {
        gameMap[x][y] = new Water(x, y);
    } else if (nodeType == SWAMP) {
        gameMap[x][y] = new Swamp(x, y);
    } else {
        throw Exception(
                "THE TYPE OF NODE: '%s' DOES NOT EXIST", nodeType.c_str());
    }
}

void Map::setDimensions(parsedLine_t dimensions) {
    width = aParser.stringToUint32_t(dimensions[0]);
    height = aParser.stringToUint32_t(dimensions[1]);
    gameMap.reserve(width);
    for (uint32_t x = 0; x < width; x++) {
        std::vector<Node *> vecY;
        vecY.reserve(height);
        for (uint32_t y = 0; y < height; y++) {
            vecY.push_back(nullptr);
        }
        gameMap.push_back(vecY);
    }
}

Territories* Map::createNewTerritory() {
    size_t id = territories.size() + 1;
    auto* aTerritory = new Territories(id);
    territories(id, aTerritory);
    return aTerritory;
}

Node* Map::getPosition(const parsedLine_t& object) {
    uint32_t x = aParser.stringToUint32_t(object[1]);
    uint32_t y = aParser.stringToUint32_t(object[2]);
    return getNode(x, y);
}

void Map::addAdjacentToAllNodes() {
    if (adjacentsAdded) return;
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {
            gameMap[x][y]->addAdjacent(*this);
        }
    }
    adjacentsAdded = true;
}

size_t Map::getNewObjectId() {
    objectsQuant++;
    return objectsQuant;
}

void Map::addObject(Object *anObject) {
    objects(anObject->getId(), anObject);
}
