#ifndef LASER_H
#define LASER_H
//------------------------------------------------------------------------------
#include "robot.h"
#include "../../ammos/laserAmmo.h"
//------------------------------------------------------------------------------
class RobotLaser: public Robot {
 private :
    //--------------------------------------------------------------------------
    // Dispara a una posicion hacia la izquierda o derecha de la actual
    // dependiendo de si target_x>0 o target_x<0
    void shoot_x(GameObject* target);
    //--------------------------------------------------------------------------
    // Dispara a una posicion hacia arriba o abajo de la actual
    // dependiendo de si target_y>0 o target_y<0
    void shoot_y(GameObject* target);
    //--------------------------------------------------------------------------
    // Realiza un disparo en diagonal hacia el punto de coordenadas
    // pasadas por parametro.
    void shoot_xy(GameObject* target);
    //--------------------------------------------------------------------------
 public :
    //--------------------------------------------------------------------------
    RobotLaser(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y);
    //--------------------------------------------------------------------------
    // Devuelve un proyectil del tipo que dispare la unidad
    Ammo* get_bullet(
            unsigned int bullet_id, Unit* shooter, GameObject* target);
    //--------------------------------------------------------------------------
};
#endif  // LASER_H
