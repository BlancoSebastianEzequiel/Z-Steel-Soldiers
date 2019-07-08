// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef HIGH_CALIBER_PROJECTILES_H
#define HIGH_CALIBER_PROJECTILES_H
//------------------------------------------------------------------------------
#include "armament.h"
//------------------------------------------------------------------------------
class HighCaliberProjectiles : public Armament {
 public :
    //--------------------------------------------------------------------------
    HighCaliberProjectiles(const Node& position, size_t id, const Unit& shooter);
    //--------------------------------------------------------------------------
    ~HighCaliberProjectiles();
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

#endif  // HIGH_CALIBER_PROJECTILES_H
