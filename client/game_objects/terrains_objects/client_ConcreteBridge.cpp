#include "client_ConcreteBridge.h"
//------------------------------------------------------------------------------
// CONCRETE BRIDGE CONSTRUCTOR
//------------------------------------------------------------------------------
ConcreteBridge::ConcreteBridge(
        unsigned int id, unsigned int init_pos_x, unsigned int init_pos_y):
        TerrainObject(id, init_pos_x, init_pos_y) {
    std::string string = PATH_TO_IMAGE;
    string += "Terrain/Bridge/concret_bridge.png";
    frames.push_back(Frame(string));
    string = PATH_TO_IMAGE;
    string += "Terrain/Bridge/concret_bridge_destroyed.png";
    frames.push_back(Frame(string));
    frame_it = frames.begin();
    current_frame = &frames[0];
}
//------------------------------------------------------------------------------
// DESTROY
//------------------------------------------------------------------------------
void ConcreteBridge::destroy() {
    current_frame = &frames[1];
}
//------------------------------------------------------------------------------
// CAN BE ATTACKED
//------------------------------------------------------------------------------
bool ConcreteBridge::can_be_attacked() {
    return true;
}
//------------------------------------------------------------------------------
