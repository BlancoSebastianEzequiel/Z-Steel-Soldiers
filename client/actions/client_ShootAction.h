#ifndef CLIENT_SHOOTACTION_H_INCLUDED
#define CLIENT_SHOOTACTION_H_INCLUDED
#include "../game_objects/units/client_Unit.h"
#include "client_UnitAction.h"
class Unit;
class ShootAction: public UnitAction{
    private:
        GameObject* target;

    public:
        ShootAction(Unit* unit,GameObject* target);
        void execute();
        //Termina de disparar
        void finish();
};

#endif // CLIENT_SHOOTACTION_H_INCLUDED
