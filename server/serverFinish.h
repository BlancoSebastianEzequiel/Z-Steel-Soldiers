// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TP3_SERVERFINISH_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TP3_SERVERFINISH_H_
//------------------------------------------------------------------------------
class Server;
//------------------------------------------------------------------------------
#include "../libs/Threads.h"
#include <unistd.h>
//------------------------------------------------------------------------------
#define FINISH 'q'
#define WAIT_TIME 1000000
//------------------------------------------------------------------------------
class Finish: public Thread {
 private :
    Server& aServer;
 public :
    //--------------------------------------------------------------------------
    explicit Finish(Server& aServer);
    //--------------------------------------------------------------------------
    /*
    * pre:
    * pos: Si recibe por entrada estandar una q termina la ejecucion del server
     * y la ejecucion del hilo collect.En caso contrario vuelve a esperar por
     * dicho caracter.
    */
    virtual void run();
    //--------------------------------------------------------------------------
    ~Finish();
    //--------------------------------------------------------------------------
};

#endif   // _HOME_SEBASTIAN_CLIONPROJECTS_TP3_SERVERFINISH_H_
