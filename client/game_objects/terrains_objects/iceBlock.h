#ifndef CLIENT_ICEBLOCK_H_INCLUDED
#define CLIENT_ICEBLOCK_H_INCLUDED
//------------------------------------------------------------------------------
#include "terrainObject.h"
#include "../../cameras/camera.h"
//------------------------------------------------------------------------------
class IceBlock: public TerrainObject {
 private :
    bool visible;
 public :
    //--------------------------------------------------------------------------
    IceBlock(
            unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y);
    //--------------------------------------------------------------------------
    // Simplemente el bloque deja de ser visible
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
#endif  // CLIENT_ICEBLOCK_H_INCLUDED
