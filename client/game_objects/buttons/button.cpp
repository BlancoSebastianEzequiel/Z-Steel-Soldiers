#include <iostream>
#include "button.h"
//------------------------------------------------------------------------------
// CLIENT BUTTON CONSTRUCTOR
//------------------------------------------------------------------------------
Button::Button(
        unsigned int id, unsigned int pos_x, unsigned int pos_y):
        GameObject(id, pos_x, pos_y), visible(false) {}
//------------------------------------------------------------------------------
// CLIENT BUTTON DESTRUCTOR
//------------------------------------------------------------------------------
Button::~Button() {
    for (unsigned int i = 0; i < frames.size(); i++) {
        frames[i].unload();
    }
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void Button::draw(SDL_Surface* screen, Camera& camera) {
    if (visible) {
        GameObject::draw(screen, camera);
    }
}
//------------------------------------------------------------------------------
// SHOW
//------------------------------------------------------------------------------
void Button::show() {
    visible = true;
}
//------------------------------------------------------------------------------
// HIDE
//------------------------------------------------------------------------------
void Button::hide() {
    visible = false;
}
//------------------------------------------------------------------------------