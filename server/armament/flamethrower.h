// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFLAMETHROWER_H_
#define  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFLAMETHROWER_H_
//------------------------------------------------------------------------------
#include "armament.h"
//------------------------------------------------------------------------------
class Flamethrower: public Armament {
 public :
    //--------------------------------------------------------------------------
    Flamethrower(const Node& position, size_t id, const Unit& shooter);
    //--------------------------------------------------------------------------
    ~Flamethrower();
    //--------------------------------------------------------------------------
    virtual bool isLaser()const;
    //--------------------------------------------------------------------------
    virtual bool isFlamethrower()const;
    //--------------------------------------------------------------------------
    virtual bool isHighCaliberProjectiles()const;
    //--------------------------------------------------------------------------
    virtual bool isMissiles()const;
    //--------------------------------------------------------------------------
    virtual bool isBullets()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  //  _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERFLAMETHROWER_H_
