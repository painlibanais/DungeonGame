#include "AbstractElement.h"

AbstractElement::AbstractElement(char symbole)
        : symbole(symbole), visible(false) {}

AbstractElement::AbstractElement()
        : symbole(' '), visible(false) {}

char AbstractElement::getSymbole() const {
    return symbole;
}

void AbstractElement::setSymbole(char symbole) {
    AbstractElement::symbole = symbole;
}

std::ostream &operator<<(std::ostream &os, const AbstractElement &element) {
    if (element.isVisible())
        os << element.symbole << std::flush;
    else
        os << " " << std::flush;
    return os;
}

bool AbstractElement::isVisible() const {
    return visible;
}

void AbstractElement::setVisible(bool visible) {
    AbstractElement::visible = visible;
}
