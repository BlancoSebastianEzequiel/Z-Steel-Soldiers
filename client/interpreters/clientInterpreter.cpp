// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "clientInterpreter.h"
#include "../proxys/clientProxyNode.h"
#include "../proxys/clientProxyTerritories.h"
#include "../proxys/clientProxyGame.h"
#include "../proxys/clientProxyObject.h"
#include "../proxys/clientProxyUnit.h"
#include "../proxys/clientProxyMunition.h"
//------------------------------------------------------------------------------
#define DELIM '-'

#define FORT "fort"
#define VEHICLE_FACTORIE "vFactory"
#define ROBOT_FACTORIE "rFactory"
#define STONE "rock"
#define ICE_BLOCK "iceBlock"
#define WOODEN_BRIDGE "woodBridge"
#define CONCRETE_BRIDGE "concreteBridge"
#define FLAG "flag"

#define TERRITORY "territory"
#define NODES "nodes"
#define OBJECTS "objects"
#define UNITS "units"
#define MUNITION "munition"
#define MATRIX "matrix"
#define TRUE "true"
#define FALSE "false"

#define MOVING "moving"
#define STILL "still"
#define DEAD "dead"
#define OBSOLETE "obsolete"
#define BROKEN "broken"
//------------------------------------------------------------------------------
// CLIENT DESERIALIZER CONSTRUCTOR
//------------------------------------------------------------------------------
ClientInterpreter::ClientInterpreter(ClientProxyGame& game): game(game) {
    aTerritory = nullptr;
}
//------------------------------------------------------------------------------
// CLIENT DESERIALIZER DESTRUCTOR
//------------------------------------------------------------------------------
ClientInterpreter::~ClientInterpreter() {
    if (game.gameMap.empty()) return;
    for (uint32_t x = 0; x < game.width; x++) {
        for (uint32_t y = 0; y < game.height; y++) {
            delete game.gameMap[x][y];
        }
    }
}
//------------------------------------------------------------------------------
// DESERIALIZE
//------------------------------------------------------------------------------
void ClientInterpreter::deserialize(std::string parsedModel) {
    parsedCommand_t parsedCommand = aParser.parseLine(parsedModel, DELIM);
    if (parsedCommand.size() == 1) {
        keyWord = parsedCommand[0];
        return;
    }
    if (parsedCommand.size() == 2 && parsedCommand[0] == TERRITORY) {
        keyWord = TERRITORY;
        idTerritory = aParser.stringToSize_t(parsedCommand[1]);
        if (game.getTerritories().keyExist(idTerritory)) return;
        createNewTerritory(idTerritory);
        return;
    }
    if (keyWord == MATRIX) deserializeDimensions(parsedCommand);
    if (keyWord == NODES) deserializeNode(parsedCommand);
    if (keyWord == OBJECTS) deserializeObject(parsedCommand);
    if (keyWord == TERRITORY) deserializeTerritory(parsedCommand);
    if (keyWord == UNITS) deserializeUnit(parsedCommand);
    if (keyWord == MUNITION) deserializeMunition(parsedCommand);
}
//------------------------------------------------------------------------------
// DESERIALIZE DIMENSIONS
//------------------------------------------------------------------------------
void ClientInterpreter::deserializeDimensions(parsedCommand_t parsedMatrix) {
    uint32_t width = aParser.stringToUint32_t(parsedMatrix[0]);
    uint32_t height = aParser.stringToUint32_t(parsedMatrix[1]);
    game.setMapDimensions(width, height);
}
//------------------------------------------------------------------------------
// DESERIALIZE NODE
//------------------------------------------------------------------------------
void ClientInterpreter::deserializeNode(parsedCommand_t parsedNode) {
    // x-y-type-groundFactor
    uint32_t x = aParser.stringToUint32_t(parsedNode[0]);
    uint32_t y = aParser.stringToUint32_t(parsedNode[1]);
    std::string type = parsedNode[2];
    float groundFactor = aParser.stringToFloat(parsedNode[3]);
    ClientProxyNode* node = new ClientProxyNode(x, y, type);
    node->setGroundFactor(groundFactor);
    game.gameMap[x][y] = node;
}
//------------------------------------------------------------------------------
// DESERIALIZE OBJECT
//------------------------------------------------------------------------------
void ClientInterpreter::deserializeObject(parsedCommand_t parsedObject) {
    // id-type-x-y-idOwner-isBroken-(tecnologyLevel)
    ClientProxyObject* object;
    size_t id = aParser.stringToSize_t(parsedObject[0]);
    std::string type = parsedObject[1];
    uint32_t x = aParser.stringToUint32_t(parsedObject[2]);
    uint32_t y = aParser.stringToUint32_t(parsedObject[3]);
    ssize_t idOwner = aParser.stringToSize_t(parsedObject[4]);
    std::string state = parsedObject[5];
    ClientProxyNode* position = game.gameMap[x][y];
    if (!game.getObjects().keyExist(id)) {
        object = new ClientProxyObject(*position, id, type);
        object->setIsUpdated(true);
        position->addObject(object);
        if (object->isBuilding()) {
            size_t tecnologyLevel = aParser.stringToSize_t(parsedObject[6]);
            object->setTecnologyLevel(tecnologyLevel);
            ClientProxyNode* right = game.gameMap[x+1][y];
            right->addObject(object);
            ClientProxyNode* down = game.gameMap[x][y+1];
            down->addObject(object);
            ClientProxyNode* diagonal = game.gameMap[x+1][y+1];
            diagonal->addObject(object);
        }
    } else {
        object = game.getObjects()[id];
        object->setIsUpdated(true);
    }
    object->setOwnerId(idOwner);
    object->changeState(state);
    game.addObject(*object);
}
//------------------------------------------------------------------------------
// DESERIALIZE TERRITORIES
//------------------------------------------------------------------------------
void ClientInterpreter::deserializeTerritory(parsedCommand_t parsedTerritory) {
    ClientProxyTerritories* aTerritory = game.getTerritories()[idTerritory];
    if (parsedTerritory.size() == 1) {
        size_t idOwner = aParser.stringToSize_t(parsedTerritory[0]);
        aTerritory->changePlayer(idOwner);
        return;
    }
    uint32_t x = aParser.stringToUint32_t(parsedTerritory[0]);
    uint32_t y = aParser.stringToUint32_t(parsedTerritory[1]);
    aTerritory->addNode(*game.gameMap[x][y]);
}
//------------------------------------------------------------------------------
// DESERIALIZE UNITS
//------------------------------------------------------------------------------
void ClientInterpreter::deserializeUnit(parsedModel_t parsedUnit) {
    // id-x-y-type-ownerId-damageRel-baseSpeed-state(moving(x-y)-still-dead)
    ClientProxyUnit* aUnit;
    size_t id = aParser.stringToSize_t(parsedUnit[0]);
    uint32_t x = aParser.stringToUint32_t(parsedUnit[1]);
    uint32_t y = aParser.stringToUint32_t(parsedUnit[2]);
    std::string type = parsedUnit[3];
    ClientProxyNode* position = game.gameMap[x][y];
    size_t ownerId = aParser.stringToSize_t(parsedUnit[4]);
    float damageRel = aParser.stringToFloat(parsedUnit[5]);
    float baseSpeed = aParser.stringToFloat(parsedUnit[6]);
    std::string state = parsedUnit[7];
    if (!game.getUnits().keyExist(id)) {
        aUnit = new ClientProxyUnit(*position, id, type);
        aUnit->setOwnerId(ownerId);
        aUnit->setBaseSpeed(baseSpeed);
        aUnit->setIsUpdated(true);
    } else {
        aUnit = game.getUnits()[id];
        aUnit->changePosition(*position);
        aUnit->setIsUpdated(true);
    }
    aUnit->setDamageRel(damageRel);
    aUnit->changeState(state);
    if (state == MOVING) {
        uint32_t destX = aParser.stringToUint32_t(parsedUnit[8]);
        uint32_t destY = aParser.stringToUint32_t(parsedUnit[9]);
        ClientProxyNode* dest = game.gameMap[destX][destY];
        aUnit->setMovingDest(*dest);
    }
    game.addUnit(*aUnit);
}
//------------------------------------------------------------------------------
// DESERIALIZE MUNITION
//------------------------------------------------------------------------------
void ClientInterpreter::deserializeMunition(parsedModel_t parsedMunition) {
    // id-idShooter-targetType-idTarget-speed-state(moving(x-y)/obsolete)
    ClientProxyMunition* aMunition;
    size_t id = aParser.stringToSize_t(parsedMunition[0]);
    size_t idShooter = aParser.stringToSize_t(parsedMunition[1]);
    std::string targetType = parsedMunition[2];
    size_t idTarget = aParser.stringToSize_t(parsedMunition[3]);
    float speed = aParser.stringToFloat(parsedMunition[4]);
    std::string state = parsedMunition[5];
    // if (state == OBSOLETE) printf("MUNITION ID: %zu is obsolete\n", id);
    if (!game.getMunitions().keyExist(id)) {
        aMunition = new ClientProxyMunition(id, idShooter, idTarget);
        aMunition->setTargetType(targetType);
        aMunition->setSpeed(speed);
        aMunition->setIsUpdated(true);
    } else {
        aMunition = game.getMunitions()[id];
        aMunition->setIsUpdated(true);
    }
    if (state == MOVING) {
        uint32_t destX = aParser.stringToUint32_t(parsedMunition[6]);
        uint32_t destY = aParser.stringToUint32_t(parsedMunition[7]);
        ClientProxyNode* dest = game.gameMap[destX][destY];
        aMunition->setMovingDest(*dest);
    }
    aMunition->changeState(state);
    game.addMunition(*aMunition);
}
//------------------------------------------------------------------------------
// CREATE NEW TERRITORY
//------------------------------------------------------------------------------
void ClientInterpreter::createNewTerritory(size_t id) {
    ClientProxyTerritories* territory = new ClientProxyTerritories(id);
    game.addTerritory(*territory);
}
//------------------------------------------------------------------------------
