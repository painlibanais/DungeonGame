#ifndef DUNGEONGAME_LEVEL_H
#define DUNGEONGAME_LEVEL_H

#include <fstream>
#include <vector>
#include "Object/AbstractElement.h"
#include "Object/Empty.h"
#include "Object/Pass.h"
#include "Object/DownStairs.h"
#include "Object/UpStairs.h"
#include "Map.h"
#include "Item.h"

class Point;
class Salle;
class Monstre;

class Stage {
private:
    int id, level, sallesSize;
    int herosSalle;
    Point *upStairs, *downStairs;
    Map *rendering;
    std::vector<Salle *> salles;
    std::vector<Point *> couloir;
    std::vector<std::vector<Monstre *> *> monstres;
public:
    explicit Stage(int id, int level);

    int getId() const;

    int parseSalle();

    int parseCorridor();

    const std::vector<Salle *> &getSalles() const;

    int getRandomSalle() const;

    int getSallesSize() const;

    Salle *getSalle(int i);

    Point *getUpStairs() const;

    void setUpStairs(Point *upStairs);

    Point *getDownStairs() const;

    void setDownStairs(Point *downStairs);

    void addStairs();

    void reinitialisation();

    Map *getRendering();

    void setEmpty();

    void toPrint();

    std::vector<std::vector<Monstre *> *> &getMonstres();

};


#endif //DUNGEONGAME_LEVEL_H
