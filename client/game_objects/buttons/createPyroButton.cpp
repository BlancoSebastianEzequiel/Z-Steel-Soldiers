#include <iostream>
#include "createPyroButton.h"
#include "../../proxys/proxyGame.h"
#include "../../../libs/definitions.h"
//------------------------------------------------------------------------------
// CLIENT CREATE PYRO BUTTON
//------------------------------------------------------------------------------
CreatePyroButton::CreatePyroButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        Button(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_pyro_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void CreatePyroButton::handle_click(ProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createRobot(id, PYRO);
    }
}
//------------------------------------------------------------------------------
