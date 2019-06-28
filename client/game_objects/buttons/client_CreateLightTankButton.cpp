#include <iostream>
#include "client_CreateLightTankButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE LIGHT BUTTON
//------------------------------------------------------------------------------
ClientCreateLightTankButton::ClientCreateLightTankButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_light_button.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_button_pressed.png";
    frames.push_back(Frame(path));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void ClientCreateLightTankButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        // el id coincide con el del building que coincide con el del interface
        proxyGame.createVehicleLightTank(id);
    }
}
//------------------------------------------------------------------------------
