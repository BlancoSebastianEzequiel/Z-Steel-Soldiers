// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERCONCRETEBRIDGE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERCONCRETEBRIDGE_H_
//------------------------------------------------------------------------------
#include <vector>
#include "serverBridges.h"
//------------------------------------------------------------------------------
class ServerConcreteBridge: public ServerBridges {
 public :
    //--------------------------------------------------------------------------
    ServerConcreteBridge(ServerNode& position, size_t id);
    //--------------------------------------------------------------------------
    ~ServerConcreteBridge();
    //--------------------------------------------------------------------------
    virtual bool isWoodenBridge()const;
    //--------------------------------------------------------------------------
    virtual bool isConcreteBridge()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERCONCRETEBRIDGE_H_
