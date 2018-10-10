#ifndef DUNGEONGAME_PLAYABLEELEMENT_H
#define DUNGEONGAME_PLAYABLEELEMENT_H


#include "AbstractElement.h"

class PlayableElement : public AbstractElement {
protected:
    int id;
public:
    explicit PlayableElement(char symbole, int id);

    int getId() const;

    void setId(int id);
};


#endif //DUNGEONGAME_PLAYABLEELEMENT_H
