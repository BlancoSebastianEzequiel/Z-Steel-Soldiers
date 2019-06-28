#include "client_Building.h"
#include "client_RFactory.h"
#include "../interfaces/client_RFactoryInterface.h"
//------------------------------------------------------------------------------
// CLIENT R FACTORY
//------------------------------------------------------------------------------
ClientRFactory::ClientRFactory(
        unsigned int id, unsigned int owner_id, unsigned int init_pos_x,
        unsigned int init_pos_y, unsigned int tech_level):
        ClientBuilding(id, owner_id, init_pos_x, init_pos_y, tech_level,
                       new ClientRFactoryInterface(
                               id, init_pos_x, init_pos_y, tech_level)) {
    std::string path = PATH_TO_IMAGE;
    path += "Buildings/RFactory/grey_factory.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/RFactory/blue_factory.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/RFactory/red_factory.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/RFactory/green_factory.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/RFactory/orange_factory.png";
    frames.push_back(Frame(path));
    path = PATH_TO_IMAGE;
    path += "Buildings/RFactory/base_destroyed.png";
    frames.push_back(Frame(path));
    current_frame = &frames[owner_id];
}
//------------------------------------------------------------------------------
