#ifndef DUNGEONGAME_DOWNSTAIRS_H
#define DUNGEONGAME_DOWNSTAIRS_H


#include "PlayableElement.h"

class DownStairs : public PlayableElement {
public:
    DownStairs(int id);

    void toString() override;
};


#endif //DUNGEONGAME_DOWNSTAIRS_H
