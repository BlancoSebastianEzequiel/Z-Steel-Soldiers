#include <iostream>
#include <utility>
#include "../client_GameObject.h"
#include "../units/client_Unit.h"
#include "client_Ammo.h"
//------------------------------------------------------------------------------
#define BULLET_SPEED 50
//------------------------------------------------------------------------------
// CLIENT AMMO CONSTRUCTOR
//------------------------------------------------------------------------------
ClientAmmo::ClientAmmo(unsigned int id, Unit* shooter, GameObject* target):
        GameObject(id, shooter->get_x(), shooter->get_y()), shooter(shooter),
        target(target), frame_index(0), visible(true) {
    targetId = target->get_id();
    target_x = target->get_x();
    target_y = target->get_y();
    shooterId = shooter->get_id();
}
//------------------------------------------------------------------------------
// CLIENT AMMO DESTRUCTOR
//------------------------------------------------------------------------------
ClientAmmo::~ClientAmmo() {
    for (unsigned int i = 0; i < x_frames.size(); i++) {
        x_frames[i].unload();
    }
    for (unsigned int i = 0; i < y_frames.size(); i++) {
        y_frames[i].unload();
    }
    for (unsigned int i = 0; i < xy_frames.size(); i++) {
        xy_frames[i].unload();
    }
}
//------------------------------------------------------------------------------
// MOVE X
//------------------------------------------------------------------------------
void ClientAmmo::move_x(unsigned int dest_x, double speed) {
    if (dest_x > pos_x) {
        pos_x += speed;  // Esto despues va a ser la velocidad.
    } else {
        pos_x -= speed;
    }
}
//------------------------------------------------------------------------------
// MOVE Y
//------------------------------------------------------------------------------
void ClientAmmo::move_y(unsigned int dest_y, double speed) {
    if (dest_y > pos_y) {
        pos_y += speed;
    } else {
        pos_y -= speed;
    }
}
//------------------------------------------------------------------------------
// MOE X Y
//------------------------------------------------------------------------------
void
ClientAmmo::move_xy(unsigned int dest_x, unsigned int dest_y, double speed) {
    if (pos_x < dest_x) {
        pos_x += speed;
    }
    if (pos_x > dest_x) {
        pos_x -= speed;
    }
    if (pos_y < dest_y) {
        pos_y += speed;
    }

     if (pos_y > dest_y) {
        pos_y -= speed;
    }
}
//******************************************************************************
// PUBLIC
//******************************************************************************
//------------------------------------------------------------------------------
// MOVE
//------------------------------------------------------------------------------
void ClientAmmo::move(unsigned int dest_x, unsigned int dest_y, double speed) {
    // unsigned int dest_x = target->get_x();
    // unsigned int dest_y = target->get_y();
    if (this->get_x() != dest_x && this->get_y() != dest_y) {
        // Desplazamiento en diagonal
        this->move_xy(dest_x, dest_y, speed);
    }

    if (this->get_x() != dest_x &&  this->get_y() == dest_y) {
        // Desplazamiento en horizontal
        this->move_x(dest_x, speed);
    }

    if (this->get_y() != dest_y && this->get_x() == dest_x) {
        // Desplazamiento en vertical
        this->move_y(dest_y, speed);
    }
}
//------------------------------------------------------------------------------
// COLLISIONED
//------------------------------------------------------------------------------
bool ClientAmmo::collisioned() {
    // Dentro de un cuadrado de 15x15 acepto que colisiono
    if (visible) {
        bool a = abs(int(target->get_x() - this->pos_x)) <= 15;
        bool b = abs(int(target->get_y() - this->pos_y)) <= 15;
        return a && b;
    }
    return true;
}
//------------------------------------------------------------------------------
// DRAW
//------------------------------------------------------------------------------
void ClientAmmo::draw(SDL_Surface* surface, ClientCamera& camera) {
    if (visible) {
        // this->move();
        GameObject::draw(surface, camera);
    }
}
//------------------------------------------------------------------------------
// GET SHOOTER
//------------------------------------------------------------------------------
Unit* ClientAmmo::get_shooter() {
    return this->shooter;
}
//------------------------------------------------------------------------------
// GET TARGET ID
//------------------------------------------------------------------------------
unsigned int ClientAmmo::getTargetId() {
    return targetId;
}
//------------------------------------------------------------------------------
// GET SHOOTER ID
//------------------------------------------------------------------------------
unsigned int ClientAmmo::getShooterId() {
    return shooterId;
}
//------------------------------------------------------------------------------
// GET TARGET
//------------------------------------------------------------------------------
GameObject* ClientAmmo::get_target() {
    return this->target;
}
//------------------------------------------------------------------------------
// TARGET DIE
//------------------------------------------------------------------------------
void ClientAmmo::target_died(GameObject* target) {
    visible = false;
}
//------------------------------------------------------------------------------
