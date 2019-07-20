#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <map>

#define INITIAL_MODEL_SIZE 850
#define MODEL_SIZE 50

#define NEW_LINE '\n'
#define DIMENSIONS "dimensions"

// Nodes
#define DUST "dust"
#define GRASS "grass"
#define SNOW "snow"
#define ROAD "road"
#define ASPHALT_ROAD "asphaltRoad"
#define WATER "water"
#define SWAMP "swamp"
#define LAVA "lava"

// Objects
#define FORT_BEHAVIOR 0
#define BUILDING_BEHAVIOR 1
#define SOLIDS_BEHAVIOR 2
#define BRIDGES_BEHAVIOR 3
#define FLAG_BEHAVIOR 4

#define FORT "fort"
#define VEHICLE_FACTORY "vehicleFactory"
#define ROBOT_FACTORY "robotFactory"
#define STONE "rock"
#define ICE_BLOCK "iceBlock"
#define WOODEN_BRIDGE "woodBridge"
#define CONCRETE_BRIDGE "concreteBridge"
#define FLAG "flag"

// Objects Type
#define FORT_TYPE 0
#define VEHICLE_FACTORY_TYPE 1
#define ROBOT_FACTORY_TYPE 2
#define STONE_TYPE 3
#define ICE_BLOCK_TYPE 4
#define WOODEN_BRIDGE_TYPE 5
#define CONCRETE_BRIDGE_TYPE 6
#define FLAG_TYPE 7

const std::map<std::string, size_t > objectsNames = {
        { FORT, FORT_TYPE },
        { VEHICLE_FACTORY, VEHICLE_FACTORY_TYPE },
        { ROBOT_FACTORY, ROBOT_FACTORY_TYPE },
        { STONE, STONE_TYPE },
        { ICE_BLOCK, ICE_BLOCK_TYPE },
        { WOODEN_BRIDGE, WOODEN_BRIDGE_TYPE },
        { CONCRETE_BRIDGE, CONCRETE_BRIDGE_TYPE },
        { FLAG, FLAG_TYPE }
};

#define TERRITORY "territory"
#define NODES "nodes"
#define OBJECTS "objects"
#define UNITS "units"
#define MUNITION "munition"
#define MATRIX "matrix"

// units
#define ROBOT_BEHAVIOR 0
#define VEHICLE_BEHAVIOR 1

#define GRUNT 0
#define TOUGH 1
#define SNIPER 2
#define PSYCHO 3
#define PYRO 4
#define ROBOT_LASER 5
#define HEAVY_TANK 6
#define MEDIUM_TANK 7
#define LIGHT_TANK 8
#define MML 9
#define JEEP 10

const std::map<size_t, std::string> unitsNames = {
     { GRUNT, "grunt" },
     { TOUGH, "tough" },
     { SNIPER, "sniper" },
     { PSYCHO, "psycho" },
     { PYRO, "pyro" },
     { ROBOT_LASER, "laser" },
     { HEAVY_TANK, "heavy_tank" },
     { MEDIUM_TANK, "medium_tank" },
     { LIGHT_TANK, "light_tank" },
     { MML, "mml" },
     { JEEP, "jeep" }
};


// states
#define MOVING "moving"
#define STILL "still"
#define DEAD "dead"
#define OBSOLETE "obsolete"
#define BROKEN "true"

#define OBJECT "object"
#define UNIT "unit"

#define TRUE "true"
#define FALSE "false"

// messages
#define DELIM '-'
#define GET_MODEL "getModel"
#define GET_INITIAL_MODEL "getInitialModel"
#define CREATE_PLAYER "createPlayer"
#define CREATE_UNIT "createUnit"
#define MOVE_UNIT_TO "moveUnitTo"
#define ATTACK_UNIT "attackUnit"
#define ATTACK_OBJECT "attackObject"
#define UPDATE "update"
#define WINNER "winner"
#define END "end"

typedef std::vector<std::string> msg_t;

#endif // DEFINITIONS_H
