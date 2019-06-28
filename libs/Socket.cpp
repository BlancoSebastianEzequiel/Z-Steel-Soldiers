// "Copyright [2017] <SebastianBlanco>"
//------------------------------------------------------------------------------
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <cerrno>
#include <utility>
#include "Socket.h"
#include "Exception.h"
//------------------------------------------------------------------------------
#define ERROR -1
//------------------------------------------------------------------------------
// SOCKET CONSTRUCTOR
//------------------------------------------------------------------------------
Socket::Socket() {}
//------------------------------------------------------------------------------
// SOCKET DESTROY
//------------------------------------------------------------------------------
Socket::~Socket() {
    if (fd >= 0) close(fd);
}
//------------------------------------------------------------------------------
// SOCKET CREATE AND CONNECT
//------------------------------------------------------------------------------
void Socket::socketCreateAndConnect(const char* host, const char* port) {
    struct addrinfo hints;
    struct addrinfo *result;
    struct addrinfo *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV;
    hints.ai_protocol = 0;

    int s = getaddrinfo(host, port, &hints, &result);
    if (s != 0) {
        freeaddrinfo(result);
        throw Exception("ERROR: %s\n", gai_strerror(s));
    }
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (fd == ERROR) continue;
        if (connect(fd, rp->ai_addr, rp->ai_addrlen) != ERROR) break;
        close(fd);
    }
    if (rp == NULL) {
        freeaddrinfo(result);
        throw Exception("Could not find any valid address\n");
    }
    freeaddrinfo(result);
}
//------------------------------------------------------------------------------
// SOCKET CREATE AND BIND AND LISTEN
//------------------------------------------------------------------------------
void Socket::socketCreateAndBindAndListen(const char *port, int listenQuant) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int s;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    // El 'servicio' sera un puerto numerico "hardcodeado"
    hints.ai_flags = AI_NUMERICSERV;

    s = getaddrinfo(NULL, port, &hints, &result);
    if (s != 0) {
        freeaddrinfo(result);
        throw Exception(
                "ERROR: %s - getaddrinfo ha fallado\n", gai_strerror(s));
    }
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (fd == -1) {
            continue;
        }
        // Activo la opcion de Reusar la Direccion en caso de que no este
        // disponible por un TIME_WAIT
        int val = 1;
        s = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (s == ERROR) {
            close(fd);
            freeaddrinfo(result);
            throw Exception("Could not activate the option of reusing the "
             "address in caso of not being available because of a TIME Wait\n");
        }
        if (bind(fd, rp->ai_addr, rp->ai_addrlen) == 0) {
            break;
        }
        close(fd);
    }
    freeaddrinfo(result);
    if (rp == NULL) {
        throw Exception("Could not find any valid address\n");
    }
    if (listen(fd, listenQuant) == ERROR) {
        throw Exception("Could not listen\n");
    }
}
//------------------------------------------------------------------------------
// SOCKET ACCEPT
//------------------------------------------------------------------------------
Socket Socket::socketAccept() {
    struct sockaddr client;
    int newfd;
    socklen_t clientLength = (socklen_t)sizeof(struct sockaddr);
    newfd = accept(fd, &client, &clientLength);
    if (newfd == ERROR) {
        throw Exception("Could not accept a new file descriptor. %s\n",
                      strerror(errno));
    }
    Socket newSocket;
    newSocket.fd = newfd;
    return newSocket;
}
//------------------------------------------------------------------------------
// SOCKET SHUTDOWN
//------------------------------------------------------------------------------
void Socket::socketShutdown(int mode) {
    if (shutdown(fd, mode) == ERROR) {
        throw Exception("Could not shutdown the socket. %s\n", strerror(errno));
    }
    isShutdown = true;
}
//------------------------------------------------------------------------------
// SOCKET SEND
//------------------------------------------------------------------------------
size_t Socket::socketSend(const char *buffer, size_t bytesToSend) {
    size_t bytesSent = 0;
    ssize_t s = 0;
    while (bytesSent < bytesToSend) {
        const void* pointer = &buffer[bytesSent];
        s = send(fd, pointer, bytesToSend-bytesSent, MSG_NOSIGNAL);
        if (s == 0) {
            return 0;
            // throw OSError("Socket has been shutdown\n");
        } else if (s < 0) {
            throw Exception("Send returned -1. ERROR: %s\n", strerror(errno));
        } else {
            bytesSent += s;
        }
    }
    return bytesSent;
}
//------------------------------------------------------------------------------
// SOCKET RECEIVE
//------------------------------------------------------------------------------
size_t Socket::socketReceive(char* buffer, size_t bytesToReceive) {
    size_t bytesReceived = 0;
    ssize_t s = 0;
    while (bytesReceived < bytesToReceive) {
        void* pointer = &buffer[bytesReceived];
        s = recv(fd, pointer, bytesToReceive-bytesReceived, MSG_NOSIGNAL);
        if (s == 0) {  // the socket has been closed
            return 0;
            // throw OSError("Socket has been shutdown\n");
        } else if (s < 0) {  // there has been an error
            throw Exception("Recv returned -1. ERROR: %s\n", strerror(errno));
        } else {
            bytesReceived += s;
        }
    }
    return bytesReceived;
}
//------------------------------------------------------------------------------
// IS SHUT
//------------------------------------------------------------------------------
bool Socket::isShut() {
    return isShutdown;
}
//------------------------------------------------------------------------------
// KILL
//------------------------------------------------------------------------------
void Socket::kill() {
    fd = -1;
}
//------------------------------------------------------------------------------
