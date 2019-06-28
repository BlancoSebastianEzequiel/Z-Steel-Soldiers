#include <iostream>
#include "client_CreateHeavyTankButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE HEAVY TANK BUTTON
//------------------------------------------------------------------------------
ClientCreateHeavyTankButton::ClientCreateHeavyTankButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_heavy_button.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_button_pressed.png";
    frames.push_back(Frame(path));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void ClientCreateHeavyTankButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createVehicleHeavyTank(id);
    }
}
//------------------------------------------------------------------------------
