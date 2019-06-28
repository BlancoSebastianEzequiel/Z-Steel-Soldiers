#ifndef CLIENT_FORT_H_INCLUDED
#define CLIENT_FORT_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_Building.h"
#include "../interfaces/client_FortInterface.h"
//------------------------------------------------------------------------------
class ClientFort: public ClientBuilding {
 public :
    //--------------------------------------------------------------------------
    ClientFort(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_FORT_H_INCLUDED
