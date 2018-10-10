//
// Created by Mohammed on 13/01/2018.
//

#ifndef DUNGEONGAME_OBSERVER_H
#define DUNGEONGAME_OBSERVER_H

#include <vector>
#include "Stage.h"

class Map;
class Heros;
class Salle;

class Observer {
protected:
    Heros *heros;
    Stage *map;

public:
    Observer(Heros *heros, Stage *map);

    virtual void update() = 0;

    ~Observer();
};

#endif //DUNGEONGAME_OBSERVER_H
