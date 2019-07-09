#ifndef TASK_CREATE_UNIT_H
#define TASK_CREATE_UNIT_H

#include <ctime>
#include <string>
#include "task.h"

class Game;

class TaskCreateRobot: public Task {
private :
    size_t idBuilding;
    size_t type;
public :
    TaskCreateRobot(Game &aGame, size_t idBuilding, size_t type);
    ~TaskCreateRobot() override;
    void execute() override;
    bool isRelocable()const override;
};

#endif // TASK_CREATE_UNIT_H
