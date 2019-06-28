#ifndef CLIENT_ICEBLOCK_H_INCLUDED
#define CLIENT_ICEBLOCK_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_TerrainObject.h"
#include "../../cameras/client_Camera.h"
//------------------------------------------------------------------------------
class ClientIceBlock: public TerrainObject {
 private :
    bool visible;
 public :
    //--------------------------------------------------------------------------
    ClientIceBlock(
            unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y);
    //--------------------------------------------------------------------------
    // Simplemente el bloque deja de ser visible
    void destroy();
    //--------------------------------------------------------------------------
    bool is_destroyed();
    //--------------------------------------------------------------------------
    void draw(SDL_Surface* screen, ClientCamera& camera);
    //--------------------------------------------------------------------------
    // Devuelve true si el objeto sobre el terreno puede ser atacado,
    // pueden ser atacados los puentes, las rocas y bloques de hielo
    // unicamente
    bool can_be_attacked();
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_ICEBLOCK_H_INCLUDED
