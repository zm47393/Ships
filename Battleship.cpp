#include "Battleship.h"

Battleship::Battleship() : Ship("Battleship", 4) {}

Battleship::~Battleship() {}

void Battleship::displayStatus() const {
    std::cout << "Battleship - Length: " << length << " | Health: " << health << std::endl;
}
