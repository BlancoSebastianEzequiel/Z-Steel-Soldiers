#ifndef CLIENT_VFACTORY_H_INCLUDED
#define CLIENT_VFACTORY_H_INCLUDED
//------------------------------------------------------------------------------
class VFactory: public Building {
 public :
    //--------------------------------------------------------------------------
    VFactory(
            unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
            unsigned int init_pos_y, unsigned int tech_level);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_VFACTORY_H_INCLUDED
