//
// Created by Mohammed on 15/01/2018.
//

#include <iostream>
#include "Armure.h"

Armure::Armure(int def) : Item('a'), defense(def) {}

int Armure::getDefense() const {
    return defense;
}

void Armure::setDefense(int defense) {
    Armure::defense = defense;
}

void Armure::toPrint() {
    std::cout << "Armor " << "D +" << getDefense() << std::endl;
}
