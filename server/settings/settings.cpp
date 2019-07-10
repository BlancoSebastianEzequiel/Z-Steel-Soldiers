// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "settings.h"
#include "../../libs/definitions.h"
//------------------------------------------------------------------------------
// SETTINGS CONSTRUCTOR
//------------------------------------------------------------------------------
Settings::Settings() {
    bullets("damage", 2);
    highCaliberProjectiles("damage", 20);
    missiles("damage", 25);
    flamethrower("damage", 10);
    laser("damage", 10);

    armaments(BULLETS, bullets);
    armaments(HIGH_CALIBER_PROJECTILES, highCaliberProjectiles);
    armaments(MISSILES, missiles);
    armaments(FLAMETHROWER, flamethrower);
    armaments(LASER, laser);

    robotGrunt("shootingFrequency", 2);
    robotGrunt("reach", 5);
    robotGrunt("manufacturing", 3);
    robotGrunt("structurePoints", 1);  // 60
    robotGrunt("baseManufacturingTime", 9.35);  // 9.35
    robotGrunt("minimumTechnologyLevel", 1);
    robotGruntArmament("armament", BULLETS);
    unitsBehavior(GRUNT, ROBOT_BEHAVIOR);

    robotTough("shootingFrequency", 2);
    robotTough("reach", 7);
    robotTough("manufacturing", 2);
    robotTough("structurePoints", 300);
    robotTough("baseManufacturingTime", 12.22);
    robotTough("minimumTechnologyLevel", 2);
    robotToughArmament("armament", MISSILES);
    unitsBehavior(TOUGH, ROBOT_BEHAVIOR);

    robotSniper("shootingFrequency", 4);
    robotSniper("reach", 10);
    robotSniper("structurePoints", 80);
    robotSniper("manufacturing", 3);
    robotSniper("baseManufacturingTime", 9.35);
    robotSniper("minimumTechnologyLevel", 3);
    robotSniperArmament("armament", BULLETS);
    unitsBehavior(SNIPER, ROBOT_BEHAVIOR);

    robotPsycho("shootingFrequency", 10);
    robotPsycho("reach", 7);
    robotPsycho("structurePoints", 80);
    robotPsycho("manufacturing", 3);
    robotPsycho("baseManufacturingTime", 10);
    robotPsycho("minimumTechnologyLevel", 2);
    robotPsychoArmament("armament", BULLETS);
    unitsBehavior(PSYCHO, ROBOT_BEHAVIOR);

    robotPyro("shootingFrequency", 4);
    robotPyro("reach", 6);
    robotPyro("structurePoints", 100);
    robotPyro("manufacturing", 4);
    robotPyro("baseManufacturingTime", 14);
    robotPyro("minimumTechnologyLevel", 4);
    robotPyroArmament("armament", FLAMETHROWER);
    unitsBehavior(PYRO, ROBOT_BEHAVIOR);

    robotLaser("shootingFrequency", 4);
    robotLaser("reach", 7);
    robotLaser("structurePoints", 100);
    robotLaser("manufacturing", 5);
    robotLaser("baseManufacturingTime", 15);
    robotLaser("minimumTechnologyLevel", 5);
    robotLaserArmament("armament", LASER);
    unitsBehavior(ROBOT_LASER, ROBOT_BEHAVIOR);

    vehicleJeep("shootingFrequency", 6);
    vehicleJeep("reach", 6);
    vehicleJeep("structurePoints", 60);
    vehicleJeep("speedBase", 8);
    vehicleJeep("baseManufacturingTime", 11);
    vehicleJeep("minimumTechnologyLevel", 1);
    vehicleJeepArmament("armament", BULLETS);
    unitsBehavior(JEEP, VEHICLE_BEHAVIOR);

    vehicleLightTank("shootingFrequency", 0.5);
    vehicleLightTank("reach", 6);
    vehicleLightTank("structurePoints", 80);
    vehicleLightTank("speedBase", 6);
    vehicleLightTank("baseManufacturingTime", 14);
    vehicleLightTank("minimumTechnologyLevel", 2);
    vehicleLightTankArmament("armament", HIGH_CALIBER_PROJECTILES);
    unitsBehavior(LIGHT_TANK, VEHICLE_BEHAVIOR);

    vehicleMediumTank("shootingFrequency", 0.5);
    vehicleMediumTank("reach", 7);
    vehicleMediumTank("structurePoints", 120);
    vehicleMediumTank("speedBase", 5);
    vehicleMediumTank("baseManufacturingTime", 18);
    vehicleMediumTank("minimumTechnologyLevel", 3);
    vehicleMediumTankArmament("armament", HIGH_CALIBER_PROJECTILES);
    unitsBehavior(MEDIUM_TANK, VEHICLE_BEHAVIOR);

    vehicleHeavyTank("shootingFrequency", 0.5);
    vehicleHeavyTank("reach", 8);
    vehicleHeavyTank("structurePoints", 180);
    vehicleHeavyTank("speedBase", 5);
    vehicleHeavyTank("baseManufacturingTime", 20);
    vehicleHeavyTank("minimumTechnologyLevel", 4);
    vehicleHeavyTankArmament("armament", HIGH_CALIBER_PROJECTILES);
    unitsBehavior(HEAVY_TANK, VEHICLE_BEHAVIOR);

    vehicleMML("shootingFrequency", 2);
    vehicleMML("reach", 8);
    vehicleMML("structurePoints", 200);
    vehicleMML("speedBase", 5);
    vehicleMML("baseManufacturingTime", 28);
    vehicleMML("minimumTechnologyLevel", 5);
    vehicleMMLArmament("armament", MISSILES);
    unitsBehavior(MML, VEHICLE_BEHAVIOR);

    units(GRUNT, robotGrunt);
    units(TOUGH, robotTough);
    units(SNIPER, robotSniper);
    units(PSYCHO, robotPsycho);
    units(PYRO, robotPyro);
    units(ROBOT_LASER, robotLaser);
    units(JEEP, vehicleJeep);
    units(LIGHT_TANK, vehicleLightTank);
    units(MML, vehicleMML);
    units(MEDIUM_TANK, vehicleMediumTank);
    units(HEAVY_TANK, vehicleHeavyTank);

    unitsArmament(GRUNT, robotGruntArmament);
    unitsArmament(TOUGH, robotToughArmament);
    unitsArmament(SNIPER, robotSniperArmament);
    unitsArmament(PSYCHO, robotPsychoArmament);
    unitsArmament(PYRO, robotPyroArmament);
    unitsArmament(ROBOT_LASER, robotLaserArmament);
    unitsArmament(JEEP, vehicleJeepArmament);
    unitsArmament(LIGHT_TANK, vehicleLightTankArmament);
    unitsArmament(MML, vehicleMMLArmament);
    unitsArmament(MEDIUM_TANK, vehicleMediumTankArmament);
    unitsArmament(HEAVY_TANK, vehicleHeavyTankArmament);

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
