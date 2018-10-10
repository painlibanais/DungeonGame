//
// Created by Mohammed on 13/01/2018.
//

#include "Observer.h"
#include "Heros.h"

Observer::Observer(Heros *heros, Stage *map)
        : heros(heros), map(map) {}

Observer::~Observer() {
    heros->detach(this);
}