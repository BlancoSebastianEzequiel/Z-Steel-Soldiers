// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef MISSILES_H
#define MISSILES_H
//------------------------------------------------------------------------------
#include "armament.h"
//------------------------------------------------------------------------------
class Missiles: public Armament {
 public :
    //--------------------------------------------------------------------------
    Missiles(const Node& position, size_t id, const Unit& shooter);
    //--------------------------------------------------------------------------
    ~Missiles();
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
#endif  // MISSILES_H
