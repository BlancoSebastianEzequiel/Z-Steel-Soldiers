// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef SETTINGS_H
#define SETTINGS_H
//------------------------------------------------------------------------------
#include <string>
#include "../../libs/Dicc.h"
#include "../../libs/Parser.h"
//------------------------------------------------------------------------------
typedef Dicc<std::string, size_t> armament_t;
typedef Dicc<size_t, armament_t*> armaments_t;

typedef Dicc<std::string, float> unit_t;
typedef Dicc<size_t, unit_t*> units_t;

typedef Dicc<std::string, float> object_t;
//------------------------------------------------------------------------------
class Settings {
 public :
    Parser aParser;
    units_t units;
    armaments_t armaments;

    object_t EarthPrairieSnow;
    object_t WaterSwamp;
    object_t RoadAsphaltRoad;
    object_t Lava;

    object_t ConcreteAndWoodenBridges;
    object_t StoneIceBlocks;
    object_t Buildings;
 public :
    //--------------------------------------------------------------------------
    Settings();
    //--------------------------------------------------------------------------
    ~Settings();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // SETTINGS_H
