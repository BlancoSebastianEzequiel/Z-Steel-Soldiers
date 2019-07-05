#include "ammo.h"
#include "missileAmmo.h"
#include "../gameObject.h"
#include "../explosions/bigExplosion.h"
#include <iostream>
//------------------------------------------------------------------------------
// CLIENT MISSILE AMMO
//------------------------------------------------------------------------------
MissileAmmo::MissileAmmo(
        unsigned int bullet_id, Unit* shooter, GameObject* target):
        Ammo(bullet_id, shooter, target) {
    x_frames.push_back(Frame("Units/Vehicles/MML/missile_0.png"));
    y_frames.push_back(Frame("Units/Vehicles/MML/missile_90.png"));
    xy_frames.push_back(Frame("Units/Vehicles/MML/missile_45.png"));
    xy_frames.push_back(Frame("Units/Vehicles/MML/missile_135.png"));
    current_frame = &xy_frames[0];
}
//------------------------------------------------------------------------------
// MOVE X
//------------------------------------------------------------------------------
void MissileAmmo::move_x(unsigned int dest_x, double speed) {
    current_frame = &x_frames[0];
    Ammo::move_x(dest_x, speed);
}
//------------------------------------------------------------------------------
// MOVE Y
//------------------------------------------------------------------------------
void MissileAmmo::move_y(unsigned int dest_y, double speed) {
    current_frame = &y_frames[0];
    Ammo::move_y(dest_y, speed);
}
//------------------------------------------------------------------------------
// MOVE XY
//------------------------------------------------------------------------------
void MissileAmmo::move_xy(
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
Explosion* MissileAmmo::get_explosion(unsigned int id) {
    return new BigExplosion(id, target_x, target_y);
}
//------------------------------------------------------------------------------
