#ifndef DUNGEONGAME_PLAT_H
#define DUNGEONGAME_PLAT_H


#include "PlayableElement.h"

class Plat : public PlayableElement{
public:
    Plat(int id);

    void toString() override;

    int getId() const;

    void setId(int id);
};


#endif //DUNGEONGAME_PLAT_H
