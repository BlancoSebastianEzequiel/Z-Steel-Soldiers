#ifndef LITTLE_EXPLOSION_H
#define LITTLE_EXPLOSION_H
//------------------------------------------------------------------------------
#include "explosion.h"
//------------------------------------------------------------------------------
class LittleExplosion: public Explosion {
 public :
    //--------------------------------------------------------------------------
    LittleExplosion(
            unsigned int id,unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
};
#endif // LITTLE_EXPLOSION_H
