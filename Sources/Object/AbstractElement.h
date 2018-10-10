#ifndef DUNGEONGAME_ELEMENT_H
#define DUNGEONGAME_ELEMENT_H


#include <iostream>

class AbstractElement {
protected:
    char symbole;
    bool visible;

public:
    AbstractElement(char symbole);

    AbstractElement();

    bool isVisible() const;

    void setVisible(bool visible);

    char getSymbole() const;

    void setSymbole(char symbole);

    virtual void toString() = 0;

    friend std::ostream &operator<<(std::ostream &os, const AbstractElement &element);
};


#endif //DUNGEONGAME_ELEMENT_H
