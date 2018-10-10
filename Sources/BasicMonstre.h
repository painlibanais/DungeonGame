#ifndef DUNGEONGAME_BASICMONSTRE_H
#define DUNGEONGAME_BASICMONSTRE_H


#include "Monstre.h"

class BasicMonstre : public Monstre {
public:
    explicit BasicMonstre(int level, Point* position);

    void toString() override;

    void startIntelligence(bool val) override;
};


#endif //DUNGEONGAME_BASICMONSTRE_H
