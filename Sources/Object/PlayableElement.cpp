#include "PlayableElement.h"

PlayableElement::PlayableElement(char symbole, int id)
        : AbstractElement(symbole), id(id) {}

int PlayableElement::getId() const {
    return id;
}

void PlayableElement::setId(int id) {
    PlayableElement::id = id;
}
