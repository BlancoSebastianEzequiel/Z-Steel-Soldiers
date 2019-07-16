#include  <vector>
#include <iostream>
#include "buildingInterface.h"
#include "../buttons/button.h"
//------------------------------------------------------------------------------
using std::vector;
//------------------------------------------------------------------------------
// CLIENT BUILDING INTERFACE CONSTRUCTOR
//------------------------------------------------------------------------------
BuildingInterface::BuildingInterface(
        unsigned int id, unsigned int pos_x, unsigned int pos_y,
        unsigned int tech_level):
        GameObject(id, pos_x, pos_y), visible(false) {}
//------------------------------------------------------------------------------
// CLIENT BUILDING INTERFACE DESTRUCTOR
//------------------------------------------------------------------------------
BuildingInterface::~BuildingInterface() {
    for (Button* & button : buttons) {
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
void BuildingInterface::show() {
    visible = true;
    for (Button* & button : buttons) {
        // muestro todos los botones de la interfaz
        button->show();
    }
}
//------------------------------------------------------------------------------
// HIDE
//------------------------------------------------------------------------------
void BuildingInterface::hide() {
    visible = false;
    for (Button* & button : buttons) {
        // oculto todos los botones de la interfaz
        button->hide();
    }
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void BuildingInterface::draw(SDL_Surface* screen, Camera& camera) {
    if (visible) {
        GameObject::draw(screen, camera);
    }
    for (Button* & button : buttons) {
        // muestro todos los botones de la interfaz
        button->draw(screen, camera);
    }
}
//------------------------------------------------------------------------------
// CHECK BUTTON PRESSED
//------------------------------------------------------------------------------
void
BuildingInterface::check_button_pressed(
   unsigned int mouse_x, unsigned int mouse_y, ProxyGame &proxyGame) {
    if (visible) {
        for (Button* & button : buttons) {
            if (button->is_selected(mouse_x, mouse_y)) {
                button->handle_click(proxyGame);
            }
        }
    }
}
//------------------------------------------------------------------------------
