#include <iostream>
#include "fortInterface.h"
#include "buildingInterface.h"
#include "../buttons/createButton.h"
#include "../../../libs/definitions.h"

FortInterface::FortInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        BuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/fort_menu.png");
    if (tech_level >= 1) {
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 20, GRUNT));
        buttons.push_back(new CreateButton(id, pos_x + 55, pos_y + 20, JEEP));
    }
    if (tech_level >= 2) {
        buttons.push_back(
                new CreateButton(id, pos_x + 55, pos_y + 40, LIGHT_TANK));
        buttons.push_back(new CreateButton(id, pos_x , pos_y + 40, PSYCHO));
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 60, TOUGH));
    }
    if (tech_level >= 3) {
         buttons.push_back(
                 new CreateButton(id, pos_x + 55, pos_y + 60, MEDIUM_TANK));
         buttons.push_back(new CreateButton(id, pos_x, pos_y + 80, SNIPER));
    }
    if (tech_level >= 4) {
         buttons.push_back(
                 new CreateButton(id, pos_x + 55, pos_y + 80, HEAVY_TANK));
         buttons.push_back(new CreateButton(id, pos_x, pos_y + 100, PYRO));
    }
    if (tech_level >= 5) {
        buttons.push_back(
                new CreateButton(id, pos_x + 55, pos_y + 100, MML));
        buttons.push_back(
                new CreateButton(id, pos_x, pos_y + 120, ROBOT_LASER));
    }
}
