#include "client_CreateMediumTankButton.h"
#include "../../proxys/clientProxyGame.h"
#include <iostream>
//------------------------------------------------------------------------------
// CLIENT CREATE MEDIUM TANK BUTTON
//------------------------------------------------------------------------------
ClientCreateMediumTankButton::ClientCreateMediumTankButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_medium_button.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_button_pressed.png";
    frames.push_back(Frame(path));
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
