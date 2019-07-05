#include "unit.h"
#include "../../actions/unitAction.h"
#include "../../actions/standStillAction.h"
#include "../../frames/frame.h"
#include "vector"
#include <iostream>
using std::vector;

void addFrame(Frame* new_frame);

Unit::Unit(unsigned int id, unsigned int owner_id,
           unsigned int init_pos_x,unsigned int init_pos_y):
    GameObject(id,init_pos_x,init_pos_y),frame_index(0),
    current_action(new StandStillAction(this)),dead(false),
    owner_id(owner_id) {
}

Unit::~Unit(){
    for (unsigned int i = 0; i<x_frames.size(); i++){
        x_frames[i].unload();
    }
    for (unsigned int i = 0; i<y_frames.size(); i++){
        y_frames[i].unload();
    }
    for (unsigned int i = 0; i<xy_frames.size(); i++){
        xy_frames[i].unload();
    }
    for (unsigned int i = 0; i<x_shoot_frames.size(); i++){
        x_shoot_frames[i].unload();
    }
    for (unsigned int i = 0; i<y_shoot_frames.size(); i++){
        y_shoot_frames[i].unload();
    }
    for (unsigned int i = 0; i<xy_shoot_frames.size(); i++){
        xy_shoot_frames[i].unload();
    }
    delete current_action;
}

void Unit::move_x(unsigned int dest_x, double speed){
    if (dest_x > pos_x){
        pos_x += speed; //Esto despues va a ser la velocidad.
    } else {
        pos_x -= speed;
    }
}

void Unit::move_y(unsigned int dest_y, double speed){
    if (dest_y > pos_y){
        pos_y += speed;
    } else {
        pos_y -= speed;
    }
}

void Unit::move_xy(unsigned int dest_x, unsigned int dest_y, double speed){
    if (pos_x < dest_x){
        pos_x += speed;
    }

    if (pos_x > dest_x){
        pos_x -= speed;
    }

    if (pos_y < dest_y){
        pos_y += speed;
    }

     if (pos_y > dest_y){
        pos_y -= speed;
    }
}
/*******************PUBLIC*************************/
unsigned int Unit::get_id(){
    return this->id;
}

void Unit::new_command(UnitAction* action){
    current_action->finish();
    UnitAction* previous_action = this->current_action;
    this->current_action = action;//reemplazo con la nueva
    delete previous_action;//libero la anterior
}

void Unit::move(unsigned int dest_x, unsigned int dest_y, double speed){
    if (this->get_x() != dest_x && this->get_y() != dest_y){
        /**Desplazamiento en diagonal**/
        this->move_xy(dest_x, dest_y, speed);
    }

    if (this->get_x() != dest_x &&  this->get_y() == dest_y){
        /**Desplazamiento en horizontal**/
        this->move_x(dest_x, speed);
    }

    if (this->get_y() != dest_y && this->get_x() == dest_x){
        /**Desplazamiento en vertical**/
        this->move_y(dest_y, speed);
    }
}

void Unit::shoot(GameObject* target) {
    unsigned int target_x = target->get_x();
    unsigned int target_y = target->get_y();
    if (this->get_x() != target_x && this->get_y() != target_y){
        /**Disparo en diagonal**/
         this->shoot_xy(target);
    }

    if (this->get_x() != target_x &&  this->get_y() == target_y){
        /**Disparo en horizontal**/
        this->shoot_x(target);
    }

    if (this->get_y() != target_y && this->get_x() == target_x){
        /**Disparo en vertical**/
        this->shoot_y(target);
    }
}

void Unit::stand_still(){
    //Elijo un fotograma de forma arbitraria para cuando quede detenido
    current_frame = &this->y_frames[4];
}

void Unit::draw(SDL_Surface* surface , Camera& camera) {
    if (current_action) {
         this->current_action->execute();
    }
    if (!dead) GameObject::draw(surface, camera);
}

void Unit::set_x(unsigned int dest_x){
    this->pos_x = dest_x;
}

void Unit::set_y(unsigned int dest_y){
    this->pos_y = dest_y;
}

void Unit::die(){
    dead = true;
}

bool Unit::is_dead(){
    return dead;
}

unsigned int Unit::get_owner_id(){
    return owner_id;
}
//------------------------------------------------------------------------------
// IS UNIT
//------------------------------------------------------------------------------
bool Unit::isUnit() const {
    return true;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool Unit::isBuilding() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TERRAIN OBJECT
//------------------------------------------------------------------------------
bool Unit::isTerrainObject() const {
    return false;
}