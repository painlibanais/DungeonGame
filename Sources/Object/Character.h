#ifndef DUNGEONGAME_CHARACTER_H
#define DUNGEONGAME_CHARACTER_H


#include "PlayableElement.h"

class Character : public PlayableElement {
public:
    explicit Character(char symbole, int id);

    void toString() override;
};


#endif //DUNGEONGAME_CHARACTER_H
