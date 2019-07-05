#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <string>
#include <cstring>
#include "frame.h"
//------------------------------------------------------------------------------
// FRAME CONSTRUCTOR
//------------------------------------------------------------------------------
Frame::Frame(std::string filepath) {
    // Cargo la imagen en la superficie
    std::string path = PATH_TO_IMAGE;
    path += filepath;
    image = IMG_Load(path.c_str());
    // Si la imagen tiene fondo negro, lo hago transparente
    SDL_SetColorKey(
            image, SDL_SRCCOLORKEY | SDL_RLEACCEL,
            SDL_MapRGB(image->format, 0, 0, 0)
    );
}
//------------------------------------------------------------------------------
// UNLOAD
//------------------------------------------------------------------------------
void Frame::unload() {
    SDL_FreeSurface(this->image);
}
//------------------------------------------------------------------------------
// FRAME CONSTRUCTOR
//------------------------------------------------------------------------------
SDL_Surface* Frame::get_image() {
    return this->image;
}
//------------------------------------------------------------------------------
