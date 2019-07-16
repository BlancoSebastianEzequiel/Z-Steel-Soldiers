#include <iostream>
#include "VFactoryInterface.h"
#include "buildingInterface.h"
#include "../buttons/createButton.h"
#include "../../../libs/definitions.h"

VFactoryInterface::VFactoryInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        BuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/vehicle_factory_menu.png");
     if (tech_level >= 1) {
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 20, JEEP));
    }
    if (tech_level >= 2) {
        buttons.push_back(
                new CreateButton(id, pos_x + 55, pos_y+ 20, LIGHT_TANK));
    }
    if (tech_level >= 3) {
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 40, MEDIUM_TANK));
    }
    if (tech_level >= 4) {
        buttons.push_back(
                new CreateButton(id, pos_x + 55, pos_y + 40, HEAVY_TANK));
    }
    if (tech_level >= 5) {
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 60, MML));
    }
}
