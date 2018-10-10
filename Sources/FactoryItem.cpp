//
// Created by Mohammed on 15/01/2018.
//

#include <iostream>
#include "FactoryItem.h"
#include "getRandom.h"
#include "Potion.h"
#include "Arme.h"
#include "Armure.h"

Item *FactoryItem::createItem(int level, Point *pos) {
    int levelItem = getRandom(level, level + 3);
    if (levelItem == 0)
        levelItem = 1;
    Item *i;

    int itemType = getRandom(0, 4);
    switch (itemType) {
        case 0:
            i = new Potion();
            ((Potion *) i)->setVie(levelItem * 50);
            ((Potion *) i)->setVision(0);
            ((Potion *) i)->setPosition(pos);
            return i;
            break;
        case 1:
            i = new Potion();
            ((Potion *) i)->setVie(levelItem * (-50));
            ((Potion *) i)->setVision(4);
            ((Potion *) i)->setPosition(pos);
            return i;
            break;
        case 2:
            i = new Arme(levelItem * 1);
            ((Arme *) i)->setPosition(pos);
            return i;
            break;
        case 3:
            i = new Armure(levelItem * 1);
            ((Armure *) i)->setPosition(pos);
            return i;
            break;
        default:
            std::cout << "Problème FactoryMonstre" << std::endl;
            return nullptr;
            break;
    }
}
