#ifndef EXPLOSION_H
#define EXPLOSION_H
//------------------------------------------------------------------------------
#include <vector>
#include "../gameObject.h"
//------------------------------------------------------------------------------
class Explosion: public GameObject {
 protected :
    unsigned int id;
    std::vector<Frame> frames;
    unsigned int frame_index;
    bool done;
 public :
    //--------------------------------------------------------------------------
    Explosion(unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    ~Explosion();
    //--------------------------------------------------------------------------
    // Devuelve true si la explosion termino de mostrar su ultimo fotograma
    bool finished();
    //--------------------------------------------------------------------------
    // Dibuja en la escena la explosion
    void draw(SDL_Surface* surface, Camera& camera);
    //--------------------------------------------------------------------------
};
#endif  // EXPLOSION_H
