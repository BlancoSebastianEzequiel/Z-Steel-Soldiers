#include <iostream>
#include "createToughButton.h"
#include "../../proxys/proxyGame.h"
#include "../../../libs/definitions.h"
//------------------------------------------------------------------------------
// CLIENT CREATE TOUGH BUTTON
//------------------------------------------------------------------------------
CreateToughButton::CreateToughButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        Button(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_tough_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void CreateToughButton::handle_click(ProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createUnit(id, TOUGH);
    }
}
//------------------------------------------------------------------------------
