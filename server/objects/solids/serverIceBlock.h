// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERICEBLOCK_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERICEBLOCK_H_
//------------------------------------------------------------------------------
#include <vector>
#include "serverSolids.h"
//------------------------------------------------------------------------------
class ServerIceBlock: public ServerSolids {
 public :
    //--------------------------------------------------------------------------
    ServerIceBlock(ServerNode& position, size_t id);
    //--------------------------------------------------------------------------
    ~ServerIceBlock();
    //--------------------------------------------------------------------------
    virtual bool isStone()const;
    //--------------------------------------------------------------------------
    virtual bool isIceBlock()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERICEBLOCK_H_
