//
// Created by Mohammed on 07/01/2018.
//

#include <zconf.h>
#include "Controleur.h"
#include "Heros.h"
#include "Salle.h"
#include "VectorTemplate.h"
#include "FactoryItem.h"
#include "Object/Reward.h"

Item *findItem(std::vector<Item *> *vec, Point *pos);


Controleur::Controleur(Heros *heros)
        : heros(heros), screen(new Map), currentStage(0), numberStage(0) {

    init(Controleur::LAUNCH);
}

void Controleur::init(int flag) {
    switch (flag) {
        case Controleur::LAUNCH:
            addStage();
            monsterRendering();
            initHeros(flag);
            affiche();
            break;
        case Controleur::UP:
            currentStage++;
            addStage();
            itemRendering();
            monsterRendering();
            initHeros(Controleur::LAUNCH);
            affiche();
            break;
        case Controleur::DOWN:
            currentStage--;
            addStage();
            itemRendering();
            monsterRendering();
            initHeros(Controleur::DOWN);
            affiche();
            break;
    }
}


void Controleur::createStage() {
    int stageRandom = getRandom(1, 3);
    stage.push_back(new Stage(stageRandom, numberStage));
    numberStage++;
}

void Controleur::addStage() {
    Stage *current;
    try {
        current = stage.at(currentStage);
    } catch (...) {
        createStage();
        current = stage.at(currentStage);
    }

    upObs = new UpHerosObserver(heros, stage[currentStage]);
    leftObs = new LeftHerosObserver(heros, stage[currentStage]);
    downObs = new DownHerosObserver(heros, stage[currentStage]);
    rightObs = new RightHerosObserver(heros, stage[currentStage]);


    *screen = *current->getRendering();
}

void Controleur::initHeros(int flag) {
    Stage *current = stage.at(currentStage);
    Point *pos;
    PlayableElement *element;

    switch (flag) {
        case Controleur::LAUNCH:
            pos = current->getDownStairs();
            break;
        case Controleur::DOWN:
            pos = current->getUpStairs();
            break;
        default:
            break;
    }

    element = (PlayableElement *) screen->getElement(pos);
    element->setVisible(true);
    heros->setPosition(pos);
    heros->setSalle(element->getId());
    *screen = *screen + *heros;
    heros->notify();
}

void Controleur::addHeros() {
    PlayableElement *element = (PlayableElement *) screen->getElement(heros->getPosition());
    heros->setSalle(element->getId());
    *screen = *screen + *heros;
}

void Controleur::affiche() {
    std::cout << *screen << std::endl;
    std::cout << "VIE : " << heros->getVie() << " FOR : " << heros->getForce() << " DEF : " << heros->getDefense()
              << " VISION : " << heros->getVision() << " EXP : " << heros->getExp() << "/" << heros->getLevel() * 20
              << " NIV : " << heros->getLevel()
              << std::endl;
}

void Controleur::playTurn(char direction) {
    Point *di = heros->getNextPoint(direction);
    heros->setMovability(false);
    heros->move(direction);

/*    for (int i = 0; i < items.size(); ++i) {
        std::cout << items.at(i) << std::endl;
    }
*/
    if (di != nullptr) {
        int value = screen->isPlayable(di);
        switch (value) {
            case -1:
                break;
            case 0:
                heros->setMovability(true);
                heros->move(direction);
                break;
            case 1:
                heros->setMovability(false);
                heros->move(direction);
//                PlayableElement *test = (PlayableElement *) screen->getElement(di);
                doInteraction(heros, di);
                break;
            case 2:
                init(Controleur::UP);
                return;
                break;
            case 3:
                init(Controleur::DOWN);
                return;
                break;
            case 4:
                ramasser(di);
                break;
        }
    }
    heros->notify();
    addStage();
    addHeros();
    itemRendering();
    updateMonstres();
    usleep(10000);

    stage.at(currentStage)->reinitialisation();
    affiche();
    if (heros->getVie() <= 0) {
        std::cout << "GAME OVER" << std::endl;
        exit(0);
    }
}

