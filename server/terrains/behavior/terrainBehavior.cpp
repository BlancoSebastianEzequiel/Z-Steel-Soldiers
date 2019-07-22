#include "terrainBehavior.h"
#include "groundBehavior.h"
#include "lavaBehavior.h"
#include "waterBehavior.h"
#include "roadsBehavior.h"
#include "../../../libs/definitions.h"

TerrainBehavior::TerrainBehavior(const terrain_t &settings, size_t type):
    terrainSettings(settings), type(type) {
    anObject = nullptr;
    hasAnObject = false;
    groundFactor = settings["groundFactor"];
}

TerrainBehavior::~TerrainBehavior() {}

size_t TerrainBehavior::getType() const {
    return type;
}

void TerrainBehavior::addGroundObject(Object *anObjectToAdd) {
    anObject = anObjectToAdd;
    hasAnObject = true;
}

const Object *TerrainBehavior::getGroundObject() const {
    return anObject;
}

bool TerrainBehavior::hasAGroundObject() const {
    return hasAnObject;
}

float TerrainBehavior::getGroundFactor() const {
    return groundFactor;
}

TerrainBehavior* TerrainBehavior::getInstance(
        const unit_t &settings, size_t type) {
    size_t behavior = (size_t) settings["behavior"];
    if (behavior == LAVA_BEHAVIOR) {
        return new LavaBehavior(settings, type);
    } else if (behavior == GROUND_BEHAVIOR) {
        return new GroundBehavior(settings, type);
    } else if (behavior == ROADS_BEHAVIOR) {
        return new RoadsBehavior(settings, type);
    } else if (behavior == WATER_BEHAVIOR) {
        return new WaterBehavior(settings, type);
    } else {
        throw Exception("wrong type behavior");
    }
}
