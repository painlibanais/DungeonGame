//
// Created by Mohammed on 03/01/2018.
//

#ifndef DUNGEONGAME_POINT_H
#define DUNGEONGAME_POINT_H

#include <ostream>

class Point {
private:
    int x, y;

public:
    Point();

    Point(int x, int y);

    Point(Point &point);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    Point *totheUp();

    Point *totheLeft();

    Point *totheDown();

    Point *totheRight();

    friend std::ostream &operator<<(std::ostream &os, const Point &element);

    friend bool operator==(const Point &p1, const Point &p2);
};


#endif //DUNGEONGAME_POINT_H
