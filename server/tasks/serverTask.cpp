// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#include <tgmath.h>
#include "serverTask.h"
//------------------------------------------------------------------------------
// SERVER TASK CONSTRUCTOR
//------------------------------------------------------------------------------
ServerTask::ServerTask(ServerGame& aGame): aGame(aGame) {
    time(&timer);
}
//------------------------------------------------------------------------------
// SERVER TASK DESTRUCTOR
//------------------------------------------------------------------------------
ServerTask::~ServerTask() {}
//------------------------------------------------------------------------------
// CHANGE WAITING TIME
//------------------------------------------------------------------------------
void ServerTask::changeWaitingTime(double newWaitingTime) {
    time(&timer);
    waitingTime = newWaitingTime;
}
//------------------------------------------------------------------------------
// EXECUTABLE
//------------------------------------------------------------------------------
bool ServerTask::executable() {
    double timeElapsed =  difftime(time(nullptr), timer);
    return timeElapsed >= (waitingTime);
}
//------------------------------------------------------------------------------
