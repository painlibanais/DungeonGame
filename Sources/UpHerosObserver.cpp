#include "UpHerosObserver.h"
#include "Heros.h"
#include "Salle.h"


UpHerosObserver::UpHerosObserver(Heros *heros, Stage *map)
        : Observer(heros, map) {
    heros->attach(this);
}

void UpHerosObserver::update() {
    if (heros->getLastMove() == 'z') {
        Point *herosPosition = heros->getPosition();

        int heroSalle;

        try {
            heroSalle = heros->getSalle();

            for (int i = 0; i < map->getSalles().size(); ++i) {
                map->getSalle(i)->changeIntelligence(false);
            }

            if (heroSalle != -1)
                map->getSalle(heroSalle)->changeIntelligence(true);
        } catch (...) {
            std::cout << "Fail" << std::endl;
        }

        for (int j = 0; j <= heros->getVision(); j++) {
            if (herosPosition->getY() - j < 0)
                break;
            else {
                for (int i = -heros->getVision(); i <= heros->getVision(); i++) {
                    if (herosPosition->getX() + i < 0)
                        break;
                    else if (herosPosition->getX() + i > 124)
                        break;
                    else
                        map->getRendering()->getElement(herosPosition->getX() + i,
                                                        herosPosition->getY() - j)->setVisible(true);
                }
            }
        }
    }
}
