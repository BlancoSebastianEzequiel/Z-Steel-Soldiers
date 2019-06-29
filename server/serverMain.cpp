// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <iostream>
#include "../libs/Exception.h"
#include "server.h"
#include "serverFinish.h"
//------------------------------------------------------------------------------
#define SUCCESS 0
#define ERROR 1
//------------------------------------------------------------------------------
// MAIN
//------------------------------------------------------------------------------
int main() try {
    Server aServer;
    Finish finish(aServer);
    finish.start();
    aServer.mainLoop();
    finish.join();
    return SUCCESS;
} catch (const Exception& e) {
    printf("Exception catched at main: %s", e.what());
    return ERROR;
}
//------------------------------------------------------------------------------
