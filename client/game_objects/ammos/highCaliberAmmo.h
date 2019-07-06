#ifndef HIGH_CALIBER_AMMO_H
#define HIGH_CALIBER_AMMO_H
//------------------------------------------------------------------------------
#include "ammo.h"
//------------------------------------------------------------------------------
class HighCaliberAmmo: public Ammo {
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
    HighCaliberAmmo(unsigned int id, Unit* shooter, GameObject* target);
    //--------------------------------------------------------------------------
    Explosion* get_explosion(unsigned int explosion_id);
    //--------------------------------------------------------------------------
};
#endif  // HIGH_CALIBER_AMMO_H
