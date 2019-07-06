#ifndef CREATE_MML_BUTTON_H
#define CREATE_MML_BUTTON_H
//------------------------------------------------------------------------------
#include "../../frames/frame.h"
#include "button.h"
#include "../../proxys/proxyGame.h"

//------------------------------------------------------------------------------
class CreateMMLButton: public Button {
 public :
    //--------------------------------------------------------------------------
    CreateMMLButton(
            unsigned int id, unsigned int pos_x, unsigned int pos_y);
    //--------------------------------------------------------------------------
    void handle_click(ProxyGame &proxyGame);
    //--------------------------------------------------------------------------
};
#endif // CREATE_MML_BUTTON_H
