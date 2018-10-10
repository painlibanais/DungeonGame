#include <iostream>
#include "Salle.h"
#include "Heros.h"
#include "Controleur.h"

using namespace std;

int main() {
    srand(time(NULL));

    Heros *heros = Heros::getInstance();

    Controleur ct(heros);
    while (1) {
        ct.getCommande(getMove());
    }

    return 0;

}
