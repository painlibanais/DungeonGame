//
// Created by Mohammed on 15/01/2018.
//

#ifndef DUNGEONGAME_POTION_H
#define DUNGEONGAME_POTION_H


#include "Item.h"

class Potion : public Item {
private:
    int vie, vision;
public:
    Potion();

    int getVie() const;

    void setVie(int vie);

    int getVision() const;

    void setVision(int vision);

    void toPrint() override;
};


#endif //DUNGEONGAME_POTION_H
