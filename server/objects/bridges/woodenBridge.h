// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERWOODENBRIDGE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERWOODENBRIDGE_H_
//------------------------------------------------------------------------------
#include <vector>
#include "bridges.h"
//------------------------------------------------------------------------------
class WoodenBridge: public Bridges {
 public :
    //--------------------------------------------------------------------------
    WoodenBridge(Node& position, size_t id);
    //--------------------------------------------------------------------------
    ~WoodenBridge();
    //--------------------------------------------------------------------------
    virtual bool isWoodenBridge()const;
    //--------------------------------------------------------------------------
    virtual bool isConcreteBridge()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERWOODENBRIDGE_H_
