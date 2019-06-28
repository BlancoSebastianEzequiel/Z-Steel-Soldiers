// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTERRITORIES_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTERRITORIES_H_
//------------------------------------------------------------------------------
class ServerNode;
class ServerPlayer;
class ServerFlag;
class ServerBuildings;
//------------------------------------------------------------------------------
#include <vector>
#include <cstdlib>
//------------------------------------------------------------------------------
class ServerTerritories {
 private :
    const size_t id;
    std::vector<ServerNode*> nodes;
    ServerPlayer* player;
 public :
    //--------------------------------------------------------------------------
    explicit ServerTerritories(const size_t id);
    //--------------------------------------------------------------------------
    ~ServerTerritories();
    //--------------------------------------------------------------------------
    void addNode(ServerNode& aNode);
    //--------------------------------------------------------------------------
    std::vector<ServerNode*>& getNodes();
    //--------------------------------------------------------------------------
    const size_t& getId()const;
    //--------------------------------------------------------------------------
    void changePlayer(ServerPlayer& aPlayer);
    //--------------------------------------------------------------------------
    bool hasAFort()const;
    //--------------------------------------------------------------------------
    ServerBuildings* getBuilding()const;
    //--------------------------------------------------------------------------
    bool hasAPlayer()const;
    //--------------------------------------------------------------------------
    const ServerPlayer* getOwner()const;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERTERRITORIES_H_
