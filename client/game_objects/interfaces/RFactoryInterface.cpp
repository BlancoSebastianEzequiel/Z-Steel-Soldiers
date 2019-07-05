#include <iostream>
#include "RFactoryInterface.h"
#include "buildingInterface.h"
#include "../buttons/createGruntButton.h"
#include "../buttons/createLaserButton.h"
#include "../buttons/createPsychoButton.h"
#include "../buttons/createPyroButton.h"
#include "../buttons/createToughButton.h"
#include "../buttons/createSniperButton.h"
//------------------------------------------------------------------------------
// CLIENT R FACTORY INTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
RFactoryInterface::RFactoryInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        BuildingInterface(id, pos_x, pos_y, tech_level) {
    current_frame = new Frame("Buildings/Interface/robot_factory_menu.png");
    if (tech_level >= 1) {
        // Grunt
        buttons.push_back(new CreateGruntButton(id, pos_x, pos_y + 20));
    }
    if (tech_level >= 2) {
        // Psycho y Tough
        buttons.push_back(new CreatePsychoButton(
                id, pos_x + 55, pos_y + 20));
        buttons.push_back(new CreateToughButton(id, pos_x, pos_y + 40));
    }
    if (tech_level >= 3) {
        // Sniper
        buttons.push_back(new CreateSniperButton(
                id, pos_x + 55, pos_y + 40));
    }
    if (tech_level >= 4) {
        // Pyro
        buttons.push_back(new CreatePyroButton(id, pos_x, pos_y + 60));
    }
    if (tech_level >= 5) {
        // Laser
        buttons.push_back(new CreateLaserButton(
                id, pos_x + 55, pos_y + 60));
    }
}
//------------------------------------------------------------------------------
