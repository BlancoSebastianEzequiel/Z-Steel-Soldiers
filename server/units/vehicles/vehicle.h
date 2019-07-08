// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef VEHICLE_H
#define VEHICLE_H
//------------------------------------------------------------------------------
class Node;
//------------------------------------------------------------------------------
#include <cstddef>
#include "../unit.h"
//------------------------------------------------------------------------------
class Vehicle : public Unit {
 protected :
    float baseSpeed;
 public :
    //--------------------------------------------------------------------------
    Vehicle(const Node& initialPosition, size_t id);
    //--------------------------------------------------------------------------
    virtual ~Vehicle();
    //--------------------------------------------------------------------------
    float getBaseSpeed()const;
    //--------------------------------------------------------------------------
    virtual double getCost(const Node& aNode);
    //--------------------------------------------------------------------------
    virtual double getSpeed(const Node& aNode) const;
    //--------------------------------------------------------------------------
    virtual bool canPassThrough(const Node &aNode) const;
    //--------------------------------------------------------------------------
    virtual bool isGrunt()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isTough()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isSniper()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isPsycho()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isPyro()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isLaser()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isJeep()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMML()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isLightTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isMediumTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isHeavyTank()const = 0;
    //--------------------------------------------------------------------------
    virtual bool isVehicle()const;
    //--------------------------------------------------------------------------
    virtual bool isRobot()const;
    //--------------------------------------------------------------------------
 protected :
    //--------------------------------------------------------------------------
    float getDamageVehicleRel() const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif // VEHICLE_H
