#include <iostream>
#include "client_RFactoryInterface.h"
#include "client_BuildingInterface.h"
#include "../buttons/client_CreateGruntButton.h"
#include "../buttons/client_CreateLaserButton.h"
#include "../buttons/client_CreatePsychoButton.h"
#include "../buttons/client_CreatePyroButton.h"
#include "../buttons/client_CreateToughButton.h"
#include "../buttons/client_CreateSniperButton.h"
//------------------------------------------------------------------------------
// CLIENT R FACTORY INTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
ClientRFactoryInterface::ClientRFactoryInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        ClientBuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/robot_factory_menu.png");
    if (tech_level >= 1) {
        // Grunt
        buttons.push_back(new ClientCreateGruntButton(id, pos_x, pos_y + 20));
    }
    if (tech_level >= 2) {
        // Psycho y Tough
        buttons.push_back(new ClientCreatePsychoButton(
                id, pos_x + 55, pos_y + 20));
        buttons.push_back(new ClientCreateToughButton(id, pos_x, pos_y + 40));
    }
    if (tech_level >= 3) {
        // Sniper
        buttons.push_back(new ClientCreateSniperButton(
                id, pos_x + 55, pos_y + 40));
    }
    if (tech_level >= 4) {
        // Pyro
        buttons.push_back(new ClientCreatePyroButton(id, pos_x, pos_y + 60));
    }
    if (tech_level >= 5) {
        // Laser
        buttons.push_back(new ClientCreateLaserButton(
                id, pos_x + 55, pos_y + 60));
    }
}
//------------------------------------------------------------------------------
