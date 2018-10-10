#include "BasicMonstre.h"

BasicMonstre::BasicMonstre(int level, Point *position)
        : Monstre('E', level, position) {
    force = level*1;
    defense = level*1;
}

void BasicMonstre::toString() {
    std::cout << "Type : BASICMONSTRE" << std::endl;
}

void BasicMonstre::startIntelligence(bool val) {
    random = true;
}
