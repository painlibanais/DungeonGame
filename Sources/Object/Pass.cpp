#include "Pass.h"

Pass::Pass()
        : PlayableElement('#', -1)  {}

void Pass::toString() {
    std::cout << "Type : PASS" << std::endl;
}
