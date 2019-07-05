// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERICEBLOCK_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERICEBLOCK_H_
//------------------------------------------------------------------------------
#include <vector>
#include "solids.h"
//------------------------------------------------------------------------------
class IceBlock: public Solids {
 public :
    //--------------------------------------------------------------------------
    IceBlock(Node& position, size_t id);
    //--------------------------------------------------------------------------
    ~IceBlock();
    //--------------------------------------------------------------------------
    virtual bool isStone()const;
    //--------------------------------------------------------------------------
    virtual bool isIceBlock()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERICEBLOCK_H_
