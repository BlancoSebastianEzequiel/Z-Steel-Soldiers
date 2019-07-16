#ifndef DEFINITIONS_H
#define DEFINITIONS_H

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
#define FORT "fort"
#define VEHICLE_FACTORY "vehicleFactory"
#define ROBOT_FACTORY "robotFactory"
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

#include <map>

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
