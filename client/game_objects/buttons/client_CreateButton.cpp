#include <iostream>
#include "client_CreateButton.h"
#include "../../proxys/clientProxyGame.h"

//------------------------------------------------------------------------------
// CLIENT CREATE BUTTON
//------------------------------------------------------------------------------
ClientCreateButton::ClientCreateButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
    ClientButton(id, pos_x, pos_y) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_button.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/Buttons/create_button_pressed.png";
    frames.push_back(Frame(path));
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// CLIENT CREATE BUTTON
//------------------------------------------------------------------------------
void ClientCreateButton::handle_click(ClientProxyGame &proxyGame) {
    std::cout << "Hola Mundo !" << std::endl;
    current_frame = &frames[1];
}
//------------------------------------------------------------------------------
