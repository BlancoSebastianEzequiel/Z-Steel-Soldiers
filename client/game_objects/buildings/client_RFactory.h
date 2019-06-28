#ifndef CLIENT_RFACTORY_H_INCLUDED
#define CLIENT_RFACTORY_H_INCLUDED
//------------------------------------------------------------------------------
class ClientRFactory: public ClientBuilding {
 public :
    //--------------------------------------------------------------------------
    ClientRFactory(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_RFACTORY_H_INCLUDED
