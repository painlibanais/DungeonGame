//
// Created by Mohammed on 14/01/2018.
//

#include "Distance.h"

int Distance(Point *p1, Point *p2) {
    return std::abs(p2->getX() - p1->getX()) + std::abs(p2->getY() - p1->getY());
};
