// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include "serverIceBlock.h"
//------------------------------------------------------------------------------
// SERVER ICE BLOCK CONSTRUCTOR
//------------------------------------------------------------------------------
ServerIceBlock::ServerIceBlock(ServerNode &position, size_t id):
        ServerSolids::ServerSolids(position, id) {}
//------------------------------------------------------------------------------
// SERVER ICE BLOCK  DESTRUCTOR
//------------------------------------------------------------------------------
ServerIceBlock::~ServerIceBlock() {}
//------------------------------------------------------------------------------
// IS STONE
//------------------------------------------------------------------------------
bool ServerIceBlock::isStone() const {
    return false;
}
//------------------------------------------------------------------------------
// IS ICE BLOCK
//------------------------------------------------------------------------------
bool ServerIceBlock::isIceBlock() const {
    return true;
}
//------------------------------------------------------------------------------
