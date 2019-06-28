#include "client_TerrainObject.h"
#include "client_Flag.h"
#include <string>
#include <iostream>
using std::string;
using std::to_string;

Flag::Flag(unsigned int id, unsigned int init_pos_x,unsigned int init_pos_y):
  TerrainObject(id,init_pos_x,init_pos_y), frame_index(0) {
  unsigned int player = 0;
  unsigned int order = 0;
  string path;
  for (unsigned int i = 0; i < 20; i++){
    path = PATH_TO_IMAGE;
    path += "Terrain/flag_" +to_string(player)+ "_" + to_string(order) + ".png";
    frames.push_back(Frame(path));
    order++;
    if (order > 3){
      order = 0;
      player++;
    }
  }
  
  frame_it = frames.begin();
  owner_id = 0;
  current_frame = &frames[owner_id];
}

void Flag::change_owner(unsigned int owner_id){
    this->owner_id = owner_id;
    current_frame = &frames[owner_id*4];
}

bool Flag::can_be_attacked(){
    return false;
}

void Flag::draw(SDL_Surface* screen, ClientCamera& camera){
   current_frame = &frames[owner_id*4 + frame_index];
   GameObject::draw(screen,camera);
   frame_index++;
   if (frame_index > 3){
      frame_index = 0;
   }
}
