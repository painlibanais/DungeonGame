//
// Created by Mohammed on 15/01/2018.
//

#include "Item.h"

char Item::getType() const {
    return type;
}

void Item::setType(char type) {
    Item::type = type;
}

Item::Item(char type) : type(type) {}

Point *Item::getPosition() {
    return position;
}

void Item::setPosition(Point *position) {
    Item::position = position;
}

int Item::getId() const {
    return id;
}

void Item::setId(int id) {
    Item::id = id;
}
