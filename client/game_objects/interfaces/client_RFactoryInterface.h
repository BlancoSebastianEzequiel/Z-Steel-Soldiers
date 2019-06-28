#ifndef CLIENT_RFACTORYINTERFACE_H_INCLUDED
#define CLIENT_RFACTORYINTERFACE_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_BuildingInterface.h"
//------------------------------------------------------------------------------
class ClientRFactoryInterface: public ClientBuildingInterface {
 public :
    //--------------------------------------------------------------------------
    ClientRFactoryInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_RFACTORYINTERFACE_H_INCLUDED
