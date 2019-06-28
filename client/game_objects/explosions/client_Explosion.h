#ifndef CLIENT_EXPLOSION_H_INCLUDED
#define CLIENT_EXPLOSION_H_INCLUDED
//------------------------------------------------------------------------------
#include <vector>
#include "../client_GameObject.h"
//------------------------------------------------------------------------------
class ClientExplosion: public GameObject {
 protected :
    unsigned int id;
    std::vector<Frame> frames;
    unsigned int frame_index;
    bool done;
 public :
    //--------------------------------------------------------------------------
    ClientExplosion(unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    ~ClientExplosion();
    //--------------------------------------------------------------------------
    // Devuelve true si la explosion termino de mostrar su ultimo fotograma
    bool finished();
    //--------------------------------------------------------------------------
    // Dibuja en la escena la explosion
    void draw(SDL_Surface* surface, ClientCamera& camera);
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_EXPLOSION_H_INCLUDED
