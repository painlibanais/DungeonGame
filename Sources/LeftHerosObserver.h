//
// Created by Mohammed on 13/01/2018.
//

#ifndef DUNGEONGAME_LEFTHEROSOBSERVER_H
#define DUNGEONGAME_LEFTHEROSOBSERVER_H


#include "Observer.h"

class LeftHerosObserver : public Observer {

public:
    LeftHerosObserver(Heros *heros, Stage *map);

    void update() override;
};


#endif //DUNGEONGAME_LEFTHEROSOBSERVER_H
