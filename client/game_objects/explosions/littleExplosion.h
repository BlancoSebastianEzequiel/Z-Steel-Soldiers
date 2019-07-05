#ifndef CLIENT_LITTLEEXPLOSION_H_INCLUDED
#define CLIENT_LITTLEEXPLOSION_H_INCLUDED
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
#endif // CLIENT_LITTLEEXPLOSION_H_INCLUDED
