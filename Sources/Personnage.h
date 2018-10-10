#ifndef DUNGEONGAME_PERSONNAGE_H
#define DUNGEONGAME_PERSONNAGE_H

#include "Point.h"

class Point;

class Personnage {
protected:
    int vie, level;
    double force, defense;
    char symbole;
    Point *position;

public:
    Personnage(char symbole, int level, Point *position);

    int getVie() const;

    void setVie(int vie);

    char getSymbole() const;

    void setSymbole(char symbole);

    Point *getPosition() const;

    void setPosition(Point *position);

    virtual void toString() = 0;

    virtual void moveUp();

    virtual void moveLeft();

    virtual void moveDown();

    virtual void moveRight();

    Point *getNextPoint(char di);

    int getLevel() const;

    void setLevel(int level);

    double getForce() const;

    void setForce(double force);

    double getDefense() const;

    void setDefense(double defense);

    virtual bool attaque(Personnage *perso);

    bool seDefend(int degats);

    void move(char direction);
};


#endif //DUNGEONGAME_PERSONNAGE_H
