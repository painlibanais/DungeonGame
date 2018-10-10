#ifndef DUNGEONGAME_EMPTY_H
#define DUNGEONGAME_EMPTY_H


#include "NotPlayableElement.h"

class Empty : public NotPlayableElement {
public:
    Empty();

    void toString() override;
};


#endif //DUNGEONGAME_EMPTY_H
