//
// Created by Mohammed on 07/01/2018.
//

#ifndef DUNGEONGAME_CONTROLEUR_H
#define DUNGEONGAME_CONTROLEUR_H

#include <vector>
#include "UpHerosObserver.h"
#include "LeftHerosObserver.h"
#include "DownHerosObserver.h"
#include "RightHerosObserver.h"
#include "Object/AbstractElement.h"
#include "Personnage.h"

class Map;

class Heros;

class Stage;

class Monstre;

class Controleur {
private:
    int currentStage, numberStage;
    Map *screen;
    Heros *heros;
    std::vector<Stage *> stage;
    std::vector<Monstre *> monstre;
    std::vector<Item *> items;
    Observer *upObs, *leftObs, *downObs, *rightObs;

public:
    static const int UP = 1;

    static const int DOWN = 2;

    static const int LAUNCH = 0;

    explicit Controleur(Heros *heros);

    void playTurn(char direction);

    void affiche();

    void addStage();

    void createStage();

    void addHeros();

    void init(int flag);

    Salle *getCurrentSalle();

    char getNextStep(Personnage *perso, char direction);

    void doInteraction(Heros *a, Point *b);

    void doInteraction(Personnage *a, Heros *b);

    void updateMonstres();

    void monsterRendering();

    void initHeros(int flag);

    void itemRendering();

    void ramasser(Point *pos);

    void getCommande(char val);

    void menu();
};


#endif //DUNGEONGAME_CONTROLEUR_H
