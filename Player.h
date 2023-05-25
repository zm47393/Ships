#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Ship.h"

class Player {
private:
    std::vector<std::vector<char>> board;
    std::vector<Ship*> ships;

public:
    Player();
    ~Player();

    void initializeShips();
    void placeShips();
    void displayBoard() const;
    void saveBoardToFile(const std::string& filename) const;
    bool allShipsSunk() const;
    void makeMove(int x, int y);
};

#endif  // PLAYER_H
