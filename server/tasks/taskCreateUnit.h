#ifndef TASK_CREATE_UNIT_H
#define TASK_CREATE_UNIT_H

#include <ctime>
#include <string>
#include "task.h"

class Game;

class TaskCreateUnit: public Task {
private :
    size_t idBuilding;
    size_t type;
public :
    TaskCreateUnit(Game &aGame, size_t idBuilding, size_t type);
    ~TaskCreateUnit() override;
    void execute() override;
    bool isRelocable()const override;
};

#endif // TASK_CREATE_UNIT_H
