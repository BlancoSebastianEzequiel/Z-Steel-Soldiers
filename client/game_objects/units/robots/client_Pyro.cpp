#include <string>
#include <iostream>
#include "client_Robot.h"
#include "client_Pyro.h"
#include "../../ammos/client_PyroAmmo.h"
//------------------------------------------------------------------------------
using std::string;
using std::to_string;
//------------------------------------------------------------------------------
// CLIENT ROBOT PYRO
//------------------------------------------------------------------------------
ClientRobotPyro::ClientRobotPyro(unsigned int id, unsigned int owner_id,
                                 unsigned int init_pos_x,
                                 unsigned int init_pos_y):
    ClientRobot(id, owner_id, init_pos_x, init_pos_y) {
    unsigned int order = 0;
    unsigned int angle = 0;
    string path;
    for (int i = 0; i < 10 ; i++) {
        // fire_color_Angulo_orden
        path = "Units/Robots/Grunt/fire_"+ to_string(owner_id) + "_r";
        path += to_string(angle) + "_n" + to_string(order) +".png";
        order++;
        if (order > 4) {
            order = 0;
            angle += 180;
        }
        x_shoot_frames.push_back(Frame(path));
    }
    angle = 90;
    for (int i = 0; i < 10 ; i++) {
        // fire_color_Angulo_orden
        path ="Units/Robots/Grunt/fire_"+ to_string(owner_id) + "_r";
        path += to_string(angle) + "_n" + to_string(order) +".png";
        order++;
        if (order > 4) {
            order = 0;
            angle += 180;
        }
        y_shoot_frames.push_back(Frame(path));
    }
    angle = 45;
    for (int i = 0; i < 20 ; i++) {
        // fire_color_Angulo_orden
        path = "Units/Robots/Grunt/fire_"+ to_string(owner_id) + "_r";
        path += to_string(angle) + "_n" + to_string(order) +".png";
        order++;
        if (order > 4) {
            order = 0;
            angle += 90;
        }
        xy_shoot_frames.push_back(Frame(path));
    }
}
//------------------------------------------------------------------------------
// SHOOT X
//------------------------------------------------------------------------------
void ClientRobotPyro::shoot_x(GameObject* target) {
    unsigned int target_x  = target->get_x();
    if (pos_x > target_x) {
        // disparo hacia la izquierda
        if (frame_index < 5 || frame_index > 9) {
            frame_index = 5;
        }
    } else {
        // Disparo hacia la derecha
        if (frame_index > 4) {
            frame_index = 0;
        }
    }
    current_frame = &x_shoot_frames[frame_index];
    frame_index++;
}
//------------------------------------------------------------------------------
// SHOOT Y
//------------------------------------------------------------------------------
void ClientRobotPyro::shoot_y(GameObject* target) {
    unsigned int target_y = target->get_y();
    if (pos_y < target_y) {
        // Disparo hacia abajo
        if (frame_index < 5 || frame_index > 9) {
            frame_index = 5;
        }
    } else {
        // Disparo hacia arriba
        if (frame_index > 4) {
            frame_index = 0;
        }
    }
    current_frame = &y_shoot_frames[frame_index];
    frame_index++;
}
//------------------------------------------------------------------------------
// SHOOT XY
//------------------------------------------------------------------------------
void ClientRobotPyro::shoot_xy(GameObject* target) {
    unsigned int target_x = target->get_x();
    unsigned int target_y = target->get_y();
    if (pos_x > target_x && pos_y > target_y) {
        // diagonal hacia arriba e izquierda
        if (frame_index < 5 ||frame_index > 9) {
            frame_index = 5;
        }
    } else if (pos_x > target_x && pos_y < target_y) {
        // diagonal hacia abajo e izquierda
        if (frame_index < 10 || frame_index > 14) {
            frame_index = 10;
        }
    } else if (pos_x < target_x && pos_y < target_y) {
        // diagonal hacia abajo y derecha
        if (frame_index < 15 || frame_index > 19) {
            frame_index = 15;
        }
    } else if (pos_x < target_x && pos_y > target_y) {
        // diagonal hacia arriba y derecha
        if (frame_index > 4) {
            frame_index = 0;
        }
    }
    current_frame = &xy_shoot_frames[frame_index];
    frame_index++;
}
//------------------------------------------------------------------------------
// GET BULLET
//------------------------------------------------------------------------------
ClientAmmo* ClientRobotPyro::get_bullet(
        unsigned int id, Unit* shooter, GameObject* target) {
    return new ClientPyroAmmo(id, shooter, target);
}
//------------------------------------------------------------------------------
