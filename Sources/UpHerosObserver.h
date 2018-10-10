//
// Created by Mohammed on 13/01/2018.
//

#ifndef DUNGEONGAME_HEROSOBSERVER_H
#define DUNGEONGAME_HEROSOBSERVER_H

#include <vector>
#include "Observer.h"
#include "Stage.h"

class UpHerosObserver : public Observer {
public:
    UpHerosObserver(Heros *heros, Stage *map);

    void update() override;

};


#endif //DUNGEONGAME_HEROSOBSERVER_H
