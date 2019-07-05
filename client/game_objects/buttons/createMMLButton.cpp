#include "createMMLButton.h"
#include "../../proxys/proxyGame.h"
#include <iostream>
//------------------------------------------------------------------------------
// CLIENT CREATE MML BUTTON
//------------------------------------------------------------------------------
CreateMMLButton::CreateMMLButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        Button(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_mml_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// HANDLE CLICK
//------------------------------------------------------------------------------
void CreateMMLButton::handle_click(ProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createVehicleMML(id);
    }
}
//------------------------------------------------------------------------------
