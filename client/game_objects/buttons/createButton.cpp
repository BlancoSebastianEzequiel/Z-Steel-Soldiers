#include <iostream>
#include "createButton.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE BUTTON
//------------------------------------------------------------------------------
CreateButton::CreateButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
    Button(id, pos_x, pos_y) {
    frames.push_back(Frame("Buildings/Buttons/create_button.png"));
    frames.push_back(Frame("Buildings/Buttons/create_button_pressed.png"));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// CLIENT CREATE BUTTON
//------------------------------------------------------------------------------
void CreateButton::handle_click(ProxyGame &proxyGame) {
    std::cout << "Hola Mundo !" << std::endl;
    current_frame = &frames[1];
}
//------------------------------------------------------------------------------
