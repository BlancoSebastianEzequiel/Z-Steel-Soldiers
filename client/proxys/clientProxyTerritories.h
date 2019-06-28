// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYTERRITORIES_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_CLIENTPROXYTERRITORIES_H_
//------------------------------------------------------------------------------
class ClientProxyNode;
//------------------------------------------------------------------------------
#include <vector>
#include <cstdlib>
//------------------------------------------------------------------------------
class ClientProxyTerritories {
 private :
    const size_t id;
    std::vector<ClientProxyNode*> nodes;
    size_t ownerId;
 public :
    //--------------------------------------------------------------------------
    explicit ClientProxyTerritories(const size_t id);
    //--------------------------------------------------------------------------
    ~ClientProxyTerritories();
    //--------------------------------------------------------------------------
    bool operator==(const ClientProxyTerritories& otherTerritory);
    //--------------------------------------------------------------------------
    void addNode(ClientProxyNode& aNode);
    //--------------------------------------------------------------------------
    std::vector<ClientProxyNode*>& getNodes();
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
