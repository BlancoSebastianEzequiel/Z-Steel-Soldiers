#ifndef MISSILE_AMMO_H
#define MISSILE_AMMO_H
//------------------------------------------------------------------------------
#include "ammo.h"
//------------------------------------------------------------------------------
class MissileAmmo: public Ammo {
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
    //--------------------------------------------------------------------------
    MissileAmmo(unsigned int id, Unit* shooter, GameObject* target);
    //--------------------------------------------------------------------------
    Explosion* get_explosion(unsigned int get_explosion);
    //--------------------------------------------------------------------------
};
#endif // MISSILE_AMMO_H
