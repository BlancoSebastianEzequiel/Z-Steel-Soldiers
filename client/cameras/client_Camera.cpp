#include <iostream>
#include "client_Camera.h"
//------------------------------------------------------------------------------
#define SCROLL_SPEED 50
#define WIDTH_LIMIT 64*20
#define HEIGHT_LIMIT 64*20
//------------------------------------------------------------------------------
// CLIENT CAMERA CONSTRUCTOR
//------------------------------------------------------------------------------
ClientCamera::ClientCamera(): pos_x(0), pos_y(0) {
    camera.x = 0;
    camera.y = 0;
    camera.w = 0;
    camera.h = 0;
}
//------------------------------------------------------------------------------
// GET X
//------------------------------------------------------------------------------
unsigned int ClientCamera::get_x() {
    return pos_x;
}
//------------------------------------------------------------------------------
// GET Y
//------------------------------------------------------------------------------
unsigned int ClientCamera::get_y() {
    return pos_y;
}
//------------------------------------------------------------------------------
// MOVE X
//------------------------------------------------------------------------------
void ClientCamera::move_x(unsigned int dest_x) {
    if ((short int)dest_x <= screen->w) {
        // Ya verifique que no me salgo de pantalla
        // 640 es el ancho del mapa en pixeles
        if (dest_x >=0.90*camera.w &&
            pos_x + camera.w + SCROLL_SPEED <= WIDTH_LIMIT) {
            // Si llegue hasta cierto punto hago el scroll hacia la derecha
            this->pos_x += SCROLL_SPEED;
        }
        if (dest_x <= 0.10*camera.w && pos_x > 0) {
            // Si llegue hasta cierto punto hago el scroll hacia la izquierda
            this->pos_x -= SCROLL_SPEED;
        }
    }
}
//------------------------------------------------------------------------------
// MOVE Y
//------------------------------------------------------------------------------
void ClientCamera::move_y(unsigned int dest_y) {
    if ((short int)dest_y <= screen->h) {
        // Ya verifique que no me salgo de pantalla
        if (dest_y >= 0.90*camera.h &&
            pos_y + camera.h + SCROLL_SPEED <= HEIGHT_LIMIT) {
            // Si llegue hasta cierto punto hago el scroll hacia abajo
            this->pos_y += SCROLL_SPEED;
        }
        if (dest_y <= 0.10*camera.h && pos_y > 0) {
            // Si llegue hasta cierto punto hago el scroll arriba
            this->pos_y -= SCROLL_SPEED;
        }
    }
}
//------------------------------------------------------------------------------
// GET CAMERA
//------------------------------------------------------------------------------
SDL_Rect* ClientCamera::get_camera() {
    return &this->camera;
}
//------------------------------------------------------------------------------
// SET SCREEN
//------------------------------------------------------------------------------
void ClientCamera::set_screen(SDL_Surface* screen) {
    this->camera.w = screen->w;
    this->camera.h = screen->h;
    this->screen = screen;
}
//------------------------------------------------------------------------------
// KEYWORD MOVE X
//------------------------------------------------------------------------------
void ClientCamera::keyboard_move_x(bool right) {
    if (right) {
        if (pos_x + camera.w + SCROLL_SPEED <= WIDTH_LIMIT) {
            this->pos_x+= SCROLL_SPEED;
        }
    } else if (pos_x > 0) {
        this->pos_x-= SCROLL_SPEED;
    }
}
//------------------------------------------------------------------------------
// KEYWORD MOVE Y
//------------------------------------------------------------------------------
void ClientCamera::keyboard_move_y(bool up) {
    if (up) {
        if (pos_y > 0) {
            this->pos_y -= SCROLL_SPEED;
        }
    } else if (pos_y + camera.h + SCROLL_SPEED <= HEIGHT_LIMIT) {
        this->pos_y += SCROLL_SPEED;
    }
}
//------------------------------------------------------------------------------
