//
// Created by Mohammed on 13/01/2018.
//

#ifndef DUNGEONGAME_DOWNHEROSOBSERVER_H
#define DUNGEONGAME_DOWNHEROSOBSERVER_H


#include "Observer.h"

class DownHerosObserver : public Observer {
public:
    DownHerosObserver(Heros *heros, Stage *map);

    void update() override;
};


#endif //DUNGEONGAME_DOWNHEROSOBSERVER_H
