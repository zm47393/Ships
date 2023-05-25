#include "Game.h"

Game::Game() {
    player = new Player();
    computerPlayer = new ComputerPlayer();
}

Game::~Game() {
    delete player;
    delete computerPlayer;
}

void Game::start() {
    std::cout << "Welcome to Battleship!" << std::endl;
    std::cout << "Place your ships on the board." << std::endl;
    player->placeShips();
}

void Game::playTurn() {
    std::cout << "Your turn:" << std::endl;
    player->displayBoard();
    std::cout << "Enter coordinates (x y): ";
    int x, y;
    std::cin >> x >> y;

    // Perform player's move
    // ...

    // Perform computer's move
    std::pair<int, int> computerMove = computerPlayer->generateMove();
    int computerX = computerMove.first;
    int computerY = computerMove.second;

    // Perform computer's move on player's board
    player->makeMove(computerX, computerY);

    std::cout << "Computer's move: " << computerX << " " << computerY << std::endl;

    // Check game over condition
    if (player->allShipsSunk()) {
        std::cout << "You lost. Game over!" << std::endl;
        end();
    }
    else if (computerPlayer->allShipsSunk()) {
        std::cout << "You won! Game over!" << std::endl;
        end();
    }
}



void Game::end() {
    // Save boards to files
    player->saveBoardToFile("player_board.txt");
    computerPlayer->saveBoardToFile("computer_board.txt");

    // Clean up resources
    delete player;
    delete computerPlayer;
}
