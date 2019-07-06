// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "interpreter.h"
#include "../games/game.h"
#include "../terrains/node.h"
#include "../objects/object.h"
#include "../states/state.h"
#include "../territories/territories.h"
#include "../players/player.h"
#include "../states/stateMoving.h"
#include "../units/vehicles/vehicle.h"
#include "../armament/armament.h"
#include "../objects/buildings/buildings.h"
#include "../../libs/definitions.h"
//------------------------------------------------------------------------------
// SERVER SERIALIZER CONSTRUCTOR
//------------------------------------------------------------------------------
Interpreter::Interpreter(Game& aGame): aGame(aGame) {}
//------------------------------------------------------------------------------
// SERVER SERIALIZER DESTRUCTOR
//------------------------------------------------------------------------------
Interpreter::~Interpreter() {}
//------------------------------------------------------------------------------
// TILE TO CORNER PIXEL
//------------------------------------------------------------------------------
uint32_t Interpreter::tileToCornerPixel(uint32_t number) {
    return 64 * number;
}
//------------------------------------------------------------------------------
// TILE TO CENTRAL PIXEL
//------------------------------------------------------------------------------
uint32_t Interpreter::tileToCentralPixel(uint32_t number) {
    return 32 * (2 * number + 1);
}
//------------------------------------------------------------------------------
// DESERIALIZE PETITION
//------------------------------------------------------------------------------
msg_t Interpreter::deserializePetition(std::string petition) {
    std::vector<std::string> parsedPetition;
    parsedPetition = aParser.parseLine(petition, DELIM);
    if (parsedPetition[0] == CREATE_PLAYER) {
        size_t idTeam = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createPlayer(idTeam);
    }
    if (petition == GET_MODEL) {
        return aGame.getModel();
    }
    if (petition == GET_INITIAL_MODEL) {
        return aGame.getInitialModel();
    }
    if (parsedPetition[0] == CREATE_ROBOT_GRUNT) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createRobotGrunt(idBuilding);
    }
    if (parsedPetition[0] == CREATE_ROBOT_LASER) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createRobotLaser(idBuilding);
    }
    if (parsedPetition[0] == CREATE_ROBOT_PSYCHO) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createRobotPsycho(idBuilding);
    }
    if (parsedPetition[0] == CREATE_ROBOT_PYRO) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createRobotPyro(idBuilding);
    }
    if (parsedPetition[0] == CREATE_ROBOT_SNIPER) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createRobotSniper(idBuilding);
    }
    if (parsedPetition[0] == CREATE_ROBOT_TOUGH) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createRobotTough(idBuilding);
    }
    if (parsedPetition[0] == CREATE_VEHICLE_JEEP) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createVehicleJeep(idBuilding);
    }
    if (parsedPetition[0] == CREATE_VEHICLE_MML) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createVehicleMML(idBuilding);
    }
    if (parsedPetition[0] == CREATE_VEHICLE_LIGHT_TANK) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createVehicleLightTank(idBuilding);
    }
    if (parsedPetition[0] == CREATE_VEHICLE_MEDIUM_TANK) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createVehicleMediumTank(idBuilding);
    }
    if (parsedPetition[0] == CREATE_VEHICLE_HEAVY_TANK) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        return aGame.createVehicleHeavyTank(idBuilding);
    }
    if (parsedPetition[0] == MOVE_UNIT_TO) {
        uint32_t x = aParser.stringToUint32_t(parsedPetition[1]);
        uint32_t y = aParser.stringToUint32_t(parsedPetition[2]);
        size_t idUnit = aParser.stringToSize_t(parsedPetition[3]);
        return aGame.moveUnitTo(x, y, idUnit);
    }
    if (parsedPetition[0] == ATTACK_UNIT) {
        size_t idShooter = aParser.stringToSize_t(parsedPetition[1]);
        size_t idTarget = aParser.stringToSize_t(parsedPetition[2]);
        return aGame.attackUnit(idShooter, idTarget);
    }
    if (parsedPetition[0] == ATTACK_OBJECT) {
        size_t idShooter = aParser.stringToSize_t(parsedPetition[1]);
        size_t idTarget = aParser.stringToSize_t(parsedPetition[2]);
        return aGame.attackObject(idShooter, idTarget);
    }
    if (parsedPetition[0] == UPDATE) {
        return aGame.update();
    }
    const char* aPetition = parsedPetition[0].c_str();
    throw Exception("The petition received '%s' does not exist\n", aPetition);
}
//------------------------------------------------------------------------------
// CREATE UNIT
//------------------------------------------------------------------------------
msg_t Interpreter::createUnit(std::string &id) {
    size_t idBuilding = aParser.stringToSize_t(id);
    aGame.createVehicleHeavyTank(idBuilding);
    return std::vector<std::string>(1, "");
}
//------------------------------------------------------------------------------
// SERIALIZE
//------------------------------------------------------------------------------
parsedModel_t Interpreter::serialize() {
    parsedModel_t parsedModel;
    parsedModel.reserve(MODEL_SIZE);
    serializeObjects(parsedModel);
    serializeMunition(parsedModel);
    serializeUnits(parsedModel);
    parsedModel.push_back(END);
    return parsedModel;
}
//------------------------------------------------------------------------------
// INITIAL SERIALIZE
//------------------------------------------------------------------------------
parsedModel_t Interpreter::InitialSerialize() {
    parsedModel_t parsedModel;
    parsedModel.reserve(INITIAL_MODEL_SIZE);
    serializeMatrixDimensions(parsedModel);
    serializeNodes(parsedModel);
    serializeObjects(parsedModel);
    serializeTerritories(parsedModel);
    parsedModel.push_back(END);
    return parsedModel;
}
//------------------------------------------------------------------------------
// SERIALIZE MATRIX DIMENSIONS
//------------------------------------------------------------------------------
void Interpreter::serializeMatrixDimensions(parsedModel_t& parsedModel) {
    parsedModel.push_back(aParser.armString("matrix"));
    uint32_t width = aGame.gameMap.width;
    uint32_t height = aGame.gameMap.height;
    parsedModel.push_back(aParser.armString("%u-%u", width, height));
}
//------------------------------------------------------------------------------
// SERIALIZE NODES
//------------------------------------------------------------------------------
void Interpreter::serializeNodes(parsedModel_t &parsedModel) {
    parsedModel.push_back(aParser.armString("nodes"));
    uint32_t width = aGame.gameMap.width;
    uint32_t height = aGame.gameMap.height;
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0; y < height; y++) {
            Node* node = aGame.gameMap.getNode(x, y);
            uint32_t posX = node->getX();
            uint32_t posY = node->getY();
            float groundFactor = node->getGroundFactor();
            std::string tile;
            if (node->isDust()) tile = DUST;
            if (node->isGrass()) tile = GRASS;
            if (node->isSnow()) tile = SNOW;
            if (node->isRoad()) tile = ROAD;
            if (node->isAsphaltRoad()) tile = ASPHALT_ROAD;
            if (node->isWater()) tile = WATER;
            if (node->isSwamp()) tile = SWAMP;
            if (node->isLava()) tile = LAVA;
            std::string command;
            command = aParser.armString(
                    "%u-%u-%s-%f", posX, posY, tile.c_str(), groundFactor);
            parsedModel.push_back(command);
        }
    }
}
//------------------------------------------------------------------------------
// SERIALIZE OBJECTS
//------------------------------------------------------------------------------
void Interpreter::serializeObjects(parsedModel_t& parsedModel) {
    std::vector<Object*>& objects = aGame.gameMap.getObjects().getList();
    if (objects.empty()) return;
    parsedModel.push_back(aParser.armString("objects"));
    for (Object* anObject : objects) {
        if (!anObject->wasAddedOnNode()) continue;
        size_t id = anObject->getId();
        const Node& position = anObject->getPrincipalPosition();
        uint32_t x = position.getX();
        uint32_t y = position.getY();
        ssize_t idOwner = 0;
        if (anObject->hasAnOwner()) {
            idOwner = anObject->getOwner()->getId();
        }
        std::string type;
        std::string state = FALSE;
        if (anObject->getCurrentState()->isBroken()) state = TRUE;
        if (anObject->isFort()) type = FORT;
        if (anObject->isVehicleFactorie()) type = VEHICLE_FACTORY;
        if (anObject->isRobotFactorie()) type = ROBOT_FACTORY;
        if (anObject->isStone()) type = STONE;
        if (anObject->isIceBlock()) type = ICE_BLOCK;
        if (anObject->isWoodenBridge()) type = WOODEN_BRIDGE;
        if (anObject->isConcreteBridge()) type = CONCRETE_BRIDGE;
        if (anObject->isFlag()) type = FLAG;
        std::string command;
        command = aParser.armString(
                "%zu-%s-%u-%u-%zu-%s", id, type.c_str(), x, y, idOwner,
                state.c_str());
        if (anObject->isBuilding()) {
            Buildings* building = (Buildings*) anObject;
            size_t tec = building->getTecnologyLevel();
            command += aParser.armString("-%zu", tec);
        }
        parsedModel.push_back(command);
    }
}
//------------------------------------------------------------------------------
// SERIALIZE TERRITORIES
//------------------------------------------------------------------------------
void Interpreter::serializeTerritories(parsedModel_t& parsedModel) {
    territoriesVector& territories = aGame.gameMap.getTerritories();
    if (territories.empty()) return;
    for (Territories* aTerritory : territories) {
        size_t id = aTerritory->getId();
        parsedModel.push_back(aParser.armString("territory-%zu", id));
        if (aTerritory->hasAPlayer()) {
            size_t idOwner = aTerritory->getOwner()->getId();
            parsedModel.push_back(aParser.armString("%zu", idOwner));
        }
        std::vector<Node*>& nodes = aTerritory->getNodes();
        for (Node* aNode : nodes) {
            uint32_t x = aNode->getX();
            uint32_t y = aNode->getY();
            parsedModel.push_back(aParser.armString("%u-%u", x, y));
        }
    }
}
//------------------------------------------------------------------------------
// SERIALIZE UNITS
//------------------------------------------------------------------------------
void Interpreter::serializeUnits(parsedModel_t& parsedModel) {
    unitsVector& units = aGame.getUnits().getList();
    if (units.empty()) return;
    parsedModel.push_back(aParser.armString("units"));
    for (Unit* aUnit : units) {
        size_t id = aUnit->getId();
        uint32_t x = aUnit->getPosition()->getX();
        uint32_t y = aUnit->getPosition()->getY();
        size_t idOwner = aUnit->getOwner()->getId();
        float damageRel = aUnit->getDamageRel();
        float baseSpeed = 0;
        if (aUnit->isVehicle()) {
            Vehicle* vehicle = (Vehicle*) aUnit;
            baseSpeed = vehicle->getBaseSpeed();
        }
        std::string type;
        std::string state;
        if (aUnit->isGrunt()) type = GRUNT;
        if (aUnit->isTough()) type = TOUGH;
        if (aUnit->isSniper()) type = SNIPER;
        if (aUnit->isPsycho()) type = PSYCHO;
        if (aUnit->isPyro()) type = PYRO;
        if (aUnit->isLaser()) type = LASER;
        if (aUnit->isJeep()) type = JEEP;
        if (aUnit->isMML()) type = MML;
        if (aUnit->isLightTank()) type = LIGHT_TANK;
        if (aUnit->isMediumTank()) type = MEDIUM_TANK;
        if (aUnit->isHeavyTank()) type = HEAVY_TANK;
        std::string command;
        command = aParser.armString(
                "%zu-%u-%u-%s-%zu-%f-%f",
                id, x, y, type.c_str(), idOwner, damageRel, baseSpeed);

        const State* currentState = aUnit->getCurrentState();
        if (currentState->isStill()) {
            state = aParser.armString("-%s", STILL);
            command += state;
        }
        if (currentState->isDead()) {
            state = aParser.armString("-%s", DEAD);
            command += state;
        }
        if (currentState->isMoving()) {
            state = MOVING;
            const StateMoving* moving;
            moving = (const StateMoving*) currentState;
            uint32_t destX = moving->movingTo().getX();
            uint32_t destY = moving->movingTo().getY();
            command += aParser.armString(
                    "-%s-%u-%u", state.c_str(), destX, destY);
        }
        if (currentState->isAttackingUnit()) {
            state = aParser.armString("-%s", ATTACK_UNIT);
            command += state;
        }
        if (currentState->isAttackingObject()) {
            state = aParser.armString("-%s", ATTACK_OBJECT);
            command += state;
        }
        parsedModel.push_back(command);
    }
}
//------------------------------------------------------------------------------
// SERIALIZE MUNITION
//------------------------------------------------------------------------------
void Interpreter::serializeMunition(parsedModel_t& parsedModel) {
    munitionVector& munitions = aGame.getMunitions().getList();
    if (munitions.empty()) return;
    parsedModel.push_back(aParser.armString("munition"));
    for (Armament* aMunition : munitions) {
        size_t id = aMunition->getId();
        size_t idShooter = aMunition->getShooterId();
        if (!aGame.getUnits().keyExist(idShooter)) {
            aGame.munitionDie(id);
            continue;
        }
        std::string targetType;
        size_t idTarget;
        double speed = aMunition->getSpeed();
        if (aMunition->isTargetAnObject()) {
            targetType = OBJECT;
            idTarget = aMunition->getObjectTarget()->getId();
        } else {
            targetType = UNIT;
            idTarget = aMunition->getUnitTarget()->getId();
        }
        std::string command;
        command = aParser.armString("%zu-%zu-%s-%zu-%f", id, idShooter,
                                    targetType.c_str(), idTarget, speed);
        std::string state;
        const State* currentState = aMunition->getCurrentState();
        if (currentState->isMoving() && !aMunition->hasDeprecated()) {
            state = MOVING;
            const StateMoving* moving;
            moving = (const StateMoving*) currentState;
            uint32_t destX = moving->movingTo().getX();
            uint32_t destY = moving->movingTo().getY();
            command += aParser.armString(
                    "-%s-%u-%u", state.c_str(), destX, destY);
        }
        if (currentState->isStill() && !aMunition->hasDeprecated()) {
            state = aParser.armString("-%s", STILL);
            command += state;
        }
        if (currentState->isBroken() || aMunition->hasDeprecated()) {
            state = aParser.armString("-%s", OBSOLETE);
            command += state;
        }
        parsedModel.push_back(command);
    }
}
