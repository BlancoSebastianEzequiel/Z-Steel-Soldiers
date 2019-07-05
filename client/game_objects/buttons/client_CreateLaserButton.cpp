//------------------------------------------------------------------------------
#include <iostream>
#include "client_CreateLaserButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE LASER BUTTON CONSTRUCTOR
//------------------------------------------------------------------------------
ClientCreateLaserButton::ClientCreateLaserButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        ClientButton(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_laser_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void ClientCreateLaserButton::handle_click(ClientProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createRobotLaser(id);
    }
}
//------------------------------------------------------------------------------
