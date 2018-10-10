#ifndef DUNGEONGAME_MONSTRE_H
#define DUNGEONGAME_MONSTRE_H


#include "Personnage.h"
#include <iostream>

class Monstre : public Personnage {
protected:
    bool random;
    int toMove;
    int salle;
public:
    Monstre(char symbole, int level, Point *position);

    virtual void startIntelligence(bool val) = 0;

    virtual void move();

    virtual Point *doRandomMove(Point *heros);

    int getSalle() const;

    void setSalle(int salle);
};


#endif //DUNGEONGAME_MONSTRE_H
