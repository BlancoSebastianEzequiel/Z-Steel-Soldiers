// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <sys/socket.h>
#include "clientPlayer.h"
#include "../maps/client_Map.h"
#include "../proxys/clientProxyGame.h"
#include "../event_handlers/client_MouseEventHandler.h"
#include "../event_handlers/client_KeyboardEventHandler.h"
//------------------------------------------------------------------------------
#define WIDTH 12*64  // ancho de la ventana contenedora
#define HEIGHT 12*57  // alto de la ventana contenedora
#define BPP 24  // cantidad de bits por pixel (para los colores)
#define FRAME_RATE 5
//------------------------------------------------------------------------------
// CLIENT PLAYER CONSTRUCTOR
//------------------------------------------------------------------------------
ClientPlayer::ClientPlayer(
        size_t idTeam, ClientProxyGame& proxyGame, petitions_t& petitions):
      idTeam(idTeam), proxyGame(proxyGame),
      communicator(socket, petitions, proxyGame, *this), aMap(proxyGame) {
    charged = false;
    finish = false;
    screen = nullptr;
    communicator.start();
    proxyGame.createPlayer(idTeam);
    proxyGame.getInitialModel();
}
//------------------------------------------------------------------------------
// CLIENT PLAYER DESTRUCTOR
//------------------------------------------------------------------------------
ClientPlayer::~ClientPlayer() {}
//------------------------------------------------------------------------------
// INITIALIZER
//------------------------------------------------------------------------------
void ClientPlayer::initializer(SDL_Surface*& screen) {
    // Inicio SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "No se pudo iniciar SDL: " << SDL_GetError() << std::endl;
    } else {
        // Inicio el modo de video de SDL y le doy a screen la responsabilida
        screen = SDL_SetVideoMode(
                WIDTH, HEIGHT, BPP, SDL_SWSURFACE|SDL_DOUBLEBUF);
        if (screen == nullptr) {
            std::cout << "No se pudo crear la ventana: ";
            std::cout << SDL_GetError() << std::endl;
        }
    }
}
//------------------------------------------------------------------------------
// RUN
//------------------------------------------------------------------------------
void ClientPlayer::run() try {
    SDL_Event event;
    initializer(screen);
    ClientCamera camera;
    camera.set_screen(screen);
    while (!charged) printf(" ");
    aMap.drawMap();
    MouseEventHandler mouse_handler(proxyGame, camera);
    KeyboardEventHandler keyboardEventHandler(camera);
    mouse_handler.set_player_id((unsigned int)idPlayer);
    mouse_handler.set_map(&aMap);
    //--------------------------------------------------------------------------
    bool running = true;
    int cont = 0;
    if (screen) {
        unsigned int timerfps;
        while (running && !finish) {
            timerfps = SDL_GetTicks();
            // Dibujo la escena
            aMap.draw(screen, camera);
            // Lo muestro
            SDL_Flip(screen);
            // veo si ocurre algun evento con el usuario
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_KEYDOWN) {
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        running = false;
                    }
                }
                mouse_handler.handle_event(event);
                keyboardEventHandler.handle_event(event);
            }
            timerfps = SDL_GetTicks() - timerfps;
            // Renderizo con 30 fps
            if (timerfps < 1000 / FRAME_RATE) {
                SDL_Delay((1000 / FRAME_RATE) - timerfps);
            }
            if (cont % 6 == 0) {
                proxyGame.getModel();
                proxyGame.update();
                aMap.updateMap();
            }
            cont++;
        }
    }
    // Libero los recursos utilizados por la libreria
    SDL_Quit();
    communicator.stop();
} catch (const Exception& e) {
    printf("%s", e.what());
}
//------------------------------------------------------------------------------
// SET ID
//------------------------------------------------------------------------------
void ClientPlayer::setIdPlayer(size_t id) {
    idPlayer = id;
}
//------------------------------------------------------------------------------
// GET ID TEAM
//------------------------------------------------------------------------------
size_t ClientPlayer::getIdTeam() {
    return idTeam;
}
//------------------------------------------------------------------------------
// STOP
//------------------------------------------------------------------------------
void ClientPlayer::stop() {
    finish = true;
}
//------------------------------------------------------------------------------
