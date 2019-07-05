#ifndef CLIENT_OUTCOMEWINDOW_H_INCLUDED
#define CLIENT_OUTCOMEWINDOW_H_INCLUDED
#include "../frames/frame.h"
#include <string>

class OutcomeWindow {
    private:
        Frame frame;
    public:
        explicit OutcomeWindow(std::string result);
        ~OutcomeWindow();
        void draw(SDL_Surface* screen);
};


#endif // CLIENT_OUTCOMEWINDOW_H_INCLUDED
