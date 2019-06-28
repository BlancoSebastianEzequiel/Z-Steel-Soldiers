#ifndef CLIENT_LITTLEEXPLOSION_H_INCLUDED
#define CLIENT_LITTLEEXPLOSION_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_Explosion.h"
//------------------------------------------------------------------------------
class ClientLittleExplosion: public ClientExplosion {
 public :
    //--------------------------------------------------------------------------
    ClientLittleExplosion(
            unsigned int id,unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_LITTLEEXPLOSION_H_INCLUDED
