#include "Empty.h"

Empty::Empty()
        : NotPlayableElement(' ') {}

void Empty::toString() {
    std::cout << "Type : EMPTY" << std::endl;
}

