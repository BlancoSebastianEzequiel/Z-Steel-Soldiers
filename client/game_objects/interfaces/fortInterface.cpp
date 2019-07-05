#include <iostream>
#include "fortInterface.h"
#include "buildingInterface.h"
#include "../buttons/createGruntButton.h"
#include "../buttons/createLaserButton.h"
#include "../buttons/createPsychoButton.h"
#include "../buttons/createPyroButton.h"
#include "../buttons/createToughButton.h"
#include "../buttons/createSniperButton.h"
#include "../buttons/createLightTankButton.h"
#include "../buttons/createMediumTankButton.h"
#include "../buttons/createJeepButton.h"
#include "../buttons/createHeavyTankButton.h"
#include "../buttons/createMMLButton.h"
//------------------------------------------------------------------------------
// CLIENT FORTINTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
FortInterface::FortInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        BuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/fort_menu.png");
    if (tech_level >= 1) {
        // Jeep y Grunt
        buttons.push_back(new CreateGruntButton(id, pos_x, pos_y + 20));
        buttons.push_back(
                new CreateJeepButton(id, pos_x + 55, pos_y + 20));
    }
    if (tech_level >= 2) {
        // Lighttank, Psycho y Tough
        buttons.push_back(
                new CreateLightTankButton(id, pos_x + 55, pos_y + 40));
        buttons.push_back(new CreatePsychoButton(id, pos_x , pos_y + 40));
        buttons.push_back(new CreateToughButton(id, pos_x, pos_y + 60));
    }
    if (tech_level >= 3) {
        // Medium tank y Sniper
         buttons.push_back(
                 new CreateMediumTankButton(id, pos_x + 55, pos_y + 60));
         buttons.push_back(new CreateSniperButton(id, pos_x, pos_y + 80));
    }
    if (tech_level >= 4) {
        // HeavyTank y Pyro
         buttons.push_back(
                 new CreateHeavyTankButton(id, pos_x + 55, pos_y + 80));
         buttons.push_back(new CreatePyroButton(id, pos_x, pos_y + 100));
    }
    if (tech_level >= 5) {
        // MML y Laser
        buttons.push_back(
                new CreateMMLButton(id, pos_x + 55, pos_y + 100));
        buttons.push_back(new CreateLaserButton(id, pos_x, pos_y + 120));
    }
}
//------------------------------------------------------------------------------
