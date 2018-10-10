#include "Point.h"

Point::Point() {}


Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(Point &point) {
    setX(point.getX());
    setY(point.getY());
}

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

Point *Point::totheUp() {
    return new Point(getX(), getY() - 1);
}

Point *Point::totheLeft() {
    return new Point(getX() - 1, getY());
}

Point *Point::totheDown() {
    return new Point(getX(), getY() + 1);
}

Point *Point::totheRight() {
    return new Point(getX() + 1, getY());
}

std::ostream &operator<<(std::ostream &os, const Point &element) {
    os << "X : " << element.getX() << " Y : " << element.getY() << std::endl;
    return os;
}

bool operator==(const Point &p1, const Point &p2) {
    return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}
