#include <iostream>
#include "VFactoryInterface.h"
#include "buildingInterface.h"
#include "../buttons/createLightTankButton.h"
#include "../buttons/createMediumTankButton.h"
#include "../buttons/createJeepButton.h"
#include "../buttons/createHeavyTankButton.h"
#include "../buttons/createMMLButton.h"
//------------------------------------------------------------------------------
// CLIENT V FACTORY INTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
VFactoryInterface::VFactoryInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        BuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/vehicle_factory_menu.png");
     if (tech_level >= 1) {
        // Jeep
        buttons.push_back(new CreateJeepButton(id, pos_x, pos_y + 20));
    }
    if (tech_level >= 2) {
        // Lighttank
        buttons.push_back(new CreateLightTankButton(
                id, pos_x + 55, pos_y+ 20));
    }
    if (tech_level >= 3) {
        // Medium tank y Sniper
        buttons.push_back(new CreateMediumTankButton(
                id, pos_x, pos_y+ 40));
    }
    if (tech_level >= 4) {
        // HeavyTank y Pyro
        buttons.push_back(new CreateHeavyTankButton(
                id, pos_x + 55, pos_y + 40));
    }
    if (tech_level >= 5) {
        // MML y Laser
        buttons.push_back(new CreateMMLButton(id, pos_x, pos_y + 60));
    }
}
//------------------------------------------------------------------------------
