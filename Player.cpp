#include "Player.h"
#include "Battleship.h"
#include "Carrier.h"

Player::Player() : board(10, std::vector<char>(10, ' ')) {
    initializeShips();
}

Player::~Player() {
    for (Ship* ship : ships) {
        delete ship;
    }
}

void Player::initializeShips() {
    ships.push_back(new Battleship());
    ships.push_back(new Carrier());
}

void Player::placeShips() {
    for (Ship* ship : ships) {
        bool validPlacement = false;
        while (!validPlacement) {
            int x = rand() % 10;
            int y = rand() % 10;
            bool horizontal = rand() % 2 == 0;

            // Check if the ship can be placed at the randomly generated coordinates
            if (horizontal) {
                if (x + ship->getLength() <= 10) {
                    validPlacement = true;
                    for (int i = x; i < x + ship->getLength(); i++) {
                        if (board[y][i] != ' ') {
                            validPlacement = false;
                            break;
                        }
                    }
                    if (validPlacement) {
                        for (int i = x; i < x + ship->getLength(); i++) {
                            board[y][i] = '#';
                        }
                    }
                }
            } else {
                if (y + ship->getLength() <= 10) {
                    validPlacement = true;
                    for (int i = y; i < y + ship->getLength(); i++) {
                        if (board[i][x] != ' ') {
                            validPlacement = false;
                            break;
                        }
                    }
                    if (validPlacement) {
                        for (int i = y; i < y + ship->getLength(); i++) {
                            board[i][x] = '#';
                        }
                    }
                }
            }
        }
    }
}

void Player::displayBoard() const {
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 10; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


void Player::saveBoardToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& row : board) {
            for (char cell : row) {
                file << cell << ' ';
            }
            file << std::endl;
        }
        file.close();
        std::cout << "Board saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to save board to file." << std::endl;
    }
}

bool Player::allShipsSunk() const {
    for (const Ship* ship : ships) {
        if (!ship->isSunk()) {
            return false;
        }
    }
    return true;
}

void Player::makeMove(int x, int y) {
    if (board[y][x] == '#') {
        std::cout << "Computer hit your ship!" << std::endl;
        board[y][x] = 'X';
    }
    else {
        std::cout << "Computer missed." << std::endl;
        board[y][x] = 'O';
    }
}
