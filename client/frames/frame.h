#ifndef FRAME_H
#define FRAME_H
//------------------------------------------------------------------------------
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#define PATH_TO_IMAGE "pics/"
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
#endif  // FRAME_H
