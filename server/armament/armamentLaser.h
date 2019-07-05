// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERARMAMENTLASER_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERARMAMENTLASER_H_
//------------------------------------------------------------------------------
#include "armament.h"
//------------------------------------------------------------------------------
class ArmamentLaser: public Armament {
 public :
    //--------------------------------------------------------------------------
    ArmamentLaser(const Node& position, size_t id, const Unit& shooter);
    //--------------------------------------------------------------------------
    ~ArmamentLaser();
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
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERARMAMENTLASER_H_
