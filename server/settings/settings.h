// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef SETTINGS_H
#define SETTINGS_H
//------------------------------------------------------------------------------
#include <string>
#include "../../libs/Dicc.h"
//------------------------------------------------------------------------------
typedef Dicc<std::string, size_t> DiccArmament;
typedef Dicc<std::string, std::string> ArmamentOfManufactured;
typedef Dicc<std::string, float> DiccSettings;
typedef Dicc<std::string, uint32_t> DiccMap;
typedef Dicc<std::string, size_t> Objects;
//------------------------------------------------------------------------------
class Settings {
 public :
    DiccArmament bullets;
    DiccArmament highCaliberProjectiles;
    DiccArmament missiles;
    DiccArmament flamethrower;
    DiccArmament laser;

    DiccSettings robotGrunt;
    DiccSettings robotTough;
    DiccSettings robotSniper;
    DiccSettings robotPsycho;
    DiccSettings robotPyro;
    DiccSettings robotLaser;

    ArmamentOfManufactured robotGruntArmament;
    ArmamentOfManufactured robotToughArmament;
    ArmamentOfManufactured robotSniperArmament;
    ArmamentOfManufactured robotPsychoArmament;
    ArmamentOfManufactured robotPyroArmament;
    ArmamentOfManufactured robotLaserArmament;

    DiccSettings vehicleJeep;
    DiccSettings vehicleLightTank;
    DiccSettings vehicleMML;
    DiccSettings vehicleMediumTank;
    DiccSettings vehicleHeavyTank;

    ArmamentOfManufactured vehicleJeepArmament;
    ArmamentOfManufactured vehicleLightTankArmament;
    ArmamentOfManufactured vehicleMMLArmament;
    ArmamentOfManufactured vehicleMediumTankArmament;
    ArmamentOfManufactured vehicleHeavyTankArmament;

    DiccSettings EarthPrairieSnow;
    DiccSettings WaterSwamp;
    DiccSettings RoadAsphaltRoad;
    DiccSettings Lava;

    Objects ConcreteAndWoodenBridges;
    Objects StoneIceBlocks;
    Objects Buildings;

    DiccMap aMap;
 public :
    //--------------------------------------------------------------------------
    Settings();
    //--------------------------------------------------------------------------
    ~Settings();
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // SETTINGS_H
