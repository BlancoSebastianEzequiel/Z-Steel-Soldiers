#include "client_Building.h"
#include "client_VFactory.h"
#include "../interfaces/client_VFactoryInterface.h"
//------------------------------------------------------------------------------
// CLIENT V FACTORY
//------------------------------------------------------------------------------
ClientVFactory::ClientVFactory(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y, unsigned int tech_level):
        ClientBuilding(id, owner_id, init_pos_x, init_pos_y, tech_level,
                       new ClientVFactoryInterface(
                               id, init_pos_x, init_pos_y, tech_level)) {
    frames.push_back(Frame("Buildings/VFactory/grey_factory.png"));
    frames.push_back(Frame("Buildings/VFactory/blue_factory.png"));
    frames.push_back(Frame("Buildings/VFactory/red_factory.png"));
    frames.push_back(Frame("Buildings/VFactory/green_factory.png"));
    frames.push_back(Frame("Buildings/VFactory/orange_factory.png"));
    frames.push_back(Frame("Buildings/VFactory/base_destroyed.png"));
    current_frame = &frames[owner_id];
}
//------------------------------------------------------------------------------
