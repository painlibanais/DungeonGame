//
// Created by Mohammed on 13/01/2018.
//

#ifndef DUNGEONGAME_RIGHTHEROSOBSERVER_H
#define DUNGEONGAME_RIGHTHEROSOBSERVER_H


#include "Observer.h"
#include "Stage.h"

class RightHerosObserver : public Observer {
public:
    RightHerosObserver(Heros *heros, Stage *map);

    void update() override;
};


#endif //DUNGEONGAME_RIGHTHEROSOBSERVER_H
