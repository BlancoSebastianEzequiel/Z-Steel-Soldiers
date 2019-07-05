#include <iostream>
#include "client_FortInterface.h"
#include "client_BuildingInterface.h"
#include "../buttons/client_CreateGruntButton.h"
#include "../buttons/client_CreateLaserButton.h"
#include "../buttons/client_CreatePsychoButton.h"
#include "../buttons/client_CreatePyroButton.h"
#include "../buttons/client_CreateToughButton.h"
#include "../buttons/client_CreateSniperButton.h"
#include "../buttons/client_CreateLightTankButton.h"
#include "../buttons/client_CreateMediumTankButton.h"
#include "../buttons/client_CreateJeepButton.h"
#include "../buttons/client_CreateHeavyTankButton.h"
#include "../buttons/client_CreateMMLButton.h"
//------------------------------------------------------------------------------
// CLIENT FORTINTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
ClientFortInterface::ClientFortInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        ClientBuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/fort_menu.png");
    if (tech_level >= 1) {
        // Jeep y Grunt
        buttons.push_back(new ClientCreateGruntButton(id, pos_x, pos_y + 20));
        buttons.push_back(
                new ClientCreateJeepButton(id, pos_x + 55, pos_y + 20));
    }
    if (tech_level >= 2) {
        // Lighttank, Psycho y Tough
        buttons.push_back(
                new ClientCreateLightTankButton(id, pos_x + 55, pos_y + 40));
        buttons.push_back(new ClientCreatePsychoButton(id, pos_x , pos_y + 40));
        buttons.push_back(new ClientCreateToughButton(id, pos_x, pos_y + 60));
    }
    if (tech_level >= 3) {
        // Medium tank y Sniper
         buttons.push_back(
                 new ClientCreateMediumTankButton(id, pos_x + 55, pos_y + 60));
         buttons.push_back(new ClientCreateSniperButton(id, pos_x, pos_y + 80));
    }
    if (tech_level >= 4) {
        // HeavyTank y Pyro
         buttons.push_back(
                 new ClientCreateHeavyTankButton(id, pos_x + 55, pos_y + 80));
         buttons.push_back(new ClientCreatePyroButton(id, pos_x, pos_y + 100));
    }
    if (tech_level >= 5) {
        // MML y Laser
        buttons.push_back(
                new ClientCreateMMLButton(id, pos_x + 55, pos_y + 100));
        buttons.push_back(new ClientCreateLaserButton(id, pos_x, pos_y + 120));
    }
}
//------------------------------------------------------------------------------
