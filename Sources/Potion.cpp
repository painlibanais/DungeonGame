//
// Created by Mohammed on 15/01/2018.
//

#include <iostream>
#include "Potion.h"

Potion::Potion() : Item('p') {}

int Potion::getVie() const {
    return vie;
}

void Potion::setVie(int vie) {
    Potion::vie = vie;
}

int Potion::getVision() const {
    return vision;
}

void Potion::setVision(int vision) {
    Potion::vision = vision;
}

void Potion::toPrint() {
    std::cout << "Potion " << "VIE +" << getVie() << " VISION +" << getVision() << std::endl;
}
