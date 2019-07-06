#ifndef WOOD_BRIDGE_H
#define WOOD_BRIDGE_H
//------------------------------------------------------------------------------
#include "terrainObject.h"
//------------------------------------------------------------------------------
class WoodBridge: public TerrainObject {
 public :
    //--------------------------------------------------------------------------
    WoodBridge(
            unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y);
    //--------------------------------------------------------------------------
    // Cambia el sprite al de un puente destruido
    void destroy();
    //--------------------------------------------------------------------------
    // Devuelve true si el objeto sobre el terreno puede ser atacado,
    // pueden ser atacados los puentes, las rocas y bloques de hielo
    // unicamente
    bool can_be_attacked();
    //--------------------------------------------------------------------------
};
#endif  // WOOD_BRIDGE_H
