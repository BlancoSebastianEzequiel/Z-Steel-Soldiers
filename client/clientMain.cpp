// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <iostream>
#include "client.h"
#include "../libs/Exception.h"
//------------------------------------------------------------------------------
#define SUCCESS 0
#define ERROR 1
//------------------------------------------------------------------------------
// MAIN
//------------------------------------------------------------------------------
int main() try {
    Client client;
    client.run();
    return SUCCESS;
} catch (const Exception& e) {
    printf("%s", e.what());
    return ERROR;
}
//------------------------------------------------------------------------------
