#ifndef CLIENT_ROCK_H_INCLUDED
#define CLIENT_ROCK_H_INCLUDED
//------------------------------------------------------------------------------
#include "terrainObject.h"
#include "../../cameras/camera.h"
//------------------------------------------------------------------------------
class Rock: public TerrainObject {
 private :
    bool visible;
 public :
    //--------------------------------------------------------------------------
    Rock(
            unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y);
    void destroy();
    //--------------------------------------------------------------------------
    bool is_destroyed();
    //--------------------------------------------------------------------------
    void draw(SDL_Surface* screen, Camera& camera);
    //--------------------------------------------------------------------------
    // Devuelve true si el objeto sobre el terreno puede ser atacado,
    // pueden ser atacados los puentes, las rocas y bloques de hielo
    // unicamente
    bool can_be_attacked();
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_ROCK_H_INCLUDED
