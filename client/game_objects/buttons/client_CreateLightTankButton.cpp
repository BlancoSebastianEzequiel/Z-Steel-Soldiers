#include <iostream>
#include "client_CreateLightTankButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE LIGHT BUTTON
//------------------------------------------------------------------------------
ClientCreateLightTankButton::ClientCreateLightTankButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_light_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
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
