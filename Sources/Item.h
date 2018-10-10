//
// Created by Mohammed on 15/01/2018.
//

#ifndef DUNGEONGAME_ITEM_H
#define DUNGEONGAME_ITEM_H


#include "Point.h"

class Item {
protected:
    char type;
    Point *position;
    int id;
public:
    Item(char type);

    char getType() const;

    void setType(char type);

    Point *getPosition();

    void setPosition(Point *position);

    int getId() const;

    void setId(int id);

    virtual void toPrint() = 0;
};


#endif //DUNGEONGAME_ITEM_H
