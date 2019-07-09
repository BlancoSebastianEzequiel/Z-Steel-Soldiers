// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "interpreter.h"
#include "../proxys/proxyNode.h"
#include "../proxys/proxyTerritories.h"
#include "../proxys/proxyGame.h"
#include "../proxys/proxyObject.h"
#include "../proxys/proxyUnit.h"
#include "../proxys/proxyMunition.h"
#include "../../libs/definitions.h"
//------------------------------------------------------------------------------
// CLIENT DESERIALIZER CONSTRUCTOR
//------------------------------------------------------------------------------
Interpreter::Interpreter(ProxyGame& game): game(game) {
    aTerritory = nullptr;
}
//------------------------------------------------------------------------------
// CLIENT DESERIALIZER DESTRUCTOR
//------------------------------------------------------------------------------
Interpreter::~Interpreter() {
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
void Interpreter::deserialize(std::string parsedModel) {
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
void Interpreter::deserializeDimensions(parsedCommand_t parsedMatrix) {
    uint32_t width = aParser.stringToUint32_t(parsedMatrix[0]);
    uint32_t height = aParser.stringToUint32_t(parsedMatrix[1]);
    game.setMapDimensions(width, height);
}
//------------------------------------------------------------------------------
// DESERIALIZE NODE
//------------------------------------------------------------------------------
void Interpreter::deserializeNode(parsedCommand_t parsedNode) {
    // x-y-type-groundFactor
    uint32_t x = aParser.stringToUint32_t(parsedNode[0]);
    uint32_t y = aParser.stringToUint32_t(parsedNode[1]);
    std::string type = parsedNode[2];
    float groundFactor = aParser.stringToFloat(parsedNode[3]);
    auto* node = new ProxyNode(x, y, type);
    node->setGroundFactor(groundFactor);
    game.gameMap[x][y] = node;
}
//------------------------------------------------------------------------------
// DESERIALIZE OBJECT
//------------------------------------------------------------------------------
void Interpreter::deserializeObject(parsedCommand_t parsedObject) {
    ProxyObject* object;
    size_t id = aParser.stringToSize_t(parsedObject[0]);
    std::string type = parsedObject[1];
    uint32_t x = aParser.stringToUint32_t(parsedObject[2]);
    uint32_t y = aParser.stringToUint32_t(parsedObject[3]);
    ssize_t idOwner = aParser.stringToSize_t(parsedObject[4]);
    std::string state = parsedObject[5];
    ProxyNode* position = game.gameMap[x][y];
    if (!game.getObjects().keyExist(id)) {
        object = new ProxyObject(*position, id, type);
        object->setIsUpdated(true);
        position->addObject(object);
        if (object->isBuilding()) {
            size_t tecnologyLevel = aParser.stringToSize_t(parsedObject[6]);
            object->setTecnologyLevel(tecnologyLevel);
            ProxyNode* right = game.gameMap[x+1][y];
            right->addObject(object);
            ProxyNode* down = game.gameMap[x][y+1];
            down->addObject(object);
            ProxyNode* diagonal = game.gameMap[x+1][y+1];
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
void Interpreter::deserializeTerritory(parsedCommand_t parsedTerritory) {
    ProxyTerritories* aTerritory = game.getTerritories()[idTerritory];
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
void Interpreter::deserializeUnit(parsedModel_t parsedUnit) {
    ProxyUnit* aUnit;
    size_t id = aParser.stringToSize_t(parsedUnit[0]);
    uint32_t x = aParser.stringToUint32_t(parsedUnit[1]);
    uint32_t y = aParser.stringToUint32_t(parsedUnit[2]);
    size_t type = aParser.stringToSize_t(parsedUnit[3]);
    ProxyNode* position = game.gameMap[x][y];
    size_t ownerId = aParser.stringToSize_t(parsedUnit[4]);
    float damageRel = aParser.stringToFloat(parsedUnit[5]);
    float baseSpeed = aParser.stringToFloat(parsedUnit[6]);
    std::string state = parsedUnit[7];
    if (!game.getUnits().keyExist(id)) {
        aUnit = new ProxyUnit(*position, id, type);
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
        ProxyNode* dest = game.gameMap[destX][destY];
        aUnit->setMovingDest(*dest);
    }
    game.addUnit(*aUnit);
}
//------------------------------------------------------------------------------
// DESERIALIZE MUNITION
//------------------------------------------------------------------------------
void Interpreter::deserializeMunition(parsedModel_t parsedMunition) {
    ProxyMunition* aMunition;
    size_t id = aParser.stringToSize_t(parsedMunition[0]);
    size_t idShooter = aParser.stringToSize_t(parsedMunition[1]);
    std::string targetType = parsedMunition[2];
    size_t idTarget = aParser.stringToSize_t(parsedMunition[3]);
    float speed = aParser.stringToFloat(parsedMunition[4]);
    std::string state = parsedMunition[5];
    if (!game.getMunitions().keyExist(id)) {
        aMunition = new ProxyMunition(id, idShooter, idTarget);
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
        ProxyNode* dest = game.gameMap[destX][destY];
        aMunition->setMovingDest(*dest);
    }
    aMunition->changeState(state);
    game.addMunition(*aMunition);
}
//------------------------------------------------------------------------------
// CREATE NEW TERRITORY
//------------------------------------------------------------------------------
void Interpreter::createNewTerritory(size_t id) {
    auto* territory = new ProxyTerritories(id);
    game.addTerritory(*territory);
}
//------------------------------------------------------------------------------
