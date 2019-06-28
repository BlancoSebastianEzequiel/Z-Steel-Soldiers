// "Copyright [2017] <SebastianBlanco>"
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TP3_COMMONSOCKET_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TP3_COMMONSOCKET_H_
//------------------------------------------------------------------------------
#include <string.h>
#include <stdio.h>
//------------------------------------------------------------------------------
class Socket {
 private :
    bool isShutdown = false;
 public :
    int fd;
 public :
    //--------------------------------------------------------------------------
    Socket();
    //--------------------------------------------------------------------------
    /*
     * pre:
     * pos: le hace close al file descriptor si es distinto de -1.
     */
    ~Socket();
    //--------------------------------------------------------------------------
    /*
     * pre: Un socket fue declarado. Recibe la direccion host y el puerto
     * pos: Conecta al socket y le crea un file descriptor. Si hubo un error,
     * devuelve una excepcion con el mensaje correspondiente.
     */
    void socketCreateAndConnect(const char *host, const char *port);
    //--------------------------------------------------------------------------
    /*
     * pre: Un socket fue declarado. Recibe el puerto y la cantidad de socket
     * a esperar en la cola de aceptados.
     * pos: Enlaza la coneccion y le crea un file descriptor. Si hubo un error,
     * devuelve una excepcion con el mensaje correspondiente.
     */
    void socketCreateAndBindAndListen(const char *port, int listenQuant);
    //--------------------------------------------------------------------------
    /*
     * pre: Un socket fue declarado.
     * pos: Epera hasta aceptar un nuevo socket. Si hubo un error, devuelve
     * una excepcion con el mensaje correspondiente.
     */
    Socket socketAccept();
    //--------------------------------------------------------------------------
    /*
     * pre: Un socket fue declarado y recibe el modo de cierre.
     * pos: Cierra el socket. Si hubo un error, devuelve una excepcion con el
     * mensaje correspondiente.
     */
    void socketShutdown(int mode);
    //--------------------------------------------------------------------------
    /*
     * pre: Un socket fue declarado y un puntero a char y la cantidad de bytes
     * a enviar.
     * pos: Devuelve la cantidad de bytes enviados en caso de exito. Si hubo un
     * error, devuelve una excepcion con el mensaje correspondiente. Si el
     * socket fue cerrado devuelve cero.
     */
    size_t socketSend(const char *buffer, size_t bytesToSend);
    //--------------------------------------------------------------------------
    /*
     * pre: Un socket fue declarado y un puntero a char y la cantidad de bytes
     * a recibir.
     * pos: Devuelve la cantidad de bytes recibidos en caso de exito. Si hubo un
     * error, devuelve una excepcion con el mensaje correspondiente. Si el
     * socket fue cerrado devuelve cero.
     */
    size_t socketReceive(char *buffer, size_t bytesToReceive);
    //--------------------------------------------------------------------------
    /*
     * pre:
     * pos: Devuelve verdadero o falso si el socket fue cerrado o no.
     */
    bool isShut();
    //--------------------------------------------------------------------------
    /*
     * pre:
     * pos: Pone a -1 el file descriptor del socket para que al copiar los
     * socket no se destruyan el file descriptor en momentos no deseados.
     */
    void kill();
    //--------------------------------------------------------------------------
};

#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TP3_COMMONSOCKET_H_
