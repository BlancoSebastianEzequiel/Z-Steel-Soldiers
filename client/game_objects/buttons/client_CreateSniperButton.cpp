#include <iostream>
#include "client_CreateSniperButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE SNIPER BUTTON
//------------------------------------------------------------------------------
ClientCreateSniperButton::ClientCreateSniperButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_sniper_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void ClientCreateSniperButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createRobotSniper(id);
    }
}
//------------------------------------------------------------------------------
