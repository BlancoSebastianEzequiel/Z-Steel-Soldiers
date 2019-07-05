// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTONE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTONE_H_
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "solids.h"
//------------------------------------------------------------------------------
class Stone: public Solids {
 public :
    //--------------------------------------------------------------------------
    Stone(Node& position, size_t id);
    //--------------------------------------------------------------------------
    ~Stone();
    //--------------------------------------------------------------------------
    virtual bool isStone()const;
    //--------------------------------------------------------------------------
    virtual bool isIceBlock()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERSTONE_H_
