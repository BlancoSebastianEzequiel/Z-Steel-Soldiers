// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYNODE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYNODE_H_
//------------------------------------------------------------------------------
class ClientProxyTerritories;
class ClientProxyObject;
//------------------------------------------------------------------------------
#include <vector>
#include <memory>
//------------------------------------------------------------------------------
class ClientProxyNode {
 protected :
    const uint32_t x;
    const uint32_t y;
    const std::string type;
    ClientProxyObject* anObject;
    bool wasAnObjectAdded;
    float groundFactor;
    const ClientProxyTerritories* territory;
 public :
    //--------------------------------------------------------------------------
    ClientProxyNode(uint32_t x, uint32_t y, std::string type);
    //--------------------------------------------------------------------------
    ~ClientProxyNode();
    //--------------------------------------------------------------------------
    bool operator==(const ClientProxyNode& otherNode)const;
    //--------------------------------------------------------------------------
    bool operator!=(const ClientProxyNode& otherNode)const;
    //--------------------------------------------------------------------------
    void showNode()const;
    //--------------------------------------------------------------------------
    void setGroundFactor(float groundFactor);
    //--------------------------------------------------------------------------
    void addObject(ClientProxyObject *anObjectToAdd);
    //--------------------------------------------------------------------------
    bool hasAnObject()const;
    //--------------------------------------------------------------------------
    const ClientProxyObject* getGroundObject()const;
    //--------------------------------------------------------------------------
    void addTerritory(const ClientProxyTerritories& aTerritory);
    //--------------------------------------------------------------------------
    size_t getIdTerritory()const;
    //--------------------------------------------------------------------------
    const size_t getOwnerId()const;
    //--------------------------------------------------------------------------
    const float& getGroundFactor()const;
    //--------------------------------------------------------------------------
    bool isLava()const;
    //--------------------------------------------------------------------------
    bool isDust()const;
    //--------------------------------------------------------------------------
    bool isGrass()const;
    //--------------------------------------------------------------------------
    bool isSnow()const;
    //--------------------------------------------------------------------------
    bool isWater()const;
    //--------------------------------------------------------------------------
    bool isSwamp()const;
    //--------------------------------------------------------------------------
    bool isRoad()const;
    //--------------------------------------------------------------------------
    bool isAsphaltRoad()const;
    //--------------------------------------------------------------------------
    const uint32_t getX()const;
    //--------------------------------------------------------------------------
    const uint32_t getY()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYNODE_H_
