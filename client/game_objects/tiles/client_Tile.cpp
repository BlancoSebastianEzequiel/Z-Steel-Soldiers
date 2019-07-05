#include "../client_GameObject.h"
#include "client_Tile.h"
#include <iostream>

Tile::Tile(unsigned int pos_x, unsigned int pos_y):
    GameObject(pos_x,pos_y), tile_frame("Maps/Forest/grassland.bmp") {
    current_frame = &tile_frame;
}

Tile::~Tile() {
    this->tile_frame.unload();
}
