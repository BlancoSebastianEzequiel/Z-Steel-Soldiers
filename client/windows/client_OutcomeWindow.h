#ifndef CLIENT_OUTCOMEWINDOW_H_INCLUDED
#define CLIENT_OUTCOMEWINDOW_H_INCLUDED
#include "../frames/client_Frame.h"
#include <string>

class ClientOutcomeWindow {
    private:
        Frame frame;
    public:
        explicit ClientOutcomeWindow(std::string result);
        ~ClientOutcomeWindow();
        void draw(SDL_Surface* screen);
};


#endif // CLIENT_OUTCOMEWINDOW_H_INCLUDED
