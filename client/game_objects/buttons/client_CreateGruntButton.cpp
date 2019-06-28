#include <iostream>
#include "client_CreateGruntButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CRATE GRUNT BUTTON
//------------------------------------------------------------------------------
ClientCreateGruntButton::ClientCreateGruntButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_grunt_button.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_button_pressed.png";
    frames.push_back(Frame(path));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void ClientCreateGruntButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createRobotGrunt(id);
    }
}
//------------------------------------------------------------------------------
