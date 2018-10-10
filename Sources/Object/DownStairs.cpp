#include "DownStairs.h"

DownStairs::DownStairs(int id)
        : PlayableElement('!', id) {}

void DownStairs::toString() {
    std::cout << "Type : DOWNSTAIRS" << std::endl;
}
