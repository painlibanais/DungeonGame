#include "Personnage.h"


Personnage::Personnage(char symbole, int level, Point *position)
        : symbole(symbole), level(level), position(position) {
    vie = 200;
}

int Personnage::getVie() const {
    return vie;
}

void Personnage::setVie(int vie) {
    Personnage::vie = vie;
}

char Personnage::getSymbole() const {
    return symbole;
}

void Personnage::setSymbole(char symbole) {
    Personnage::symbole = symbole;
}

Point *Personnage::getPosition() const {
    return position;
}

void Personnage::setPosition(Point *position) {
    Personnage::position = position;
}

void Personnage::moveUp() {
    position = position->totheUp();
}

void Personnage::moveDown() {
    position = position->totheDown();
}

void Personnage::moveLeft() {
    position = position->totheLeft();
}

void Personnage::moveRight() {
    position = position->totheRight();
}

void Personnage::move(char direction) {
    switch (direction) {
        case 'z':
            moveUp();
            break;
        case 'q':
            moveLeft();
            break;
        case 's':
            moveDown();
            break;
        case 'd':
            moveRight();
            break;
    }
}

int Personnage::getLevel() const {
    return level;
}

void Personnage::setLevel(int level) {
    Personnage::level = level;
}

double Personnage::getForce() const {
    return force;
}

void Personnage::setForce(double force) {
    Personnage::force = force;
}

double Personnage::getDefense() const {
    return defense;
}

void Personnage::setDefense(double defense) {
    Personnage::defense = defense;
}

bool Personnage::attaque(Personnage *perso) {
    return perso->seDefend(force * 10);

}

bool Personnage::seDefend(int degats) {
    vie = vie - (degats / defense);
    return vie <= 0;
}

Point *Personnage::getNextPoint(char di) {
    Point *point;
    switch (di) {
        case 'z':
            point = position->totheUp();
            break;
        case 'q':
            point = position->totheLeft();
            break;
        case 's':
            point = position->totheDown();
            break;
        case 'd':
            point = position->totheRight();
            break;
    }
    if (point->getX() < 0 || point->getY() < 0 || point->getX() > 119 || point->getY() > 24)
        return nullptr;
    else
        return point;
}

