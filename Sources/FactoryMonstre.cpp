#include "FactoryMonstre.h"
#include "getRandom.h"
#include "BasicMonstre.h"
#include "IntelligentMonstre.h"
#include "TeleportMonstre.h"

Monstre *FactoryMonstre::createMonstre(int level, Point *position) {
    int levelMonstre = getRandom(level, level + 3);
    if (levelMonstre == 0)
        levelMonstre = 1;

    int monstreType = getRandom(1, 101);
    switch (monstreType % 10) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            return new BasicMonstre(levelMonstre, position);
            break;
        case 7:
        case 8:
            return new IntelligentMonstre(levelMonstre, position);
            break;
        case 9:
            return new TeleportMonstre(levelMonstre, position);
            break;
        default:
            std::cout << "Problème FactoryMonstre" << std::endl;
            return nullptr;
            break;
    }
}
