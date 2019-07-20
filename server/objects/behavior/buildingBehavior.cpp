#include <cmath>
#include "buildingBehavior.h"
#include "../../maps/map.h"
#include "../../terrains/node.h"

extern Settings settings;

BuildingBehavior::BuildingBehavior(
        const object_t &buildingSettings, size_t type):
    ObjectBehavior(buildingSettings, type) {
    size_t unitType;
    float baseManufacturingTime;
    for (unit_t* aUnit: settings.units.getList()) {
        unitType = (size_t) (*aUnit)["id"];
        baseManufacturingTime = (*aUnit)["baseManufacturingTime"];
        unitManufacturingTime(unitType, baseManufacturingTime);
    }
}

BuildingBehavior::~BuildingBehavior() {}

double BuildingBehavior::manufacturingTime(
        size_t takenTerritories, size_t type) {
    float baseManufacturingTime = unitManufacturingTime[type];
    double a = baseManufacturingTime / takenTerritories;
    double b = std::sqrt(1 - getDamageStructureRel());
    return a / b;
}

bool BuildingBehavior::canPassThrough() {
    return false;
}

void BuildingBehavior::addObjectToNodes(
        Node &mainPos, Object &anObject, positions_t &positions) {
    uint32_t x = mainPos.getX();
    uint32_t y = mainPos.getY();
    std::vector<Node*> adjacents = mainPos.getAdjacent();
    uint32_t x_2, y_2;
    for (Node* aNode: adjacents) {
        x_2 = aNode->getX();
        y_2 = aNode->getY();
        if (x_2 == x+1 && y == y_2) {
            // right
            aNode->addGroundObject(&anObject);
            positions.push_back(aNode);
        } else if (x_2 == x && y == y_2+1) {
            // left
            aNode->addGroundObject(&anObject);
            positions.push_back(aNode);
        } else if (x_2 == x+1 && y == y_2+1) {
            // diagonal
            aNode->addGroundObject(&anObject);
            positions.push_back(aNode);
        }
    }
    mainPos.addGroundObject(&anObject);
    wasAdded = true;
}

void
BuildingBehavior::addAttributes(object_t attr, Map &aMap, Object &anObject) {
    techLevel = (size_t) attr["techLevel"];
}

object_t BuildingBehavior::getAttributes() {
    object_t attr;
    attr("techLevel", techLevel);
    return attr;
}

bool BuildingBehavior::isBuilding() {
    return true;
}
