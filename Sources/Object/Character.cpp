#include "Character.h"

Character::Character(char symbole, int id)
        : PlayableElement(symbole, id) {}

void Character::toString() {
    std::cout << "Type : CHARACTER" << std::endl;
}
