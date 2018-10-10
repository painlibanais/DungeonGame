#ifndef DUNGEONGAME_HEROS_H
#define DUNGEONGAME_HEROS_H

#include <iostream>
#include <vector>
#include "Personnage.h"
#include "Observer.h"
#include "Item.h"


class Heros : public Personnage {
private:
    static Heros *instance;
    int exp;
    char lastMove;
    int salle;
    int vision;
    bool canMove;
    std::vector<Observer *> observerList;
    std::vector<Item *> sac;
public:
    static Heros *getInstance();

    Heros();

    void toString() override;

    void moveUp() override;

    void moveDown() override;

    void moveLeft() override;

    void moveRight() override;

    char getLastMove() const;

    void setLastMove(char lastMove);

    void attach(Observer *obs);

    void detach(Observer *obs);

    void notify();

    int getSalle() const;

    void setSalle(int salle);

    int getVision() const;

    void setVision(int vision);

    void setMovability(bool move);

    std::vector<Item *> &getSac();

    void use(int id);

    void erase(int id);

    void setSac(const std::vector<Item *> &sac);

    void addExp(int id);

    int getExp() const;

    bool attaque(Personnage *perso) override;

    void nextLevel();
};


#endif //DUNGEONGAME_HEROS_H
