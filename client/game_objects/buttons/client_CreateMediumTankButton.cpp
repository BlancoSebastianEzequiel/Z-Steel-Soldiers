#include "client_CreateMediumTankButton.h"
#include "../../proxys/clientProxyGame.h"
#include <iostream>
//------------------------------------------------------------------------------
// CLIENT CREATE MEDIUM TANK BUTTON
//------------------------------------------------------------------------------
ClientCreateMediumTankButton::ClientCreateMediumTankButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_medium_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// CLIENT CREATE MEDIUM TANK BUTTON
//------------------------------------------------------------------------------
void ClientCreateMediumTankButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createVehicleMediumTank(id);
    }
}
//------------------------------------------------------------------------------
