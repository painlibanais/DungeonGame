#ifndef DUNGEONGAME_INTELLIGENTMONSTRE_H
#define DUNGEONGAME_INTELLIGENTMONSTRE_H


#include "Monstre.h"


class IntelligentMonstre : public Monstre {
public:
    explicit IntelligentMonstre(int level, Point *position);

    void toString() override;

    void startIntelligence(bool val) override;

    Point *doRandomMove(Point *heros) override;
};


#endif //DUNGEONGAME_INTELLIGENTMONSTRE_H
