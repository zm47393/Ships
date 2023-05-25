#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"

class Battleship : public Ship {
public:
    Battleship();
    ~Battleship();

    void displayStatus() const override;
};

#endif  // BATTLESHIP_H
