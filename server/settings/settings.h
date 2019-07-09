// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef SETTINGS_H
#define SETTINGS_H
//------------------------------------------------------------------------------
#include <string>
#include "../../libs/Dicc.h"
//------------------------------------------------------------------------------
typedef Dicc<std::string, size_t> armament_t;
typedef Dicc<std::string, std::string> unitArmament_t;
typedef Dicc<std::string, unitArmament_t> unitsArmament_t;
typedef Dicc<std::string, float> unit_t;
typedef Dicc<std::string, unit_t> units_t;
typedef Dicc<std::string, float> object_t;
typedef Dicc<std::string, uint32_t> map_t;
//------------------------------------------------------------------------------
class Settings {
 public :
    units_t units;
    unitsArmament_t unitsArmament;

    armament_t bullets;
    armament_t highCaliberProjectiles;
    armament_t missiles;
    armament_t flamethrower;
    armament_t laser;

    unit_t robotGrunt;
    unit_t robotTough;
    unit_t robotSniper;
    unit_t robotPsycho;
    unit_t robotPyro;
    unit_t robotLaser;

    unitArmament_t robotGruntArmament;
    unitArmament_t robotToughArmament;
    unitArmament_t robotSniperArmament;
    unitArmament_t robotPsychoArmament;
    unitArmament_t robotPyroArmament;
    unitArmament_t robotLaserArmament;

    unit_t vehicleJeep;
    unit_t vehicleLightTank;
    unit_t vehicleMML;
    unit_t vehicleMediumTank;
    unit_t vehicleHeavyTank;

    unitArmament_t vehicleJeepArmament;
    unitArmament_t vehicleLightTankArmament;
    unitArmament_t vehicleMMLArmament;
    unitArmament_t vehicleMediumTankArmament;
    unitArmament_t vehicleHeavyTankArmament;

    object_t EarthPrairieSnow;
    object_t WaterSwamp;
    object_t RoadAsphaltRoad;
    object_t Lava;

    object_t ConcreteAndWoodenBridges;
    object_t StoneIceBlocks;
    object_t Buildings;

    map_t aMap;
 public :
    //--------------------------------------------------------------------------
    Settings();
    //--------------------------------------------------------------------------
    ~Settings();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // SETTINGS_H