void Controleur::updateMonstres() {
    std::vector<std::vector<Monstre *> *> monstre = stage[currentStage]->getMonstres();
    for (std::vector<Monstre *> *&i : monstre) {
        for (int j = 0; j < i->size(); ++j) {
            Monstre *m = i->at(j);
            Point *want = m->doRandomMove(heros->getPosition());
            //std::cout << *want << std::endl;
            if (want != nullptr) {
                int rep = screen->isPlayable(want);
                //      std::cout << rep << std::endl;

                if (rep == 0) {
                    stage[currentStage]->getSalle(m->getSalle())->updatePositionMonsters(j, want);
                    stage[currentStage]->getSalle(m->getSalle())->getMonsters()->at(j)->move();
                } else if (rep == 1) {
                    if (*want == *heros->getPosition())
                        doInteraction(m, heros);
                }
            }
//            std::cout << *m->getPosition() << std::endl;
        }
        addStage();
        addHeros();
        itemRendering();
        monsterRendering();
    }
}


Salle *Controleur::getCurrentSalle() {
    if (heros->getSalle() < 0)
        return nullptr;
    else
        return stage[currentStage]->getSalle(heros->getSalle());
}

char Controleur::getNextStep(Personnage *perso, char direction) {
    return screen->getElement(perso->getNextPoint(direction))->getSymbole();
}

void Controleur::doInteraction(Personnage *a, Heros *b) {
    a->attaque(b);
//    std::cout << heros->getVie() << std::endl;
}

void Controleur::ramasser(Point *pos) {
    Item *i = findItem(&items, pos);
    heros->getSac().push_back(findItem(&items, pos));
    remove(&items, i->getId());
//    std::cout << items.size() << std::endl;
}

void Controleur::doInteraction(Heros *a, Point *b) {
    PlayableElement *element = (PlayableElement *) screen->getElement(b);
    std::vector<Point *> *listeMonstre = stage[currentStage]->getSalle(element->getId())->getPositionMonsters();
    int id = find(*listeMonstre, b);
    if (id != -1) {
        Monstre *monstre = stage[currentStage]->getSalle(element->getId())->getMonsters()->at(id);
        if (a->attaque(monstre)) {
            items.push_back(FactoryItem::createItem(currentStage, new Point(*b)));
//            std::cout << listeMonstre->size() << std::endl;
            remove(listeMonstre, id);
            remove(stage[currentStage]->getSalle(element->getId())->getMonsters(), id);
//            std::cout << listeMonstre->size() << std::endl;
        }
    }
}

void Controleur::monsterRendering() {
    std::vector<std::vector<Monstre *> *> monstres = stage[currentStage]->getMonstres();
    for (std::vector<Monstre *> *&monstre : monstres) {
        for (Monstre *&j : *monstre) {
            screen->setElement(j->getPosition(),
                               new Character(j->getSymbole(),
                                             j->getSalle()));
        }
    }
}

void Controleur::itemRendering() {
    for (Item *&item : items) {
        screen->setElement(item->getPosition(), new Reward());
    }
}

void Controleur::getCommande(char val) {
    switch (val) {
        case 'm':
            menu();
            break;
        case 'z':
        case 'q':
        case 's':
        case 'd':
            playTurn(val);
            break;
    }
}

void Controleur::menu() {
    std::string rep;
    if (heros->getSac().size() != 0) {
        for (int i = 0; i < heros->getSac().size(); i++) {
            std::cout << i << " " << std::flush;
            heros->getSac().at(i)->toPrint();
        }
        std::cout << "Select item :" << std::endl;
        rep = getMove();

        if (stoi(rep) >= 0 && stoi(rep) < heros->getSac().size()) {
            int val = stoi(rep);
            std::cout << "Item num" << val << " " << std::endl;
            std::cout << "for use : 0" << std::endl;
            std::cout << "for erase : 1" << std::endl;
            rep = getMove();
            if (stoi(rep) == 0) {
                std::cout << "use" << std::endl;
                heros->use(val);
            } else if (stoi(rep) == 1) {
                std::cout << "erase" << std::endl;
                heros->erase(val);
            }
        }
    } else
        std::cout << "sac vide" << std::endl;
    affiche();
}


Item *findItem(std::vector<Item *> *vec, Point *pos) {
    Item *it = nullptr;
    for (int i = 0; i < vec->size(); i++) {
        if (*(vec->at(i)->getPosition()) == *pos) {
            vec->at(i)->setId(i);
            it = vec->at(i);
            break;
        }
    }
    return it;
}