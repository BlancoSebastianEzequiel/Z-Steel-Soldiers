#include <iostream>
#include "RFactoryInterface.h"
#include "buildingInterface.h"
#include "../buttons/createButton.h"
#include "../../../libs/definitions.h"
//------------------------------------------------------------------------------
// CLIENT R FACTORY INTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
RFactoryInterface::RFactoryInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        BuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/robot_factory_menu.png");
    if (tech_level >= 1) {
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 20, GRUNT));
    }
    if (tech_level >= 2) {
        buttons.push_back(new CreateButton(id, pos_x + 55, pos_y + 20, PSYCHO));
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 40, TOUGH));
    }
    if (tech_level >= 3) {
        buttons.push_back(new CreateButton(id, pos_x + 55, pos_y + 40, SNIPER));
    }
    if (tech_level >= 4) {
        buttons.push_back(new CreateButton(id, pos_x, pos_y + 60, PYRO));
    }
    if (tech_level >= 5) {
        buttons.push_back(
                new CreateButton(id, pos_x + 55, pos_y + 60, ROBOT_LASER));
    }
}
//------------------------------------------------------------------------------
