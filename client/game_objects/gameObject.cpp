#include <iostream>
#include <vector>
#include "gameObject.h"
#include "../frames/frame.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//------------------------------------------------------------------------------
using std::vector;
//------------------------------------------------------------------------------
// GAME OBJECT CONSTRUCTOR
//------------------------------------------------------------------------------
GameObject::GameObject(
        unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y):
        pos_x(init_pos_x), pos_y(init_pos_y), id(id), container() {}
//------------------------------------------------------------------------------
// GAME OBJECT CONSTRUCTOR
//------------------------------------------------------------------------------
GameObject::GameObject(unsigned int init_pos_x, unsigned int init_pos_y):
        pos_x(init_pos_x), pos_y(init_pos_y) {}
//------------------------------------------------------------------------------
// GAME OBJECT DESTRUCTOR
//------------------------------------------------------------------------------
GameObject::~GameObject() {}
//------------------------------------------------------------------------------
// GET X
//------------------------------------------------------------------------------
unsigned int GameObject::get_x() {
    return pos_x;
}
//------------------------------------------------------------------------------
// GET Y
//------------------------------------------------------------------------------
unsigned int GameObject::get_y() {
    return pos_y;
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void GameObject::draw(SDL_Surface* screen, Camera& camera) {
    // Para mostrar una imagen primero debo almacenarla en un contenedor
    container.x = pos_x;
    container.y = pos_y;
    container.h = current_frame->get_image()->h;
    container.w = current_frame->get_image()->w;

    SDL_Rect source = {0, 0, (unsigned short)current_frame->get_image()->w,
                       (unsigned short)current_frame->get_image()->h};
    short rel_x = (short)(this->pos_x - camera.get_x());
    short rel_y = (short)(this->pos_y - camera.get_y());

    short dw = camera.get_camera()->w - rel_x;
    short dh = camera.get_camera()->h - rel_y;

    if (dw < 0) {
        dw = 0;
    }
    if (dh < 0) {
        dh = 0;
    }
    SDL_Rect dest = {rel_x, rel_y, (unsigned short)(dw), (unsigned short)(dh)};
    // Cargo el fotograma actual del sprite en la superficie pasada por
    // parametro, habitualmente es donde luego sera mostrado el sprite
    SDL_BlitSurface(current_frame->get_image(), &source, screen, &dest);
    // SDL_BlitSurface(current_frame->get_image(),NULL,screen,&container);
}
//------------------------------------------------------------------------------
// GET ID
//------------------------------------------------------------------------------
unsigned int GameObject::get_id() {
    return this->id;
}
//------------------------------------------------------------------------------
// SET ID
//------------------------------------------------------------------------------
void GameObject::set_id(unsigned int id) {
    this->id = id;
}
//------------------------------------------------------------------------------
// IS SELECTED
//------------------------------------------------------------------------------
bool GameObject::is_selected(int mouse_x, int mouse_y) {
    return (mouse_x >= container.x) && (mouse_y >= container.y) &&
            (mouse_x < container.x + container.w) &&
            (mouse_y < container.y + container.h);
}
//------------------------------------------------------------------------------
// IS UNIT
//------------------------------------------------------------------------------
bool GameObject::isUnit() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool GameObject::isBuilding() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TERRAIN OBJECT
//------------------------------------------------------------------------------
bool GameObject::isTerrainObject() const {
    return false;
}
//------------------------------------------------------------------------------
