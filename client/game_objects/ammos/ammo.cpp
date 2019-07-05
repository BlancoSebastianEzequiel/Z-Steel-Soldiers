#include <iostream>
#include <utility>
#include "../gameObject.h"
#include "../units/unit.h"
#include "ammo.h"
//------------------------------------------------------------------------------
#define BULLET_SPEED 50
//------------------------------------------------------------------------------
// CLIENT AMMO CONSTRUCTOR
//------------------------------------------------------------------------------
Ammo::Ammo(unsigned int id, Unit* shooter, GameObject* target):
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
Ammo::~Ammo() {
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
void Ammo::move_x(unsigned int dest_x, double speed) {
    if (dest_x > pos_x) {
        pos_x += speed;  // Esto despues va a ser la velocidad.
    } else {
        pos_x -= speed;
    }
}
//------------------------------------------------------------------------------
// MOVE Y
//------------------------------------------------------------------------------
void Ammo::move_y(unsigned int dest_y, double speed) {
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
Ammo::move_xy(unsigned int dest_x, unsigned int dest_y, double speed) {
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
void Ammo::move(unsigned int dest_x, unsigned int dest_y, double speed) {
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
bool Ammo::collisioned() {
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
void Ammo::draw(SDL_Surface* surface, Camera& camera) {
    if (visible) {
        // this->move();
        GameObject::draw(surface, camera);
    }
}
//------------------------------------------------------------------------------
// GET SHOOTER
//------------------------------------------------------------------------------
Unit* Ammo::get_shooter() {
    return this->shooter;
}
//------------------------------------------------------------------------------
// GET TARGET ID
//------------------------------------------------------------------------------
unsigned int Ammo::getTargetId() {
    return targetId;
}
//------------------------------------------------------------------------------
// GET SHOOTER ID
//------------------------------------------------------------------------------
unsigned int Ammo::getShooterId() {
    return shooterId;
}
//------------------------------------------------------------------------------
// GET TARGET
//------------------------------------------------------------------------------
GameObject* Ammo::get_target() {
    return this->target;
}
//------------------------------------------------------------------------------
// TARGET DIE
//------------------------------------------------------------------------------
void Ammo::target_died(GameObject* target) {
    visible = false;
}
//------------------------------------------------------------------------------
