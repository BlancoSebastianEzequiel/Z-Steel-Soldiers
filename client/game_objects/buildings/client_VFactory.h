#ifndef CLIENT_VFACTORY_H_INCLUDED
#define CLIENT_VFACTORY_H_INCLUDED
//------------------------------------------------------------------------------
class ClientVFactory: public ClientBuilding {
 public :
    //--------------------------------------------------------------------------
    ClientVFactory(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_VFACTORY_H_INCLUDED
