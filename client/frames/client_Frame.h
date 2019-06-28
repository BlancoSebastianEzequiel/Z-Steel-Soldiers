#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED
//------------------------------------------------------------------------------
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//------------------------------------------------------------------------------
class Frame {
 private :
    SDL_Surface* image;
 public :
    //--------------------------------------------------------------------------
    // Carga la imagen pasada por parametro en el frame
    explicit Frame(std::string filepath);
    //--------------------------------------------------------------------------
    // Libera al frame de la imagen actual
    void unload();
    //--------------------------------------------------------------------------
    // Devuelve una referencia a la imagen del fotograma
    SDL_Surface* get_image();
    //--------------------------------------------------------------------------
};
#endif  // FRAME_H_INCLUDED
