#include  <vector>
#include <iostream>
#include "client_BuildingInterface.h"
#include "../buttons/client_CreateGruntButton.h"
#include "../buttons/client_CreateLaserButton.h"
#include "../buttons/client_CreateLightTankButton.h"
#include "../buttons/client_Button.h"
//------------------------------------------------------------------------------
using std::vector;
//------------------------------------------------------------------------------
// CLIENT BUILDING INTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
ClientBuildingInterface::ClientBuildingInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        GameObject(id, pos_x, pos_y), visible(false) {}
//------------------------------------------------------------------------------
// CLIENT BUILDING INTERFACE DESTRUCTOR
//------------------------------------------------------------------------------
ClientBuildingInterface::~ClientBuildingInterface() {
    for (ClientButton* & button : buttons) {
        delete button;
    }
    this->current_frame->unload();
    delete current_frame;
}
//******************************************************************************
// PUBLIC
//******************************************************************************
//------------------------------------------------------------------------------
// SHOW
//------------------------------------------------------------------------------
void ClientBuildingInterface::show() {
    visible = true;
    for (ClientButton* & button : buttons) {
        // muestro todos los botones de la interfaz
        button->show();
    }
}
//------------------------------------------------------------------------------
// HIDE
//------------------------------------------------------------------------------
void ClientBuildingInterface::hide() {
    visible = false;
    for (ClientButton* & button : buttons) {
        // oculto todos los botones de la interfaz
        button->hide();
    }
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void ClientBuildingInterface::draw(SDL_Surface* screen, ClientCamera& camera) {
    if (visible) {
        GameObject::draw(screen, camera);
    }
    for (ClientButton* & button : buttons) {
        // muestro todos los botones de la interfaz
        button->draw(screen, camera);
    }
}
//------------------------------------------------------------------------------
// CHECK BUTTON PRESSED
//------------------------------------------------------------------------------
void
ClientBuildingInterface::check_button_pressed(
   unsigned int mouse_x, unsigned int mouse_y, ClientProxyGame &proxyGame) {
    if (visible) {
        for (ClientButton* & button : buttons) {
            if (button->is_selected(mouse_x, mouse_y)) {
                button->handle_click(proxyGame);
            }
        }
    }
}
//------------------------------------------------------------------------------
