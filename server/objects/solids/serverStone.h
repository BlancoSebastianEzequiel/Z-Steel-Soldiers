// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTONE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTONE_H_
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "serverSolids.h"
//------------------------------------------------------------------------------
class ServerStone: public ServerSolids {
 public :
    //--------------------------------------------------------------------------
    ServerStone(ServerNode& position, size_t id);
    //--------------------------------------------------------------------------
    ~ServerStone();
    //--------------------------------------------------------------------------
    virtual bool isStone()const;
    //--------------------------------------------------------------------------
    virtual bool isIceBlock()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTONE_H_
