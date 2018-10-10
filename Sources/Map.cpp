#include "Map.h"
#include "Object/Character.h"
#include "Stage.h"
#include "Heros.h"
#include "Salle.h"


Map::Map() : width(120), length(25) {
    stage.resize(length);
    for (int i = 0; i < length; i++) {
        stage[i].resize(width);
    }
}

Map::Map(int width, int length) : width(width), length(length) {
    stage.resize(length);
    for (int i = 0; i < length; i++) {
        stage[i].resize(width);
    }
}

void Map::setElement(int x, int y, AbstractElement *element) {
    if (stage[y][x] != nullptr)
        element->setVisible(stage[y][x]->isVisible());
    stage[y][x] = element;
}

void Map::setElement(Point *point, AbstractElement *element) {
    if (stage[point->getY()][point->getX()] != nullptr)
        element->setVisible(stage[point->getY()][point->getX()]->isVisible());
    stage[point->getY()][point->getX()] = element;
}

void Map::setElement(Point *point, char symbole) {
    PlayableElement *element = (PlayableElement *) getElement(point);
    stage[point->getY()][point->getX()] = new Character(symbole, element->getId());
}

AbstractElement *Map::getElement(int x, int y) {
    return stage[y][x];
}

AbstractElement *Map::getElement(Point *point) {
    if (point == nullptr)
        return nullptr;
    else
        return stage[point->getY()][point->getX()];
}

int Map::getLength() const {
    return length;
}

int Map::getWidth() const {
    return width;
}

bool Map::isUp(Point *x) {
    return getElement(x)->getSymbole() == '?';
}

bool Map::isDown(Point *x) {
    return getElement(x)->getSymbole() == '!';
}

bool Map::isWall(Point *x) {
    return getElement(x)->getSymbole() == '|' || getElement(x)->getSymbole() == '-';
}

bool Map::isEmpty(Point *x) {
    return getElement(x)->getSymbole() == ' ';
}

bool Map::isPlat(Point *x) {
    return getElement(x)->getSymbole() == '.';
}

bool Map::isPass(Point *x) {
    return getElement(x)->getSymbole() == '#';
}

bool Map::isItem(Point *x) {
    return getElement(x)->getSymbole() == '0';
}

int Map::isPlayable(Point *x) {
    if (isPlat(x) || isPass(x))
        return 0;
    else if (isEmpty(x) || isWall(x))
        return -1;
    else if (isUp(x))
        return 2;
    else if (isDown(x))
        return 3;
    else if (isItem(x))
        return 4;
    else
        return 1;
}

std::ostream &operator<<(std::ostream &out, Map &map) {
    for (int y = 0; y < map.getLength(); y++) {
        for (int x = 0; x < map.getWidth(); x++) {
            out << *map.getElement(x, y) << std::flush;
        }
        out << std::endl;
    }
    return out;
}

Map operator+(Map &map1, Map &map2) {
    Map map(120, 25);

    for (int y = 0; y < map1.getLength(); y++) {
        for (int x = 0; x < map1.getWidth(); x++) {
            if (map1.getElement(x, y) != nullptr)
                map.setElement(x, y, map1.getElement(x, y));
        }
    }

    for (int y = 0; y < map2.getLength(); y++) {
        for (int x = 0; x < map2.getWidth(); x++) {
            if (map2.getElement(x, y) != nullptr)
                map.setElement(x, y, map2.getElement(x, y));
        }
    }
    return map;
}

Map operator+(Map map1, Heros &heros) {
    PlayableElement *element = (PlayableElement *) map1.getElement(heros.getPosition());
    AbstractElement *h = new Character(heros.getSymbole(), element->getId());
    h->setVisible(true);

    map1.setElement(heros.getPosition(), h);
    return map1;
}


Map operator+(Map map, Salle &salle) {
    Map rendu = map + *salle.getRendering();
    return rendu;
}

