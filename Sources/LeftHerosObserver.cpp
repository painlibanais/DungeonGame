//
// Created by Mohammed on 13/01/2018.
//

#include "LeftHerosObserver.h"
#include "Heros.h"
#include "Salle.h"

LeftHerosObserver::LeftHerosObserver(Heros *heros, Stage *map)
        : Observer(heros, map) {
    heros->attach(this);
}


void LeftHerosObserver::update() {
    if (heros->getLastMove() == 'q') {
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
            if (herosPosition->getX() - j < 0) {
                break;
            } else {
                for (int i = -(heros->getVision()); i <= heros->getVision(); i++) {
                    if (herosPosition->getY() + i < 0) {}
                    else if (herosPosition->getY() + i > 24) {}
                    else
                        map->getRendering()->getElement(herosPosition->getX() - j,
                                                        herosPosition->getY() + i)->setVisible(true);

                }
            }
        }
    }
}
