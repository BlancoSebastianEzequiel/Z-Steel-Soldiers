#include "../client_GameObject.h"
#include "client_TerrainObject.h"
TerrainObject::TerrainObject(unsigned int id,
                             unsigned int init_pos_x,
                             unsigned int init_pos_y):
  GameObject(id,init_pos_x,init_pos_y){
}

TerrainObject::~TerrainObject(){
    for (unsigned int i = 0; i<frames.size(); i++){
        frames[i].unload();
    }
}
//------------------------------------------------------------------------------
// IS UNIT
//------------------------------------------------------------------------------
bool TerrainObject::isUnit() const {
    return false;
}
//------------------------------------------------------------------------------
// IS BUILDING
//------------------------------------------------------------------------------
bool TerrainObject::isBuilding() const {
    return false;
}
//------------------------------------------------------------------------------
// IS TERRAIN OBJECT
//------------------------------------------------------------------------------
bool TerrainObject::isTerrainObject() const {
    return true;
}
