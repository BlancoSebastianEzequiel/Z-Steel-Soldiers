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
//------------------------------------------------------------------------------
#define DUST "dust"
#define GRASS "grass"
#define SNOW "snow"
#define ROAD "highway"
#define ASPHALT_ROAD "asphaltRoad"
#define WATER "water"
#define SWAMP "swamp"
#define LAVA "lava"

#define FORT "fort"
#define VEHICLE_FACTORIE "vFactory"
#define ROBOT_FACTORIE "rFactory"
#define STONE "rock"
#define ICE_BLOCK "iceBlock"
#define WOODEN_BRIDGE "woodBridge"
#define CONCRETE_BRIDGE "concreteBridge"
#define FLAG "flag"

#define GRUNT "grunt"
#define TOUGH "tough"
#define SNIPER "sniper"
#define PSYCHO "psycho"
#define PYRO "pyro"
#define LASER "laser"
#define HEAVY_TANK "heavyTank"
#define MEDIUM_TANK "MediumTank"
#define LIGHT_TANK "LightTank"
#define MML "MML"
#define JEEP "jeep"

#define MOVING "moving"
#define STILL "still"
#define DEAD "dead"
#define OBSOLETE "obsolete"

#define OBJECT "object"
#define UNIT "unit"

#define TRUE "true"
#define FALSE "false"

#define DELIM '-'
#define CREATE_PLAYER "createPlayer"
#define CREATE_ROBOT_GRUNT "createRobotGrunt"
#define CREATE_ROBOT_LASER "createRobotLaser"
#define CREATE_ROBOT_TOUGH "createRobotTough"
#define CREATE_ROBOT_SNIPER "createRobotSniper"
#define CREATE_ROBOT_PYRO "createRobotPyro"
#define CREATE_ROBOT_PSYCHO "createRobotPsycho"
#define CREATE_VEHICLE_MML "createVehicleMML"
#define CREATE_VEHICLE_JEEP "createVehicleJeep"
#define CREATE_VEHICLE_LIGHT_TANK "createVehicleLightTank"
#define CREATE_VEHICLE_MEDIUM_TANK "createVehicleMediumTank"
#define CREATE_VEHICLE_HEAVY_TANK "createVehicleHeavyTank"
#define MOVE_UNIT_TO "moveUnitTo"
#define ATTACK_UNIT "attackUnit"
#define ATTACK_OBJECT "attackObject"
#define UPDATE "update"
#define END "end"


#define INITIAL_MODEL_SIZE 850
#define MODEL_SIZE 50
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
void Interpreter::deserializePetition(std::string petition) {
    std::vector<std::string> parsedPetition;
    parsedPetition = aParser.parseLine(petition, DELIM);
    if (parsedPetition[0] == CREATE_PLAYER) {
        size_t idTeam = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createPlayer(idTeam);
        return;
    }
    if (parsedPetition[0] == CREATE_ROBOT_GRUNT) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createRobotGrunt(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_ROBOT_LASER) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createRobotLaser(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_ROBOT_PSYCHO) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createRobotPsycho(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_ROBOT_PYRO) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createRobotPyro(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_ROBOT_SNIPER) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createRobotSniper(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_ROBOT_TOUGH) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createRobotTough(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_VEHICLE_JEEP) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createVehicleJeep(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_VEHICLE_MML) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createVehicleMML(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_VEHICLE_LIGHT_TANK) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createVehicleLightTank(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_VEHICLE_MEDIUM_TANK) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createVehicleMediumTank(idBuilding);
        return;
    }
    if (parsedPetition[0] == CREATE_VEHICLE_HEAVY_TANK) {
        size_t idBuilding = aParser.stringToSize_t(parsedPetition[1]);
        aGame.createVehicleHeavyTank(idBuilding);
        return;
    }
    if (parsedPetition[0] == MOVE_UNIT_TO) {
        uint32_t x = aParser.stringToUint32_t(parsedPetition[1]);
        uint32_t y = aParser.stringToUint32_t(parsedPetition[2]);
        size_t idUnit = aParser.stringToSize_t(parsedPetition[3]);
        aGame.moveUnitTo(x, y, idUnit);
        return;
    }
    if (parsedPetition[0] == ATTACK_UNIT) {
        size_t idShooter = aParser.stringToSize_t(parsedPetition[1]);
        size_t idTarget = aParser.stringToSize_t(parsedPetition[2]);
        aGame.attackUnit(idShooter, idTarget);
        return;
    }
    if (parsedPetition[0] == ATTACK_OBJECT) {
        size_t idShooter = aParser.stringToSize_t(parsedPetition[1]);
        size_t idTarget = aParser.stringToSize_t(parsedPetition[2]);
        aGame.attackObject(idShooter, idTarget);
        return;
    }
    if (parsedPetition[0] == UPDATE) {
        aGame.update();
        return;
    }
    const char* aPetition = parsedPetition[0].c_str();
    throw Exception("The petition received '%s' does not exist\n", aPetition);
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
            // x-y-type-groundFactor
            command = aParser.armString(
                    "%u-%u-%s-%f", posX, posY, tile.c_str(), groundFactor);
            // printf("NODES PARSE: %s\n", command.c_str());
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
        if (anObject->isVehicleFactorie()) type = VEHICLE_FACTORIE;
        if (anObject->isRobotFactorie()) type = ROBOT_FACTORIE;
        if (anObject->isStone()) type = STONE;
        if (anObject->isIceBlock()) type = ICE_BLOCK;
        if (anObject->isWoodenBridge()) type = WOODEN_BRIDGE;
        if (anObject->isConcreteBridge()) type = CONCRETE_BRIDGE;
        if (anObject->isFlag()) type = FLAG;
        std::string command;
        // id-type-x-y-idOwner-isBroken-(tecnologyLevel)
        command = aParser.armString(
                "%zu-%s-%u-%u-%zu-%s", id, type.c_str(), x, y, idOwner,
                state.c_str());
        if (anObject->isBuilding()) {
            Buildings* building = (Buildings*) anObject;
            size_t tec = building->getTecnologyLevel();
            command += aParser.armString("-%zu", tec);
        }
        // printf("OBJECTS PARSE: %s\n", command.c_str());
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
    // id-x-y-type-idOwner-damageRel-baseSpeed-state(moving(x-y)-still-dead)
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
        // id-x-y-type-idOwner-damageRel-baseSpeed-state(moving(x-y)-still-dead)
        // printf("UNIT PARSE: %s\n", command.c_str());
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
        // id-idShooter-targetType-idTarget-speed-state(moving(x-y)/obsolete)
        // printf("MUNITION PARSE: %s\n", command.c_str());
        parsedModel.push_back(command);
    }
}
//------------------------------------------------------------------------------
