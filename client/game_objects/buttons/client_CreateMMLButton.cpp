#include "client_CreateMMLButton.h"
#include "../../proxys/clientProxyGame.h"
#include <iostream>
//------------------------------------------------------------------------------
// CLIENT CREATE MML BUTTON
//------------------------------------------------------------------------------
ClientCreateMMLButton::ClientCreateMMLButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_mml_button.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_button_pressed.png";
    frames.push_back(Frame(path));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void ClientCreateMMLButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createVehicleMML(id);
    }
}
//------------------------------------------------------------------------------
