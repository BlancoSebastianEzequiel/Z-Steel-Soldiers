// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include <iostream>
#include "map.h"
#include "../../libs/Exception.h"
#include "../terrains/node.h"
#include "../terrains/lava.h"
#include "../settings/settings.h"
#include "../objects/solids/solids.h"
#include "../objects/flags/flag.h"
#include "../players/player.h"
#include "../territories/territories.h"
#include "../terrains/earth_prairie_snow/dust.h"
#include "../terrains/earth_prairie_snow/grass.h"
#include "../terrains/road_asphalt_road/road.h"
#include "../terrains/road_asphalt_road/asphaltRoad.h"
#include "../terrains/water_swamp/water.h"
#include "../terrains/water_swamp/swamp.h"
#include "../terrains/earth_prairie_snow/snow.h"
#include "../objects/buildings/fort.h"
#include "../objects/buildings/robotFactory.h"
#include "../objects/buildings/vehicleFactory.h"
#include "../objects/bridges/woodenBridge.h"
#include "../objects/bridges/concreteBridge.h"
#include "../objects/solids/iceBlock.h"
#include "../objects/solids/stone.h"
//------------------------------------------------------------------------------
#define NEW_LINE '\n'
#define DELIM '-'
#define DIMENSIONS "dimensions"
#define MATRIX "matrix"
#define TERRITORY "territory"
#define DUST "dust"
#define SNOW "snow"
#define GRASS "grass"
#define LAVA "lava"
#define ROAD "road"
#define ASPHALT_ROAD "asphaltRoad"
#define WATER "water"
#define SWAMP "swamp"
#define OBJECTS "objects"
#define FORT "fort"
#define VEHICLE_FACTORIE "vehicleFactorie"
#define ROBOT_FACTORIE "robotFactorie"
#define WOODEN_BRIDGE "woodenBridge"
#define CONCRETE_BRIDGE "concreteBridge"
#define STONE "stone"
#define ICE_BLOCK "iceBlock"
#define FLAG "flag"
//------------------------------------------------------------------------------
extern Settings settings;
//------------------------------------------------------------------------------
// MAP CONSTRUCTOR
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
// MAP DESTRUCTOR
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
// GET NODE
//------------------------------------------------------------------------------
Node* Map::getNode(uint32_t x, uint32_t y) const {
    if (!belongs(x, y)) throw Exception("(%u, %u) does not belong\n", x, y);
    return gameMap[x][y];
}
//------------------------------------------------------------------------------
// BELONGS
//------------------------------------------------------------------------------
bool Map::belongs(uint32_t x, uint32_t y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}
//------------------------------------------------------------------------------
// BELONGS
//------------------------------------------------------------------------------
bool Map::belongs(const Node& aNode) const {
    return belongs(aNode.x, aNode.y);
}
//------------------------------------------------------------------------------
// GET ADJACENT OF
//------------------------------------------------------------------------------
void Map::addAdjacentTo(Node &aNode) const {
    std::vector<Node*> adjacent;
    //--------------------------------------------------------------------------
    if (belongs(aNode.x-1, aNode.y-1)) {
        adjacent.push_back(getNode(aNode.x-1, aNode.y-1));
    }
    if (belongs(aNode.x-1, aNode.y)) {
        adjacent.push_back(getNode(aNode.x-1, aNode.y));
    }
    if (belongs(aNode.x-1, aNode.y+1)) {
        adjacent.push_back(getNode(aNode.x-1, aNode.y+1));
    }
    //--------------------------------------------------------------------------
    if (belongs(aNode.x+1, aNode.y-1)) {
        adjacent.push_back(getNode(aNode.x+1, aNode.y-1));
    }
    if (belongs(aNode.x+1, aNode.y)) {
        adjacent.push_back(getNode(aNode.x+1, aNode.y));
    }
    if (belongs(aNode.x+1, aNode.y+1)) {
        adjacent.push_back(getNode(aNode.x+1, aNode.y+1));
    }
    //--------------------------------------------------------------------------
    if (belongs(aNode.x, aNode.y-1)) {
        adjacent.push_back(getNode(aNode.x, aNode.y-1));
    }
    if (belongs(aNode.x, aNode.y+1)) {
        adjacent.push_back(getNode(aNode.x, aNode.y+1));
    }
    //--------------------------------------------------------------------------
    aNode.adjacent = adjacent;
}
//------------------------------------------------------------------------------
// GET OBJECTS
//------------------------------------------------------------------------------
objectsMap& Map::getObjects() {
    return objects;
}
//------------------------------------------------------------------------------
// GET OBJECT
//------------------------------------------------------------------------------
Object* Map::getObject(size_t id) {
    return objects[id];
}
//------------------------------------------------------------------------------
// GET BUILDING
//------------------------------------------------------------------------------
Buildings* Map::getBuilding(size_t id) {
    return buildings[id];
}
//------------------------------------------------------------------------------
// GET BRIDGE
//------------------------------------------------------------------------------
Bridges* Map::getBridge(size_t id) {
    return bridges[id];
}
//------------------------------------------------------------------------------
// GET SOLID
//------------------------------------------------------------------------------
Solids* Map::getSolid(size_t id) {
    return solids[id];
}
//------------------------------------------------------------------------------
// GET FLAG
//------------------------------------------------------------------------------
Flag* Map::getFlag(size_t id) {
    return flags[id];
}
//------------------------------------------------------------------------------
// GET TERRAIN
//------------------------------------------------------------------------------
Territories* Map::getTerritory(size_t id) {
    return territories[id];
}
//------------------------------------------------------------------------------
// ADD INITIAL TERRAIN TO PLAYER
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
// GET MAXIMUM NUMBER OF PLAYER
//------------------------------------------------------------------------------
const size_t& Map::getMaximumNumberOfPlayers() const {
    return maximumNumberOfPlayers;
}
//------------------------------------------------------------------------------
// GET MAP MATRIX
//------------------------------------------------------------------------------
const mapMatrix& Map::getMapMatrix() const {
    return gameMap;
}
//------------------------------------------------------------------------------
// GET QUANTITY OF TERRITORIES
//------------------------------------------------------------------------------
size_t Map::getQuantityOfTerritories() const {
    return territories.size();
}
//------------------------------------------------------------------------------
// GET TERRITORIES
//------------------------------------------------------------------------------
const std::vector<Territories*>& Map::getTerritories() {
    return territories.getList();
}
// *****************************************************************************
// ********************************PRIVATE**************************************
// *****************************************************************************
//------------------------------------------------------------------------------
// CREATE STONE
//------------------------------------------------------------------------------
void Map::createStone(Node &position) {
    size_t id = ++objectsQuant;
    Stone* object = new Stone(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    solids(id, object);
}
//------------------------------------------------------------------------------
// CREATE ICE BLOCKS
//------------------------------------------------------------------------------
void Map::createIceBlocks(Node &position) {
    size_t id = ++objectsQuant;
    IceBlock* object = new IceBlock(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    solids(id, object);
}
//------------------------------------------------------------------------------
// CREATE FORT
//------------------------------------------------------------------------------
void Map::createFort(Node &position, size_t tecnologyLevel) {
    maximumQuantityOfPlayers++;
    size_t id = ++objectsQuant;
    // Este new sera destruido en la clase nodo.
    Fort* fort = new Fort(position, id, tecnologyLevel);
    fort->addObjectToNodes(*this);
    //--------------------------------------------------------------------------
    Node* flagPosition;
    flagPosition = fort->getFlagNode();
    size_t idFlag = ++objectsQuant;
    // Este new sera destruido en la clase nodo.
    Flag* flag = new Flag(*flagPosition, idFlag);
    objects(idFlag, flag);
    flags(idFlag, flag);
    fort->addFlag(*flag);
    //--------------------------------------------------------------------------
    objects(id, fort);
    buildings(id, fort);
}
//------------------------------------------------------------------------------
// CREATE ROBOT FACTORIE
//------------------------------------------------------------------------------
void Map::createRobotFactorie(
        Node &position, size_t tecnologyLevel) {
    size_t id = ++objectsQuant;
    RobotFactory* object;
    object = new RobotFactory(position, id, tecnologyLevel);
    object->addObjectToNodes(*this);
    objects(id, object);
    buildings(id, object);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE FACTORIE
//------------------------------------------------------------------------------
void Map::createVehicleFactorie(
        Node &position, size_t tecnologyLevel) {
    size_t id = ++objectsQuant;
    VehicleFactory* object;
    object = new VehicleFactory(position, id, tecnologyLevel);
    object->addObjectToNodes(*this);
    objects(id, object);
    buildings(id, object);
}
//------------------------------------------------------------------------------
// CREATE FLAG
//------------------------------------------------------------------------------
void Map::createFlag(Node& position) {
    size_t id = ++objectsQuant;
    Flag* object = new Flag(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    flags(id, object);
}
//------------------------------------------------------------------------------
// CREATE WOODEN BRIDGE
//------------------------------------------------------------------------------
void Map::createWoodenBridge(Node& position) {
    size_t id = ++objectsQuant;
    WoodenBridge* object = new WoodenBridge(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    bridges(id, object);
}
//------------------------------------------------------------------------------
// CREATE CONCRETE BRIDGE
//------------------------------------------------------------------------------
void Map::createConcreteBridge(Node &position) {
    size_t id = ++objectsQuant;
    ConcreteBridge* object = new ConcreteBridge(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    bridges(id, object);
}
//------------------------------------------------------------------------------
// ADD NODES TO TERRITORY
//------------------------------------------------------------------------------
void Map::addNodesToTerritory(
        parsedLine_t aNode, Territories *aTerritory) {
    uint32_t x = aParser.stringToUint32_t(aNode[0]);
    uint32_t y = aParser.stringToUint32_t(aNode[1]);
    aTerritory->addNode(*getNode(x, y));
}
//------------------------------------------------------------------------------
// ADD OBJECT
//------------------------------------------------------------------------------
void Map::addObject(parsedLine_t object) {
    std::string objectType = object[0];
    Node* position = nullptr;
    if (objectType == FORT) {
        size_t tecnologyLevel = aParser.stringToSize_t(object[1]);
        object.erase(object.begin());
        object.erase(object.begin());
        position = getPosition(object);
        createFort(*position, tecnologyLevel);
    } else if (objectType == VEHICLE_FACTORIE) {
        size_t tecnologyLevel = aParser.stringToSize_t(object[1]);
        object.erase(object.begin());
        object.erase(object.begin());
        position = getPosition(object);
        createVehicleFactorie(*position, tecnologyLevel);
    } else if (objectType == ROBOT_FACTORIE) {
        size_t tecnologyLevel = aParser.stringToSize_t(object[1]);
        object.erase(object.begin());
        object.erase(object.begin());
        position = getPosition(object);
        createRobotFactorie(*position, tecnologyLevel);
    } else if (objectType == STONE) {
        object.erase(object.begin());
        position = getPosition(object);
        createStone(*position);
    } else if (objectType == ICE_BLOCK) {
        object.erase(object.begin());
        position = getPosition(object);
        createIceBlocks(*position);
    } else if (objectType == WOODEN_BRIDGE) {
        object.erase(object.begin());
        position = getPosition(object);
        createWoodenBridge(*position);
    } else if (objectType == CONCRETE_BRIDGE) {
        object.erase(object.begin());
        position = getPosition(object);
        createConcreteBridge(*position);
    } else if (objectType == FLAG) {
        object.erase(object.begin());
        position = getPosition(object);
        createFlag(*position);
    } else {
        throw Exception(
                "THE TYPE OF OBJECT: '%s' DOES NOT EXIST", objectType.c_str());
    }
}
//------------------------------------------------------------------------------
// CREATE NODE
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
// CREATE MAP DIMENSIONS
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
// CREATE NEW TERRITORY
//------------------------------------------------------------------------------
Territories* Map::createNewTerritory() {
    size_t id = territories.size() + 1;
    Territories* aTerritory = new Territories(id);
    territories(id, aTerritory);
    return aTerritory;
}
//------------------------------------------------------------------------------
// GET BUILDING POSITIONS
//------------------------------------------------------------------------------
Node* Map::getPosition(const parsedLine_t& object) {
    uint32_t x = aParser.stringToUint32_t(object[0]);;
    uint32_t y = aParser.stringToUint32_t(object[1]);
    return getNode(x, y);
}
//------------------------------------------------------------------------------
// ADD ADJACENTS TO ALL NODES
//------------------------------------------------------------------------------
void Map::addAdjacentToAllNodes() {
    if (adjacentsAdded) return;
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {
            gameMap[x][y]->addAdjacent(*this);
        }
    }
    adjacentsAdded = true;
}
//------------------------------------------------------------------------------
