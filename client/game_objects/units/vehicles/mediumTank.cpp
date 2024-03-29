#include <string>
#include <iostream>
#include "mediumTank.h"
#include "../../ammos/highCaliberAmmo.h"
#include "../../ammos/laserAmmo.h"
//------------------------------------------------------------------------------
using std::string;
using std::to_string;
//------------------------------------------------------------------------------
// CLIENT MEDIUM TANK CONSTRUCTOR
//------------------------------------------------------------------------------
MediumTank::MediumTank(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y):
        Vehicle(id, owner_id,init_pos_x,init_pos_y) {
    unsigned int order = 0;
    unsigned int angle = 0;
    string path;
    for (int i = 0; i < 6 ; i++) {
        // fire_color_Angulo_orden
        path = "Units/Vehicles/Medium/move_"+ to_string(owner_id) + "_";
        path += to_string(angle) + "_" + to_string(order) +".png";
        order++;
        if (order > 2) {
            order = 0;
            angle += 180;
        }
        x_frames.push_back(Frame(path));
    }
    angle = 90;
    for (int i = 0; i < 6 ; i++) {
        // fire_color_Angulo_orden
        path = "Units/Vehicles/Medium/move_"+ to_string(owner_id) + "_";
        path += to_string(angle) + "_" + to_string(order) +".png";
        order++;
        if (order > 2) {
            order = 0;
            angle += 180;
        }
        y_frames.push_back(Frame(path));
    }
    angle = 45;
    for (int i = 0; i < 12 ; i++) {
        path = "Units/Vehicles/Medium/move_"+ to_string(owner_id) + "_";
        path += to_string(angle) + "_" + to_string(order) +".png";
        order++;
        if (order > 2) {
            order = 0;
            angle += 90;
        }
        xy_frames.push_back(Frame(path));
    }
    current_frame = &x_frames[0];
}
//------------------------------------------------------------------------------
// SHOOT X
//------------------------------------------------------------------------------
void MediumTank::shoot_x(GameObject* target){
    unsigned int target_x = target->get_x();
    if (pos_x > target_x){
        // disparo hacia la izquierda
        frame_index = 3;
    } else {
        // Disparo hacia la derecha
        frame_index = 0;
    }
    current_frame = &x_frames[frame_index];
 }
//------------------------------------------------------------------------------
// SHOOT Y
//------------------------------------------------------------------------------
void MediumTank::shoot_y(GameObject* target) {
    unsigned int target_y = target->get_y();
    if (pos_y < target_y) {
        // Disparo hacia abajo
        frame_index = 3;
    } else {
        // Disparo hacia arriba
        frame_index = 0;
    }
    current_frame = &y_frames[frame_index];
 }
//------------------------------------------------------------------------------
// SHOOT XY
//------------------------------------------------------------------------------
void MediumTank::shoot_xy(GameObject* target) {
    unsigned int target_x = target->get_x();
    unsigned int target_y = target->get_y();
    if (pos_x > target_x && pos_y > target_y) {
        // diagonal hacia arriba e izquierda
        frame_index = 3;
    } else if (pos_x > target_x && pos_y < target_y) {
        // diagonal hacia abajo e izquierda
        frame_index = 6;
    } else if (pos_x < target_x && pos_y < target_y) {
        // diagonal hacia abajo y derecha
        frame_index = 9;
    } else if (pos_x < target_x && pos_y > target_y) {
        // diagonal hacia arriba y derecha*
        frame_index = 0;
    }
    current_frame = &xy_frames[frame_index];
 }
//------------------------------------------------------------------------------
// GET BULLET
//------------------------------------------------------------------------------
Ammo* MediumTank::get_bullet(
        unsigned int bullet_id, Unit* shooter, GameObject* target) {
    return new HighCaliberAmmo(bullet_id, shooter, target);
}
//------------------------------------------------------------------------------
