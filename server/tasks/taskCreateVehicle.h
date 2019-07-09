//
// Created by sebastian on 08/07/19.
//

#ifndef TASK_CREATE_VEHICLE_H
#define TASK_CREATE_VEHICLE_H

#include <ctime>
#include <string>
#include "task.h"

class Game;

class TaskCreateVehicle: public Task {
private :
    size_t idBuilding;
    std::string type;
public :
    TaskCreateVehicle(Game &aGame, size_t idBuilding, std::string type);
    ~TaskCreateVehicle() override;
    void execute() override;
    bool isRelocable()const override;
};


#endif // TASK_CREATE_VEHICLE_H
