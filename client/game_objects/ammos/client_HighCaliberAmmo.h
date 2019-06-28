#ifndef CLIENT_HIGHCALIBERAMMO_H_INCLUDED
#define CLIENT_HIGHCALIBERAMMO_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_Ammo.h"
//------------------------------------------------------------------------------
class ClientHighCaliberAmmo: public ClientAmmo {
 private :
    //--------------------------------------------------------------------------
    // Alterna los fotogramas de la bala moviendose en horizontal
    void move_x(unsigned int dest_x, double speed);
    //--------------------------------------------------------------------------
    // Alterna los fotogramas de la bala moviendose en vertical
    void move_y(unsigned int dest_y, double speed);
    //--------------------------------------------------------------------------
    // Alterna los fotogramas de la bala moviendose en diagonal
    void move_xy(unsigned int dest_x, unsigned int dest_y, double speed);
    //--------------------------------------------------------------------------
 public :
    ClientHighCaliberAmmo(unsigned int id, Unit* shooter, GameObject* target);
    //--------------------------------------------------------------------------
    ClientExplosion* get_explosion(unsigned int explosion_id);
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_HIGHCALIBERAMMO_H_INCLUDED
