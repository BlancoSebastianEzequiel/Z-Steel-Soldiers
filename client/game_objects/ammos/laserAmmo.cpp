#include <iostream>
#include "ammo.h"
#include "laserAmmo.h"
#include "../gameObject.h"
#include "../explosions/littleExplosion.h"
//------------------------------------------------------------------------------
// CLIENT LASER AMMO
//------------------------------------------------------------------------------
LaserAmmo::LaserAmmo(
        unsigned int bullet_id, Unit* shooter, GameObject* target):
        Ammo(bullet_id, shooter, target) {
    x_frames.push_back(Frame("Units/Robots/Laser/laser_shoot_0.bmp"));
    y_frames.push_back(Frame("Units/Robots/Laser/laser_shoot_90.bmp"));
    xy_frames.push_back(Frame("Units/Robots/Laser/laser_shoot_45.bmp"));
    xy_frames.push_back(Frame("Units/Robots/Laser/laser_shoot_135.bmp"));
    current_frame = &xy_frames[0];
}
//------------------------------------------------------------------------------
// MOVE X
//------------------------------------------------------------------------------
void LaserAmmo::move_x(unsigned int dest_x, double speed) {
    current_frame = &x_frames[0];
    Ammo::move_x(dest_x, speed);
}
//------------------------------------------------------------------------------
// MOVE Y
//------------------------------------------------------------------------------
void LaserAmmo::move_y(unsigned int dest_y, double speed) {
    current_frame = &y_frames[0];
    Ammo::move_y(dest_y, speed);
}
//------------------------------------------------------------------------------
// MOVE XY
//------------------------------------------------------------------------------
void LaserAmmo::move_xy(
        unsigned int dest_x, unsigned int dest_y, double speed) {
    if ((pos_x < dest_x && pos_y < dest_y)||(pos_x > dest_x && pos_y>dest_y)) {
        // diagonal hacia abajo y derecha
        if (frame_index < 1){
            frame_index = 1;
        }
    }

    if ((pos_x < dest_x && pos_y > dest_y)||(pos_x > dest_x && pos_y< dest_y)) {
        // diagonal hacia arriba y derecha
        if (frame_index > 0){
        frame_index = 0;
        }
    }
    current_frame = &xy_frames[frame_index];
    Ammo::move_xy(dest_x, dest_y, speed);
}
//------------------------------------------------------------------------------
// GET EXPLOSION
//------------------------------------------------------------------------------
Explosion* LaserAmmo::get_explosion(unsigned int id){
    return new LittleExplosion(id, target_x, target_y);
}
//------------------------------------------------------------------------------
