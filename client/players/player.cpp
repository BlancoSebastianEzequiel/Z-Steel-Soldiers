// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <sys/socket.h>
#include "player.h"
#include "../maps/map.h"
#include "../proxys/proxyGame.h"
#include "../event_handlers/mouseEventHandler.h"
#include "../event_handlers/keyboardEventHandler.h"
//------------------------------------------------------------------------------
#define WIDTH 12*64  // ancho de la ventana contenedora
#define HEIGHT 12*57  // alto de la ventana contenedora
#define BPP 24  // cantidad de bits por pixel (para los colores)
#define FRAME_RATE 5
#define WAIT_TIME 1000000
//------------------------------------------------------------------------------
// CLIENT PLAYER CONSTRUCTOR
//------------------------------------------------------------------------------
Player::Player(
        size_t idTeam, ProxyGame& proxyGame, petitions_t& petitions):
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
Player::~Player() {}
//------------------------------------------------------------------------------
// INITIALIZER
//------------------------------------------------------------------------------
void Player::initializer(SDL_Surface*& screen) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception("No se pudo iniciar SDL: %s", SDL_GetError());
    } else {
        // Inicio el modo de video de SDL y le doy a screen la responsabilidad
        screen = SDL_SetVideoMode(
                WIDTH, HEIGHT, BPP, SDL_SWSURFACE|SDL_DOUBLEBUF);
        if (screen == nullptr) {
            throw Exception("No se pudo crear la ventana: %s", SDL_GetError());
        }
    }
}
//------------------------------------------------------------------------------
// RUN
//------------------------------------------------------------------------------
void Player::run() try {
    SDL_Event event;
    initializer(screen);
    Camera camera;
    camera.set_screen(screen);
    while (!charged) {
        usleep(WAIT_TIME);
    }
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
    printf("Exception catched at player: %s", e.what());
}
//------------------------------------------------------------------------------
// SET ID
//------------------------------------------------------------------------------
void Player::setIdPlayer(size_t id) {
    idPlayer = id;
}
//------------------------------------------------------------------------------
// GET ID TEAM
//------------------------------------------------------------------------------
size_t Player::getIdTeam() {
    return idTeam;
}
//------------------------------------------------------------------------------
// STOP
//------------------------------------------------------------------------------
void Player::stop() {
    finish = true;
}
//------------------------------------------------------------------------------
