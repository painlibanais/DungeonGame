#include "Stage.h"
#include "Salle.h"
#include "VectorTemplate.h"


Stage::Stage(int id, int level)
        : id(id), level(level), sallesSize(0), rendering(new Map(120, 25)) {


    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 120; x++) {
            //  if (rendering->getElement(x, y) == nullptr)
            rendering->setElement(x, y, new Empty);
        }
    }

    parseSalle();
    parseCorridor();
    addStairs();
}

void Stage::reinitialisation() {
    for (int i = 0; i < sallesSize; i++) {
        salles[i]->reinitialisation();
        *rendering = *rendering + *salles[i];
    }

    for (auto &i : couloir) {
        rendering->setElement(i, new Pass);
    }

    if (level != 0) {
        rendering->setElement(downStairs, new DownStairs(0));
    }
    rendering->setElement(upStairs, new UpStairs(0));

    setEmpty();
}

int Stage::parseSalle() {
    std::string stageName = "stage" + std::to_string(id);
    std::ifstream file(stageName, std::ios::in);

    if (file) {
        int number;
        std::string type;

        file >> type >> number;
        if (type == "room") {
            for (int i = 0; i < number; i++) {
                int id, startX, startY, width, length;

                file >> id >> startX >> startY >> width >> length;
                salles.push_back(new Salle(id, level, width, length, new Point(startX, startY)));
                monstres.push_back(salles[sallesSize]->getMonsters());
                *rendering = *rendering + *salles[sallesSize];
                sallesSize++;
            }
            return 0;
        } else
            return -1;
    } else {
        std::cout << "Error open file " << stageName << std::endl;
        return -1;
    }
}


int Stage::parseCorridor() {
    std::string stageName = "corridor" + std::to_string(id);
    std::ifstream file(stageName, std::ios::in);

    if (file) {
        int number;
        std::string type;

        file >> type >> number;
        if (type == "corridor") {
            for (int i = 0; i < number; i++) {
                int y, startX, endX;

                file >> y >> startX >> endX;
                for (int x = startX; x < endX; x++) {
                    couloir.push_back(new Point(x, y));
                    rendering->setElement(x, y, new Pass);
                }
            }
            return 0;
        } else
            return -1;
    } else {
        std::cout << "Error open file " << stageName << std::endl;
        return -1;
    }
}

void Stage::setEmpty() {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 120; x++) {
            if (rendering->getElement(x, y) == nullptr)
                rendering->setElement(x, y, new Empty);
        }
    }
}


const std::vector<Salle *> &Stage::getSalles() const {
    return salles;
}


int Stage::getRandomSalle() const {
    return getRandom(0, salles.size());
}

int Stage::getSallesSize() const {
    return sallesSize;
}

Salle *Stage::getSalle(int i) {
    return salles[i];
}

int Stage::getId() const {
    return id;
}

void Stage::addStairs() {
    int salle1 = getRandomSalle();
    int salle2;
    do {
        salle2 = getRandomSalle();
    } while (salle2 == salle1);
    do {
        downStairs = getSalle(salle1)->getRandomPoint();
    } while (find(*getSalle(salle1)->getPositionMonsters(), downStairs) != -1);
    do {
        upStairs = getSalle(salle2)->getRandomPoint();
    } while (find(*getSalle(salle1)->getPositionMonsters(), upStairs) != -1);
    if (level != 0) {
        rendering->setElement(downStairs, new DownStairs(0));
    }
    rendering->setElement(upStairs, new UpStairs(0));
}

Point *Stage::getUpStairs() const {
    return upStairs;
}

void Stage::setUpStairs(Point *upStairs) {
    Stage::upStairs = upStairs;
}

Point *Stage::getDownStairs() const {
    return downStairs;
}

void Stage::setDownStairs(Point *downStairs) {
    Stage::downStairs = downStairs;
}


Map *Stage::getRendering() {
    return rendering;
}

void Stage::toPrint() {
    std::cout << *rendering << std::flush;
}

std::vector<std::vector<Monstre *> *> &Stage::getMonstres() {
    return monstres;
}
