#include <iostream>
#include "getRandom.h"

int getRandom(int min, int max) {
    return rand() % (max - min) + min;
};

char getMove() {
    char move;
    std::cin >> move;
    return move;
};

