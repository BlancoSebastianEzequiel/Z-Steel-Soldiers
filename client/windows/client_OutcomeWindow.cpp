#include "client_OutcomeWindow.h"
#include <string>
using std::string;

ClientOutcomeWindow::ClientOutcomeWindow(string result):
    frame("Result/" + result + ".png"){
}

ClientOutcomeWindow::~ClientOutcomeWindow(){
    frame.unload();
}

void ClientOutcomeWindow::draw(SDL_Surface* screen){
    SDL_Rect container;
    container.x = 0;
    container.y = 0;
    /**Cargo el fotograma actual del sprite en la superficie pasada por
    parametro, habitualmente es donde luego sera mostrado el sprite**/
    SDL_BlitSurface(frame.get_image(),NULL,screen,&container);
}
