// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERWOODENBRIDGE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERWOODENBRIDGE_H_
//------------------------------------------------------------------------------
#include <vector>
#include "serverBridges.h"
//------------------------------------------------------------------------------
class ServerWoodenBridge: public ServerBridges {
 public :
    //--------------------------------------------------------------------------
    ServerWoodenBridge(ServerNode& position, size_t id);
    //--------------------------------------------------------------------------
    ~ServerWoodenBridge();
    //--------------------------------------------------------------------------
    virtual bool isWoodenBridge()const;
    //--------------------------------------------------------------------------
    virtual bool isConcreteBridge()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERWOODENBRIDGE_H_
