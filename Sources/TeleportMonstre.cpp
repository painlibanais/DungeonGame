#include "TeleportMonstre.h"
#include "getRandom.h"

TeleportMonstre::TeleportMonstre(int level, Point *position)
        : Monstre('%', level, position) {
    random = true;
    force = level * 5;
    defense = level * 0.1;
}

void TeleportMonstre::toString() {
    std::cout << "Type : TELEPORTMONSTRE" << std::endl;
}

void TeleportMonstre::startIntelligence(bool val) {
    random = true;
}

Point *TeleportMonstre::doRandomMove(Point *heros) {
    int rand = getRandom(0, 101);
    if (rand < 70) {
        int rand = getRandom(0, 4);

        switch (rand) {
            case 0:
                return (toGo = getNextPoint('z'));
                break;

            case 1:
                return (toGo = getNextPoint('q'));
                break;

            case 2:
                return (toGo = getNextPoint('s'));
                break;

            case 3:
                return (toGo = getNextPoint('d'));
                break;
        }
    } else {
        Point *p = new Point(getRandom(0, 120), getRandom(0, 25));
        return (toGo = p);
    }
}

void TeleportMonstre::move() {
    position = toGo;
}
