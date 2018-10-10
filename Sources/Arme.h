//
// Created by Mohammed on 15/01/2018.
//

#ifndef DUNGEONGAME_ARME_H
#define DUNGEONGAME_ARME_H


#include "Item.h"

class Arme : public Item {
private:
    int force;
public:
    Arme(int force);

    int getForce() const;

    void setForce(int force);

    friend std::ostream &operator<<(std::ostream &os, const Arme &element);

    void toPrint() override;


};


#endif //DUNGEONGAME_ARME_H
