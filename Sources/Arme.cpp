//
// Created by Mohammed on 15/01/2018.
//

#include <iostream>
#include "Arme.h"

Arme::Arme(int force) : Item('w'), force(force) {}

int Arme::getForce() const {
    return force;
}

void Arme::setForce(int force) {
    Arme::force = force;
}

void Arme::toPrint() {
    std::cout << "Weapon " << "F +" << getForce() << std::endl;

}
