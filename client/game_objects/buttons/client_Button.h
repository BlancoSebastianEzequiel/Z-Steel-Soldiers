#ifndef CLIENT_BUTTON_H_INCLUDED
#define CLIENT_BUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include <vector>
#include "../../frames/client_Frame.h"
#include "../client_GameObject.h"
#include "../../cameras/client_Camera.h"
#include "../../proxys/clientProxyGame.h"
//------------------------------------------------------------------------------
class ClientButton: public GameObject{
 protected :
    bool visible;
    std::vector<Frame> frames;
 public :
    //--------------------------------------------------------------------------
    ClientButton(unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    ~ClientButton();
    //--------------------------------------------------------------------------
    virtual void handle_click(ClientProxyGame& proxyGame) = 0;
    //--------------------------------------------------------------------------
    void draw(SDL_Surface* screen, ClientCamera& camera);
    //--------------------------------------------------------------------------
    void show();
    //--------------------------------------------------------------------------
    void hide();
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_BUTTON_H_INCLUDED
