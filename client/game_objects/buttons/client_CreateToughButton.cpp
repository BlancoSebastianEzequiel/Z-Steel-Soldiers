#include <iostream>
#include "client_CreateToughButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE TOUGH BUTTON
//------------------------------------------------------------------------------
ClientCreateToughButton::ClientCreateToughButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_tough_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void ClientCreateToughButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createRobotTough(id);
    }
}
//------------------------------------------------------------------------------
