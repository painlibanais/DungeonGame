#include "Salle.h"
#include "Map.h"
#include "VectorTemplate.h"


Salle::Salle(int id, int level, int width, int length, Point *start)
        : id(id), level(level), width(width), length(length), start(start) {
    setMonsters();
    doRendering();
}

void Salle::reinitialisation() {
    doRendering();
}

int Salle::getId() const {
    return id;
}

int Salle::getWidth() const {
    return width;
}

int Salle::getLength() const {
    return length;
}

Point *Salle::getStart() const {
    return start;
}

void Salle::changeIntelligence(bool val) {
    for (int i = 0; i < monsters.size(); ++i) {
        monsters[i]->startIntelligence(val);
    }
}

Point *Salle::getRandomPoint() {
    int xStart = start->getX();
    int yStart = start->getY();

    return (new Point(getRandom(xStart + 1, xStart + width - 1), getRandom(yStart + 1, yStart + length - 1)));
}

std::vector<Monstre *> *Salle::getMonsters() {
    return &monsters;
}

void Salle::addMonsters(Point *position) {
    Monstre *toAdd = FactoryMonstre::createMonstre(level, position);
    toAdd->setSalle(id);
    monsters.push_back(toAdd);
}

void Salle::setMonsters() {
    int nbMonstre = getRandom(2, 6);

    for (int i = 0; i < nbMonstre; i++) {
        Point *position;

        do {
            position = getRandomPoint();
        } while (find(positionMonsters, position) != -1);
        addPositionMonsters(position);
        addMonsters(position);

    }
}

std::vector<Point *> *Salle::getPositionMonsters() {
    return &positionMonsters;
}

void Salle::addPositionMonsters(Point *position) {
    positionMonsters.push_back(position);
}

void Salle::updatePositionMonsters(int id, Point *position) {
    positionMonsters[id] = position;
}

int Salle::getLevel() const {
    return level;
}

void Salle::doRendering() {
    int startX = start->getX();
    int startY = start->getY();

    int limitX = start->getX() + width;
    int limitY = start->getY() + length;

    rendering = new Map(120, 25);
    for (int y = startY; y < limitY; y++) {
        for (int x = startX; x < limitX; x++) {
            if (y == startY || y == limitY - 1)
                rendering->setElement(x, y, new WallH);
            else if (x == startX || x == limitX - 1)
                rendering->setElement(x, y, new WallV);
            else
                rendering->setElement(x, y, new Plat(id));
        }
    }
}


std::ostream &operator<<(std::ostream &os, Salle &salle) {
    os << "Salle " << salle.getId() << ", niveau " << salle.getLevel() << std::endl;
    os << "   " << "width " << salle.getWidth() << ", length " << salle.getLength() << std::endl;
    os << "   " << "start " << *salle.getStart();
    os << "   " << "monstres :" << std::endl;
    for (int i = 0; i < salle.getPositionMonsters()->size(); ++i) {
        os << "   " << "- " << *salle.getPositionMonsters()->at(i) << std::endl;
    }
    return os;
}

Map *Salle::getRendering() const {
    return rendering;
}
