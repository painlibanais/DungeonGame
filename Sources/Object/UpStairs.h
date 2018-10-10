#ifndef DUNGEONGAME_UPSTAIRS_H
#define DUNGEONGAME_UPSTAIRS_H


#include "PlayableElement.h"

class UpStairs : public PlayableElement {
public:
    UpStairs(int id);

    void toString() override;
};


#endif //DUNGEONGAME_UPSTAIRS_H
