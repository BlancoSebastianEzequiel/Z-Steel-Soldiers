// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERCONCRETEBRIDGE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERCONCRETEBRIDGE_H_
//------------------------------------------------------------------------------
#include <vector>
#include "bridges.h"
//------------------------------------------------------------------------------
class ConcreteBridge: public Bridges {
 public :
    //--------------------------------------------------------------------------
    ConcreteBridge(Node& position, size_t id);
    //--------------------------------------------------------------------------
    ~ConcreteBridge();
    //--------------------------------------------------------------------------
    virtual bool isWoodenBridge()const;
    //--------------------------------------------------------------------------
    virtual bool isConcreteBridge()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERCONCRETEBRIDGE_H_
