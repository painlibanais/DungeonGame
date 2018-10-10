//
// Created by Mohammed on 15/01/2018.
//

#ifndef DUNGEONGAME_ARMURE_H
#define DUNGEONGAME_ARMURE_H


#include "Item.h"

class Armure : public Item {
private:
    int defense;
public:
    Armure(int def);

    int getDefense() const;

    void setDefense(int defense);

    friend std::ostream &operator<<(std::ostream &os, const Armure &element);

    void toPrint() override;

};


#endif //DUNGEONGAME_ARMURE_H
