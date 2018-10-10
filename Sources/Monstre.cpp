#include "Monstre.h"
#include "getRandom.h"

Monstre::Monstre(char symbole, int level, Point *position)
        : Personnage(symbole, level, position), random(true) {
    force = level;
    defense = level;
}

Point *Monstre::doRandomMove(Point *heros) {
    int rand = getRandom(0, 4);
    toMove = rand;

    switch (rand) {
        case 0:
            return getNextPoint('z');
            break;

        case 1:
            return getNextPoint('q');
            break;

        case 2:
            return getNextPoint('s');
            break;

        case 3:
            return getNextPoint('d');
            break;
    }
}

void Monstre::move() {
    switch (toMove) {
        case 0:
            Personnage::moveUp();
            break;

        case 1:
            Personnage::moveLeft();
            break;

        case 2:
            Personnage::moveDown();
            break;

        case 3:
            Personnage::moveRight();
            break;
    }
}

int Monstre::getSalle() const {
    return salle;
}

void Monstre::setSalle(int salle) {
    Monstre::salle = salle;
}
