// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERNODEPATH_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERNODEPATH_H_
//------------------------------------------------------------------------------
class ServerNode;
class ServerState;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class ServerNodePath {
 private :
    const ServerNode& node;
    ServerState* state;
    float cumulativeSpeed;
 public :
    //--------------------------------------------------------------------------
    ServerNodePath(
            const ServerNode& aNode, ServerState& state, float cumulativeSpeed);
    //--------------------------------------------------------------------------
    ~ServerNodePath();
    //--------------------------------------------------------------------------
    ServerState* getState()const;
    //--------------------------------------------------------------------------
    const ServerNode& getNode()const;
    //--------------------------------------------------------------------------
    float getCumulativeWaitingTime()const;
    //--------------------------------------------------------------------------
    void changeState(ServerState& newState);
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_SERVERNODEPATH_H_
