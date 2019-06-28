#ifndef CLIENT_KEYBOARDEVENTHANDLER_H_INCLUDED
#define CLIENT_KEYBOARDEVENTHANDLER_H_INCLUDED
//------------------------------------------------------------------------------
#include "../cameras/client_Camera.h"
//------------------------------------------------------------------------------
class KeyboardEventHandler {
 private :
    unsigned int player_id;
    ClientCamera& camera;
 public :
    //--------------------------------------------------------------------------
    explicit KeyboardEventHandler(ClientCamera& camera);
    //--------------------------------------------------------------------------
    // Dado un SDL_Event, decide como se lo maneja
    void handle_event(SDL_Event& event);
    //--------------------------------------------------------------------------
    void set_camera(ClientCamera& camera);
    //--------------------------------------------------------------------------
    void set_player_id(unsigned int player_id);
    //--------------------------------------------------------------------------
};
#endif // CLIENT_KEYBOARDEVENTHANDLER_H_INCLUDED
