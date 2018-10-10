#ifndef DUNGEONGAME_SALLE_H
#define DUNGEONGAME_SALLE_H

#include <vector>
#include "getRandom.h"
#include "FactoryMonstre.h"
#include "Object/WallH.h"
#include "Object/WallV.h"
#include "Object/Plat.h"
#include "Object/Character.h"

class Map;

class Salle {
private:
    int id, level, width, length;
    Map *rendering;
    Point *start;
    std::vector<Monstre *> monsters;
    std::vector<Point *> positionMonsters;

public:
    Salle(int id, int level, int width, int length, Point *start);

    int getId() const;

    int getLevel() const;

    int getWidth() const;

    int getLength() const;

    Point *getStart() const;

    Point *getRandomPoint();

    std::vector<Monstre *> *getMonsters();

    void setMonsters();

    void addMonsters(Point *position);

    std::vector<Point *> *getPositionMonsters();

    void addPositionMonsters(Point *position);

    void doRendering();

    Map *getRendering() const;

    friend std::ostream &operator<<(std::ostream &os, Salle &salle);

    void reinitialisation();

    void changeIntelligence(bool);

    void updatePositionMonsters(int id, Point *position);
};


#endif //DUNGEONGAME_SALLE_H
