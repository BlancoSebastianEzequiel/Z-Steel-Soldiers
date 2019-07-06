#ifndef OUTCOMEWINDOW_H
#define OUTCOMEWINDOW_H
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


#endif // OUTCOMEWINDOW_H
