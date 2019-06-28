#ifndef CLIENT_FORTINTERFACE_H_INCLUDED
#define CLIENT_FORTINTERFACE_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_BuildingInterface.h"
//------------------------------------------------------------------------------
class ClientFortInterface: public ClientBuildingInterface {
 public :
    //--------------------------------------------------------------------------
    ClientFortInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_FORTINTERFACE_H_INCLUDED
