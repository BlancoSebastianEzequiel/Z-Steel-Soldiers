#ifndef CLIENT_VFACTORYINTERFACE_H_INCLUDED
#define CLIENT_VFACTORYINTERFACE_H_INCLUDED
//------------------------------------------------------------------------------
#include "client_BuildingInterface.h"
//------------------------------------------------------------------------------
class ClientVFactoryInterface: public ClientBuildingInterface {
 public :
    //--------------------------------------------------------------------------
    ClientVFactoryInterface(
            unsigned int id, unsigned int pos_x, unsigned int pos_y,
            unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_VFACTORYINTERFACE_H_INCLUDED
