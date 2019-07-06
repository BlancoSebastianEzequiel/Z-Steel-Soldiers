#ifndef CAMERA_H
#define CAMERA_H
//------------------------------------------------------------------------------
#include <SDL/SDL.h>
//------------------------------------------------------------------------------
class Camera {
 private :
    unsigned int pos_x;
    unsigned int pos_y;
    SDL_Surface* screen;
    SDL_Rect camera;
 public :
    //--------------------------------------------------------------------------
    Camera();
    //--------------------------------------------------------------------------
    unsigned int get_x();
    //--------------------------------------------------------------------------
    unsigned int get_y();
    //--------------------------------------------------------------------------
    void move_x(unsigned int dest_x);
    //--------------------------------------------------------------------------
    void move_y(unsigned int dest_y);
    //--------------------------------------------------------------------------
    SDL_Rect* get_camera();
    //--------------------------------------------------------------------------
    void set_screen(SDL_Surface* screen);
    //--------------------------------------------------------------------------
    // Desplaza la camara para la derecha o izquierda segun el parametro
    // recibido, esta pensado para ser usado por el teclado
    void keyboard_move_x(bool right);
    //--------------------------------------------------------------------------
    // Desplaza la camara para arribia o abajo segun el parametro
    // recibido, esta pensado para ser usado por el teclado
    void keyboard_move_y(bool up);
    //--------------------------------------------------------------------------
};
#endif  // CAMERA_H
