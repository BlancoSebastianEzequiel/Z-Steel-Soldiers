#ifndef CLIENT_BIGEXPLOSION_H_INCLUDED
#define CLIENT_BIGEXPLOSION_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_Explosion.h"
//------------------------------------------------------------------------------
class ClientBigExplosion: public ClientExplosion {
 public :
    //--------------------------------------------------------------------------
    ClientBigExplosion(unsigned int id,unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_BIGEXPLOSION_H_INCLUDED
