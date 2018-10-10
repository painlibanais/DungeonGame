#ifndef DUNGEONGAME_CREATEMONSTRE_H
#define DUNGEONGAME_CREATEMONSTRE_H


#include "Monstre.h"

class FactoryMonstre {
public:
    static Monstre *createMonstre(int level, Point *position);
};


#endif //DUNGEONGAME_CREATEMONSTRE_H
