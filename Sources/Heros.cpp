#include "Heros.h"
#include "Potion.h"
#include "Arme.h"
#include "VectorTemplate.h"
#include "Armure.h"


Heros::Heros()
        : Personnage('>', 5, new Point(0, 0)), salle(-1), lastMove('d'), vision(2), canMove(false), exp(0) {
    vie = 200;
    force = level * 1;
    defense = level * 1;
}

Heros *Heros::instance = nullptr;

Heros *Heros::getInstance() {
    if (instance == nullptr)
        instance = new Heros();
    return instance;
}

void Heros::moveUp() {
    setSymbole('^');
    if (canMove)
        Personnage::moveUp();
    lastMove = 'z';
    notify();
}

void Heros::moveDown() {
    setSymbole('v');
    if (canMove)
        Personnage::moveDown();
    lastMove = 's';
    notify();
}

void Heros::moveLeft() {
    setSymbole('<');
    if (canMove)
        Personnage::moveLeft();
    lastMove = 'q';
    notify();
}

void Heros::moveRight() {
    setSymbole('>');
    if (canMove)
        Personnage::moveRight();
    lastMove = 'd';
    notify();
}

void Heros::toString() {
    std::cout << "Type : HERO" << std::endl;
}

void Heros::attach(Observer *obs) {
    observerList.push_back(obs);
}

void Heros::detach(Observer *obs) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), obs), observerList.end());
}

void Heros::notify() {
    for (int i = 0; i < observerList.size(); ++i) {
        observerList[i]->update();
    }
}

int Heros::getSalle() const {
    return salle;
}

void Heros::setSalle(int salle) {
    Heros::salle = salle;
}

char Heros::getLastMove() const {
    return lastMove;
}

void Heros::setLastMove(char lastMove) {
    Heros::lastMove = lastMove;
}

int Heros::getVision() const {
    return vision;
}

void Heros::setVision(int vision) {
    Heros::vision = vision;
}

void Heros::setMovability(bool move) {
    Heros::canMove = move;
}

std::vector<Item *> &Heros::getSac() {
    return sac;
}

void Heros::setSac(const std::vector<Item *> &sac) {
    Heros::sac = sac;
}

void Heros::use(int id) {
    Item *i = sac.at(id);
    switch (i->getType()) {
        case 'p':
            setVie(getVie() + ((Potion *) i)->getVie());
            setVision(getVision() + ((Potion *) i)->getVision());
            break;
        case 'w':
            setForce(((Arme *) i)->getForce() + level);
            break;
        case 'a':
            setDefense(((Armure *) i)->getDefense() + level);
            break;
    }
    erase(id);
}

void Heros::erase(int id) {
    remove(&sac, id);
}

void Heros::addExp(int id) {
    exp = exp + (id * 20);
    nextLevel();
}

void Heros::nextLevel() {
    if (exp >= (level * 20)) {
        level++;
        vie = 200 + (level * 40);
        exp = 0;
    }
}

int Heros::getExp() const {
    return exp;
}

bool Heros::attaque(Personnage *perso) {
    if (perso->seDefend(force * 10)) {
        addExp(perso->getLevel());
        return true;
    }
    return false;
}
