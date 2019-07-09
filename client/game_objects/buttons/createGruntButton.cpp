#include <iostream>
#include "createGruntButton.h"
#include "../../proxys/proxyGame.h"
#include "../../../libs/definitions.h"
//------------------------------------------------------------------------------
// CLIENT CRATE GRUNT BUTTON
//------------------------------------------------------------------------------
CreateGruntButton::CreateGruntButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        Button(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_grunt_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void CreateGruntButton::handle_click(ProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createRobot(id, GRUNT);
    }
}
//------------------------------------------------------------------------------
