#ifndef CLIENT_CONCRETEBRIDGE_H_INCLUDED
#define CLIENT_CONCRETEBRIDGE_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_TerrainObject.h"
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
#endif  // CLIENT_CONCRETEBRIDGE_H_INCLUDED
