//
// Created by Mohammed on 15/01/2018.
//

#ifndef DUNGEONGAME_FACTORYITEM_H
#define DUNGEONGAME_FACTORYITEM_H


#include "Item.h"

class FactoryItem {
public:
    static Item *createItem(int level, Point *pos);
};


#endif //DUNGEONGAME_FACTORYITEM_H
