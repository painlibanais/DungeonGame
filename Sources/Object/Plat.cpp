#include "Plat.h"

Plat::Plat(int id)
        : PlayableElement('.', id) {}

void Plat::toString() {
    std::cout << "Type : PLAT" << std::endl;
}
