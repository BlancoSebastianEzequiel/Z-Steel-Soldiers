#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define INITIAL_MODEL_SIZE 850
#define MODEL_SIZE 50

#define NEW_LINE '\n'
#define DIMENSIONS "dimensions"


// Objects
#define DUST "dust"
#define GRASS "grass"
#define SNOW "snow"
#define ROAD "road"
#define ASPHALT_ROAD "asphaltRoad"
#define WATER "water"
#define SWAMP "swamp"
#define LAVA "lava"
#define HIGHWAY "highway"
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

// Armament
#define BULLETS "bullets"
#define HIGH_CALIBER_PROJECTILES "highCaliberProjectiles"
#define MISSILES "missiles"
#define FLAMETHROWER "flamethrower"
#define LASER "laser"

// units
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
#define CREATE_ROBOT "createRobot"
#define CREATE_VEHICLE "createVehicle"
#define MOVE_UNIT_TO "moveUnitTo"
#define ATTACK_UNIT "attackUnit"
#define ATTACK_OBJECT "attackObject"
#define UPDATE "update"
#define WINNER "winner"
#define END "end"

typedef std::vector<std::string> msg_t;

#endif // DEFINITIONS_H
