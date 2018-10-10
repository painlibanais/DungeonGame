#ifndef DUNGEONGAME_TELEPORTMONSTRE_H
#define DUNGEONGAME_TELEPORTMONSTRE_H


#include "Monstre.h"

class TeleportMonstre : public Monstre {
private:
    Point *toGo;
public:
    explicit TeleportMonstre(int level, Point *position);

    void toString() override;

    void startIntelligence(bool val) override;

    Point *doRandomMove(Point *heros) override;

    void move() override;
};


#endif //DUNGEONGAME_TELEPORTMONSTRE_H
