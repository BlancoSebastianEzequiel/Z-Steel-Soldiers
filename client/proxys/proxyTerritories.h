// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYTERRITORIES_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYTERRITORIES_H_
//------------------------------------------------------------------------------
class ProxyNode;
//------------------------------------------------------------------------------
#include <vector>
#include <cstdlib>
//------------------------------------------------------------------------------
class ProxyTerritories {
 private :
    const size_t id;
    std::vector<ProxyNode*> nodes;
    size_t ownerId;
 public :
    //--------------------------------------------------------------------------
    explicit ProxyTerritories(const size_t id);
    //--------------------------------------------------------------------------
    ~ProxyTerritories();
    //--------------------------------------------------------------------------
    bool operator==(const ProxyTerritories& otherTerritory);
    //--------------------------------------------------------------------------
    void addNode(ProxyNode& aNode);
    //--------------------------------------------------------------------------
    std::vector<ProxyNode*>& getNodes();
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    void changePlayer(size_t newOwnerId);
    //--------------------------------------------------------------------------
    const size_t& getOwnerId()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYTERRITORIES_H_
