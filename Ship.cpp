#include "Ship.h"

Ship::Ship(const std::string& name, int length) : name(name), length(length), health(length) {}

Ship::~Ship() {}

const std::string& Ship::getName() const {
    return name;
}

int Ship::getLength() const {
    return length;
}

int Ship::getHealth() const {
    return health;
}

bool Ship::isSunk() const {
    return health == 0;
}

void Ship::hit() {
    if (health > 0) {
        health--;
    }
}
