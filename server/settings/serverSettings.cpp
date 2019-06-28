// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverSettings.h"
//------------------------------------------------------------------------------
// SETTINGS CONSTRUCTOR
//------------------------------------------------------------------------------
Settings::Settings() {
    bullets("damage", 2);
    highCaliberProjectiles("damage", 20);
    missiles("damage", 25);
    flamethrower("damage", 10);
    laser("damage", 10);

    robotGrunt("shootingFrequency", 2);
    robotGrunt("reach", 5);
    robotGrunt("manufacturing", 3);
    robotGrunt("structurePoints", 1);  // 60
    robotGrunt("baseManufacturingTime", 9.35);  // 9.35
    robotGrunt("minimumTechnologyLevel", 1);
    robotGruntArmament("armament", "bullets");

    robotTough("shootingFrequency", 2);
    robotTough("reach", 7);
    robotTough("manufacturing", 2);
    robotTough("structurePoints", 300);
    robotTough("baseManufacturingTime", 12.22);
    robotTough("minimumTechnologyLevel", 2);
    robotToughArmament("armament", "missiles");

    robotSniper("shootingFrequency", 4);
    robotSniper("reach", 10);
    robotSniper("structurePoints", 80);
    robotSniper("manufacturing", 3);
    robotSniper("baseManufacturingTime", 9.35);
    robotSniper("minimumTechnologyLevel", 3);
    robotSniperArmament("armament", "bullets");

    robotPsycho("shootingFrequency", 10);
    robotPsycho("reach", 7);
    robotPsycho("structurePoints", 80);
    robotPsycho("manufacturing", 3);
    robotPsycho("baseManufacturingTime", 10);
    robotPsycho("minimumTechnologyLevel", 2);
    robotPsychoArmament("armament", "bullets");

    robotPyro("shootingFrequency", 4);
    robotPyro("reach", 6);
    robotPyro("structurePoints", 100);
    robotPyro("manufacturing", 4);
    robotPyro("baseManufacturingTime", 14);
    robotPyro("minimumTechnologyLevel", 4);
    robotPyroArmament("armament", "flamethrower");

    robotLaser("shootingFrequency", 4);
    robotLaser("reach", 7);
    robotLaser("structurePoints", 100);
    robotLaser("manufacturing", 5);
    robotLaser("baseManufacturingTime", 15);
    robotLaser("minimumTechnologyLevel", 5);
    robotLaserArmament("armament", "laser");

    vehicleJeep("shootingFrequency", 6);
    vehicleJeep("reach", 6);
    vehicleJeep("structurePoints", 60);
    vehicleJeep("speedBase", 8);
    vehicleJeep("baseManufacturingTime", 11);
    vehicleJeep("minimumTechnologyLevel", 1);
    vehicleJeepArmament("armament", "bullets");

    vehicleLightTank("shootingFrequency", 0.5);
    vehicleLightTank("reach", 6);
    vehicleLightTank("structurePoints", 80);
    vehicleLightTank("speedBase", 6);
    vehicleLightTank("baseManufacturingTime", 14);
    vehicleLightTank("minimumTechnologyLevel", 2);
    vehicleLightTankArmament("armament", "highCaliberProjectiles");

    vehicleMediumTank("shootingFrequency", 0.5);
    vehicleMediumTank("reach", 7);
    vehicleMediumTank("structurePoints", 120);
    vehicleMediumTank("speedBase", 5);
    vehicleMediumTank("baseManufacturingTime", 18);
    vehicleMediumTank("minimumTechnologyLevel", 3);
    vehicleMediumTankArmament("armament", "highCaliberProjectiles");

    vehicleHeavyTank("shootingFrequency", 0.5);
    vehicleHeavyTank("reach", 8);
    vehicleHeavyTank("structurePoints", 180);
    vehicleHeavyTank("speedBase", 5);
    vehicleHeavyTank("baseManufacturingTime", 20);
    vehicleHeavyTank("minimumTechnologyLevel", 4);
    vehicleHeavyTankArmament("armament", "highCaliberProjectiles");

    vehicleMML("shootingFrequency", 2);
    vehicleMML("reach", 8);
    vehicleMML("structurePoints", 200);
    vehicleMML("speedBase", 5);
    vehicleMML("baseManufacturingTime", 28);
    vehicleMML("minimumTechnologyLevel", 5);
    vehicleMMLArmament("armament", "missiles");

    EarthPrairieSnow("groundFactor", 1);
    WaterSwamp("groundFactor", 0.7);
    RoadAsphaltRoad("groundFactor", 1.5);
    Lava("groundFactor", 0);

    StoneIceBlocks("structurePoints", 10);
    Buildings("structurePoints", 1000);  // 1000
    ConcreteAndWoodenBridges("structurePoints", 1000);  // 1000

    aMap("width", 4);
    aMap("height", 6);
}
//------------------------------------------------------------------------------
// SETTINGS DESTRUCTOR
//------------------------------------------------------------------------------
Settings::~Settings() {}
//------------------------------------------------------------------------------
