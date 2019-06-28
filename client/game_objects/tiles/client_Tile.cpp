#include "../client_GameObject.h"
#include "client_Tile.h"
#include <iostream>

#define FILE_PATH "pics/Maps/Forest/grassland.bmp"

Tile::Tile(unsigned int pos_x, unsigned int pos_y):
 GameObject(pos_x,pos_y), tile_frame(FILE_PATH){
    current_frame = &tile_frame;
}

Tile::~Tile(){
    this->tile_frame.unload();
}

