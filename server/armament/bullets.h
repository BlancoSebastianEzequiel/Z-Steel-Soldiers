// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef BULLETS_H
#define BULLETS_H
//------------------------------------------------------------------------------
#include "armament.h"
//------------------------------------------------------------------------------
class Bullets : public Armament {
 public :
    //--------------------------------------------------------------------------
    Bullets(const Node& position, size_t id, const Unit& shooter);
    //--------------------------------------------------------------------------
    ~Bullets();
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
#endif  // BULLETS_H
