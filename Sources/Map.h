#ifndef DUNGEONGAME_MAP_H
#define DUNGEONGAME_MAP_H

#include <vector>
#include "Object/AbstractElement.h"

class Heros;
class Point;
class Stage;
class Salle;

class Map {
private:
    std::vector<std::vector<AbstractElement *>> stage;
    int length, width;

public:
    Map();

    Map(int width, int length);

    void setElement(int x, int y, AbstractElement *element);

    int getLength() const;

    int getWidth() const;

    AbstractElement *getElement(int x, int y);

    AbstractElement *getElement(Point *point);

    friend std::ostream &operator<<(std::ostream &out, Map &map);

    void setElement(Point *point, AbstractElement *element);

    void setElement(Point *point, char symbole);

    bool isWall(Point *x);

    bool isEmpty(Point *x);

    bool isPlat(Point *x);

    int isPlayable(Point *x);

    friend Map operator+(Map &map1, Map &map2);

    friend Map operator+(Map map, Heros &heros);

    friend Map operator+(Map map, Salle &salle);

    bool isPass(Point *x);

    bool isUp(Point *x);

    bool isDown(Point *x);

    bool isItem(Point *x);
};


#endif //DUNGEONGAME_MAP_H
