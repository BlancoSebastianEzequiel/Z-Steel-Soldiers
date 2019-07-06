#ifndef CONCRETE_BRIDGE_H
#define CONCRETE_BRIDGE_H
//------------------------------------------------------------------------------
#include "terrainObject.h"
//------------------------------------------------------------------------------
class ConcreteBridge: public TerrainObject {
 public :
    //--------------------------------------------------------------------------
    ConcreteBridge(
            unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y);
    //--------------------------------------------------------------------------
    // Cambia la animacion del puente a destruido
    void destroy();
    //--------------------------------------------------------------------------
    // Devuelve true si el objeto sobre el terreno puede ser atacado,
    // pueden ser atacados los puentes, las rocas y bloques de hielo
    // unicamente
    bool can_be_attacked();
    //--------------------------------------------------------------------------
};
#endif  // CONCRETE_BRIDGE_H
