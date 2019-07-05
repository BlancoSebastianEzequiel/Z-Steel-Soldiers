#include "createMediumTankButton.h"
#include "../../proxys/proxyGame.h"
#include <iostream>
//------------------------------------------------------------------------------
// CLIENT CREATE MEDIUM TANK BUTTON
//------------------------------------------------------------------------------
CreateMediumTankButton::CreateMediumTankButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        Button(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_medium_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// CLIENT CREATE MEDIUM TANK BUTTON
//------------------------------------------------------------------------------
void CreateMediumTankButton::handle_click(ProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createVehicleMediumTank(id);
    }
}
//------------------------------------------------------------------------------
