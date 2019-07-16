#include <iostream>
#include "createButton.h"
#include "../../proxys/proxyGame.h"
#include "../../../libs/definitions.h"

CreateButton::CreateButton(
        unsigned int id, unsigned int pos_x, unsigned int pos_y, size_t type):
    Button(id, pos_x, pos_y), type(type) {
    std::string path = "Buildings/Buttons/create_";
    path += unitsNames.at(type);
    path += "_button.png";
    frames.emplace_back(path);
    frames.emplace_back("Buildings/Buttons/create_button_pressed.png");
    current_frame = &frames[0];
}

void CreateButton::handle_click(ProxyGame &proxyGame) {
    if (visible) {
        proxyGame.createUnit(id, type);
    }
}
