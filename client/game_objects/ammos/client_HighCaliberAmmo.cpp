#include <iostream>
#include "client_Ammo.h"
#include "client_HighCaliberAmmo.h"
#include "../client_GameObject.h"
#include "../explosions/client_BigExplosion.h"
//------------------------------------------------------------------------------
// CLIENT HIGH CALIBER AMMO
//------------------------------------------------------------------------------
ClientHighCaliberAmmo::ClientHighCaliberAmmo(
        unsigned int bullet_id, Unit* shooter, GameObject* target):
        ClientAmmo(bullet_id, shooter, target) {
    x_frames.push_back(Frame("Units/Vehicles/high_caliber_0.png"));
    y_frames.push_back(Frame("Units/Vehicles/high_caliber_90.png"));
    xy_frames.push_back(Frame("Units/Vehicles/high_caliber_45.png"));
    xy_frames.push_back(Frame("Units/Vehicles/high_caliber_135.png"));
    current_frame = &xy_frames[0];
}
//------------------------------------------------------------------------------
// MOVE X
//------------------------------------------------------------------------------
void ClientHighCaliberAmmo::move_x(unsigned int dest_x, double speed) {
    current_frame = &x_frames[0];
    ClientAmmo::move_x(dest_x, speed);
}
//------------------------------------------------------------------------------
// MOVE Y
//------------------------------------------------------------------------------
void ClientHighCaliberAmmo::move_y(unsigned int dest_y, double speed) {
    current_frame = &y_frames[0];
    ClientAmmo::move_y(dest_y, speed);
}
//------------------------------------------------------------------------------
// MOVE XY
//------------------------------------------------------------------------------
void ClientHighCaliberAmmo::move_xy(
        unsigned int dest_x, unsigned int dest_y, double speed) {
    if ((pos_x < dest_x && pos_y < dest_y)||(pos_x > dest_x && pos_y>dest_y)) {
        // diagonal hacia abajo y derecha
        if (frame_index < 1) {
            frame_index = 1;
        }
    }
    if ((pos_x < dest_x && pos_y > dest_y)||(pos_x > dest_x && pos_y< dest_y)) {
        // diagonal hacia arriba y derecha
        if (frame_index > 0) {
            frame_index = 0;
        }
    }
    current_frame = &xy_frames[frame_index];
    ClientAmmo::move_xy(dest_x, dest_y, speed);
}
//------------------------------------------------------------------------------
// GET EXPLOSION
//------------------------------------------------------------------------------
ClientExplosion* ClientHighCaliberAmmo::get_explosion(unsigned int id) {
    return new ClientBigExplosion(id, target_x, target_y);
}
//------------------------------------------------------------------------------
