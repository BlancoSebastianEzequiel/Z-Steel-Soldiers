#ifndef CLIENT_BUTTON_H_INCLUDED
#define CLIENT_BUTTON_H_INCLUDED
//------------------------------------------------------------------------------
#include <vector>
#include "../../frames/frame.h"
#include "../gameObject.h"
#include "../../cameras/camera.h"
#include "../../proxys/proxyGame.h"
//------------------------------------------------------------------------------
class Button: public GameObject {
 protected :
    bool visible;
    std::vector<Frame> frames;
 public :
    //--------------------------------------------------------------------------
    Button(unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    ~Button();
    //--------------------------------------------------------------------------
    virtual void handle_click(ProxyGame& proxyGame) = 0;
    //--------------------------------------------------------------------------
    void draw(SDL_Surface* screen, Camera& camera);
    //--------------------------------------------------------------------------
    void show();
    //--------------------------------------------------------------------------
    void hide();
    //--------------------------------------------------------------------------
};
#endif  // CLIENT_BUTTON_H_INCLUDED
