#include <iostream>
#include "client_VFactoryInterface.h"
#include "client_BuildingInterface.h"
#include "../buttons/client_CreateLightTankButton.h"
#include "../buttons/client_CreateMediumTankButton.h"
#include "../buttons/client_CreateJeepButton.h"
#include "../buttons/client_CreateHeavyTankButton.h"
#include "../buttons/client_CreateMMLButton.h"
//------------------------------------------------------------------------------
// CLIENT V FACTORY INTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
ClientVFactoryInterface::ClientVFactoryInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        ClientBuildingInterface(id, pos_x, pos_y, tech_level) {
    std::string string = PATH_TO_IMAGE;
    string += "Buildings/Interface/vehicle_factory_menu.png";
    current_frame = new Frame(string);
     if (tech_level >= 1) {
        // Jeep
        buttons.push_back(new ClientCreateJeepButton(id, pos_x, pos_y + 20));
    }
    if (tech_level >= 2) {
        // Lighttank
        buttons.push_back(new ClientCreateLightTankButton(
                id, pos_x + 55, pos_y+ 20));
    }
    if (tech_level >= 3) {
        // Medium tank y Sniper
        buttons.push_back(new ClientCreateMediumTankButton(
                id, pos_x, pos_y+ 40));
    }
    if (tech_level >= 4) {
        // HeavyTank y Pyro
        buttons.push_back(new ClientCreateHeavyTankButton(
                id, pos_x + 55, pos_y + 40));
    }
    if (tech_level >= 5) {
        // MML y Laser
        buttons.push_back(new ClientCreateMMLButton(id, pos_x, pos_y + 60));
    }
}
//------------------------------------------------------------------------------
