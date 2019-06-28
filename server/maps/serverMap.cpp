// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include <iostream>
#include "serverMap.h"
#include "../../libs/Exception.h"
#include "../terrains/serverNode.h"
#include "../terrains/serverLava.h"
#include "../settings/serverSettings.h"
#include "../objects/solids/serverSolids.h"
#include "../objects/flags/serverFlag.h"
#include "../players/serverPlayer.h"
#include "../territories/serverTerritories.h"
#include "../terrains/earth_prairie_snow/serverDust.h"
#include "../terrains/earth_prairie_snow/serverGrass.h"
#include "../terrains/road_asphalt_road/serverRoad.h"
#include "../terrains/road_asphalt_road/serverAsphaltRoad.h"
#include "../terrains/water_swamp/serverWater.h"
#include "../terrains/water_swamp/serverSwamp.h"
#include "../terrains/earth_prairie_snow/serverSnow.h"
#include "../objects/buildings/serverFort.h"
#include "../objects/buildings/serverRobotFactorie.h"
#include "../objects/buildings/serverVehicleFactorie.h"
#include "../objects/bridges/serverWoodenBridge.h"
#include "../objects/bridges/serverConcreteBridge.h"
#include "../objects/solids/serverIceBlock.h"
#include "../objects/solids/serverStone.h"
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
ServerMap::ServerMap(char* mapFileName) {
    maximumQuantityOfPlayers = 0;
    objectsQuant = 0;
    adjacentsAdded = false;
    fileParsed parsedFile = aParser.parseFile(mapFileName, NEW_LINE, DELIM);
    std::string command;
    ServerTerritories* aTerritory = nullptr;
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
ServerMap::~ServerMap() {
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {
            delete gameMap[x][y];
        }
    }
    for (ServerTerritories* aTerritory : territories.getList()) {
        delete aTerritory;
    }
    for (ServerObject* anObject : objects.getList()) {
        delete anObject;
    }
}
//------------------------------------------------------------------------------
// GET NODE
//------------------------------------------------------------------------------
ServerNode* ServerMap::getNode(uint32_t x, uint32_t y) const {
    if (!belongs(x, y)) throw Exception("(%u, %u) does not belong\n", x, y);
    return gameMap[x][y];
}
//------------------------------------------------------------------------------
// BELONGS
//------------------------------------------------------------------------------
bool ServerMap::belongs(uint32_t x, uint32_t y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}
//------------------------------------------------------------------------------
// BELONGS
//------------------------------------------------------------------------------
bool ServerMap::belongs(const ServerNode& aNode) const {
    return belongs(aNode.x, aNode.y);
}
//------------------------------------------------------------------------------
// GET ADJACENT OF
//------------------------------------------------------------------------------
void ServerMap::addAdjacentTo(ServerNode &aNode) const {
    std::vector<ServerNode*> adjacent;
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
objectsMap& ServerMap::getObjects() {
    return objects;
}
//------------------------------------------------------------------------------
// GET OBJECT
//------------------------------------------------------------------------------
ServerObject* ServerMap::getObject(size_t id) {
    return objects[id];
}
//------------------------------------------------------------------------------
// GET BUILDING
//------------------------------------------------------------------------------
ServerBuildings* ServerMap::getBuilding(size_t id) {
    return buildings[id];
}
//------------------------------------------------------------------------------
// GET BRIDGE
//------------------------------------------------------------------------------
ServerBridges* ServerMap::getBridge(size_t id) {
    return bridges[id];
}
//------------------------------------------------------------------------------
// GET SOLID
//------------------------------------------------------------------------------
ServerSolids* ServerMap::getSolid(size_t id) {
    return solids[id];
}
//------------------------------------------------------------------------------
// GET FLAG
//------------------------------------------------------------------------------
ServerFlag* ServerMap::getFlag(size_t id) {
    return flags[id];
}
//------------------------------------------------------------------------------
// GET TERRAIN
//------------------------------------------------------------------------------
ServerTerritories* ServerMap::getTerritory(size_t id) {
    return territories[id];
}
//------------------------------------------------------------------------------
// ADD INITIAL TERRAIN TO PLAYER
//------------------------------------------------------------------------------
void ServerMap::addInitialTerritoryToPlayer(ServerPlayer& aPlayer) {
    for (ServerTerritories* aTerritory : territories.getList()) {
        if (!aTerritory->hasAFort()) continue;
        if (aTerritory->hasAPlayer()) continue;
        aTerritory->changePlayer(aPlayer);
        return;
    }
}
//------------------------------------------------------------------------------
// GET MAXIMUM NUMBER OF PLAYER
//------------------------------------------------------------------------------
const size_t& ServerMap::getMaximumNumberOfPlayers() const {
    return maximumNumberOfPlayers;
}
//------------------------------------------------------------------------------
// GET MAP MATRIX
//------------------------------------------------------------------------------
const mapMatrix& ServerMap::getMapMatrix() const {
    return gameMap;
}
//------------------------------------------------------------------------------
// GET QUANTITY OF TERRITORIES
//------------------------------------------------------------------------------
size_t ServerMap::getQuantityOfTerritories() const {
    return territories.size();
}
//------------------------------------------------------------------------------
// GET TERRITORIES
//------------------------------------------------------------------------------
const std::vector<ServerTerritories*>& ServerMap::getTerritories() {
    return territories.getList();
}
// *****************************************************************************
// ********************************PRIVATE**************************************
// *****************************************************************************
//------------------------------------------------------------------------------
// CREATE STONE
//------------------------------------------------------------------------------
void ServerMap::createStone(ServerNode &position) {
    size_t id = ++objectsQuant;
    ServerStone* object = new ServerStone(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    solids(id, object);
}
//------------------------------------------------------------------------------
// CREATE ICE BLOCKS
//------------------------------------------------------------------------------
void ServerMap::createIceBlocks(ServerNode &position) {
    size_t id = ++objectsQuant;
    ServerIceBlock* object = new ServerIceBlock(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    solids(id, object);
}
//------------------------------------------------------------------------------
// CREATE FORT
//------------------------------------------------------------------------------
void ServerMap::createFort(ServerNode &position, size_t tecnologyLevel) {
    maximumQuantityOfPlayers++;
    size_t id = ++objectsQuant;
    // Este new sera destruido en la clase nodo.
    ServerFort* fort = new ServerFort(position, id, tecnologyLevel);
    fort->addObjectToNodes(*this);
    //--------------------------------------------------------------------------
    ServerNode* flagPosition;
    flagPosition = fort->getFlagNode();
    size_t idFlag = ++objectsQuant;
    // Este new sera destruido en la clase nodo.
    ServerFlag* flag = new ServerFlag(*flagPosition, idFlag);
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
void ServerMap::createRobotFactorie(
        ServerNode &position, size_t tecnologyLevel) {
    size_t id = ++objectsQuant;
    ServerRobotFactorie* object;
    object = new ServerRobotFactorie(position, id, tecnologyLevel);
    object->addObjectToNodes(*this);
    objects(id, object);
    buildings(id, object);
}
//------------------------------------------------------------------------------
// CREATE VEHICLE FACTORIE
//------------------------------------------------------------------------------
void ServerMap::createVehicleFactorie(
        ServerNode &position, size_t tecnologyLevel) {
    size_t id = ++objectsQuant;
    ServerVehicleFactorie* object;
    object = new ServerVehicleFactorie(position, id, tecnologyLevel);
    object->addObjectToNodes(*this);
    objects(id, object);
    buildings(id, object);
}
//------------------------------------------------------------------------------
// CREATE FLAG
//------------------------------------------------------------------------------
void ServerMap::createFlag(ServerNode& position) {
    size_t id = ++objectsQuant;
    ServerFlag* object = new ServerFlag(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    flags(id, object);
}
//------------------------------------------------------------------------------
// CREATE WOODEN BRIDGE
//------------------------------------------------------------------------------
void ServerMap::createWoodenBridge(ServerNode& position) {
    size_t id = ++objectsQuant;
    ServerWoodenBridge* object = new ServerWoodenBridge(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    bridges(id, object);
}
//------------------------------------------------------------------------------
// CREATE CONCRETE BRIDGE
//------------------------------------------------------------------------------
void ServerMap::createConcreteBridge(ServerNode &position) {
    size_t id = ++objectsQuant;
    ServerConcreteBridge* object = new ServerConcreteBridge(position, id);
    object->addObjectToNodes(*this);
    objects(id, object);
    bridges(id, object);
}
//------------------------------------------------------------------------------
// ADD NODES TO TERRITORY
//------------------------------------------------------------------------------
void ServerMap::addNodesToTerritory(
        parsedLine_t aNode, ServerTerritories *aTerritory) {
    uint32_t x = aParser.stringToUint32_t(aNode[0]);
    uint32_t y = aParser.stringToUint32_t(aNode[1]);
    aTerritory->addNode(*getNode(x, y));
}
//------------------------------------------------------------------------------
// ADD OBJECT
//------------------------------------------------------------------------------
void ServerMap::addObject(parsedLine_t object) {
    std::string objectType = object[0];
    ServerNode* position = nullptr;
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
void ServerMap::createNode(parsedLine_t node) {
    uint32_t x = aParser.stringToUint32_t(node[0]);
    uint32_t y = aParser.stringToUint32_t(node[1]);
    std::string nodeType = node[2];
    if (nodeType == DUST) {
        gameMap[x][y] = new ServerDust(x, y);
    } else if (nodeType == SNOW) {
        gameMap[x][y] = new ServerSnow(x, y);
    } else if (nodeType == GRASS) {
        gameMap[x][y] = new ServerGrass(x, y);
    } else if (nodeType == LAVA) {
        gameMap[x][y] = new ServerLava(x, y);
    } else if (nodeType == ROAD) {
        gameMap[x][y] = new ServerRoad(x, y);
    } else if (nodeType == ASPHALT_ROAD) {
        gameMap[x][y] = new ServerAsphaltRoad(x, y);
    } else if (nodeType == WATER) {
        gameMap[x][y] = new ServerWater(x, y);
    } else if (nodeType == SWAMP) {
        gameMap[x][y] = new ServerSwamp(x, y);
    } else {
        throw Exception(
                "THE TYPE OF NODE: '%s' DOES NOT EXIST", nodeType.c_str());
    }
}
//------------------------------------------------------------------------------
// CREATE MAP DIMENSIONS
//------------------------------------------------------------------------------
void ServerMap::setDimensions(parsedLine_t dimensions) {
    width = aParser.stringToUint32_t(dimensions[0]);
    height = aParser.stringToUint32_t(dimensions[1]);
    gameMap.reserve(width);
    for (uint32_t x = 0; x < width; x++) {
        std::vector<ServerNode *> vecY;
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
ServerTerritories* ServerMap::createNewTerritory() {
    size_t id = territories.size() + 1;
    ServerTerritories* aTerritory = new ServerTerritories(id);
    territories(id, aTerritory);
    return aTerritory;
}
//------------------------------------------------------------------------------
// GET BUILDING POSITIONS
//------------------------------------------------------------------------------
ServerNode* ServerMap::getPosition(const parsedLine_t& object) {
    uint32_t x = aParser.stringToUint32_t(object[0]);;
    uint32_t y = aParser.stringToUint32_t(object[1]);
    return getNode(x, y);
}
//------------------------------------------------------------------------------
// ADD ADJACENTS TO ALL NODES
//------------------------------------------------------------------------------
void ServerMap::addAdjacentToAllNodes() {
    if (adjacentsAdded) return;
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {
            gameMap[x][y]->addAdjacent(*this);
        }
    }
    adjacentsAdded = true;
}
//------------------------------------------------------------------------------
