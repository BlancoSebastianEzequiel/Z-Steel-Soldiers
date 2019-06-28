#include <iostream>
#include "client_Ammo.h"
#include "client_LaserAmmo.h"
#include "../client_GameObject.h"
#include "../explosions/client_LittleExplosion.h"
//------------------------------------------------------------------------------
// CLIENT LASER AMMO
//------------------------------------------------------------------------------
ClientLaserAmmo::ClientLaserAmmo(
        unsigned int bullet_id, Unit* shooter, GameObject* target):
        ClientAmmo(bullet_id, shooter, target) {
    std::string path = PATH_TO_IMAGE;
    path += "Units/Robots/Laser/laser_shoot_0.bmp";
    x_frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Units/Robots/Laser/laser_shoot_90.bmp";
    y_frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Units/Robots/Laser/laser_shoot_45.bmp";
    xy_frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Units/Robots/Laser/laser_shoot_135.bmp";
    xy_frames.push_back(Frame(path));
    current_frame = &xy_frames[0];
}
//------------------------------------------------------------------------------
// MOVE X
//------------------------------------------------------------------------------
void ClientLaserAmmo::move_x(unsigned int dest_x, double speed) {
    current_frame = &x_frames[0];
    ClientAmmo::move_x(dest_x, speed);
}
//------------------------------------------------------------------------------
// MOVE Y
//------------------------------------------------------------------------------
void ClientLaserAmmo::move_y(unsigned int dest_y, double speed) {
    current_frame = &y_frames[0];
    ClientAmmo::move_y(dest_y, speed);
}
//------------------------------------------------------------------------------
// MOVE XY
//------------------------------------------------------------------------------
void ClientLaserAmmo::move_xy(
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
    ClientAmmo::move_xy(dest_x, dest_y, speed);
}
//------------------------------------------------------------------------------
// GET EXPLOSION
//------------------------------------------------------------------------------
ClientExplosion* ClientLaserAmmo::get_explosion(unsigned int id){
    return new ClientLittleExplosion(id, target_x, target_y);
}
//------------------------------------------------------------------------------
