#include "IntelligentMonstre.h"
#include "getRandom.h"
#include "Distance.h"

IntelligentMonstre::IntelligentMonstre(int level, Point *position)
        : Monstre('&', level, position) {
    random = true;
    force = level * 0.5;
    defense = level * 1;
}

void IntelligentMonstre::toString() {
    std::cout << "Type : INTELLIGENTMONSTRE" << std::endl;
}

void IntelligentMonstre::startIntelligence(bool val) {
    if (val)
        random = !val;
}

Point *IntelligentMonstre::doRandomMove(Point *heros) {
    if (random) {
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
    } else {
        Point* p = new Point;
        p->setX(position->getX()-1);
        p->setY(position->getY());

        if (Distance(p, heros) < Distance(position, heros)) {
            toMove = 1;
            return getNextPoint('q');
        }
        p = new Point;
        p->setX(position->getX()+1);
        p->setY(position->getY());

        if (Distance(p, heros) < Distance(position, heros)) {
            toMove =3;
            return getNextPoint('d');
        }
        p->setX(position->getX());
        p->setY(position->getY()-1);

        if (Distance(p, heros) < Distance(position, heros)) {
            toMove = 0;
            return getNextPoint('z');
        }
        p->setX(position->getX());
        p->setY(position->getY()+1);

        if (Distance(p, heros) < Distance(position, heros)) {
            toMove = 2;
            return getNextPoint('s');
        }
    }
}
