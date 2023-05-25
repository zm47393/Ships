#include "Game.h"

int main() {
    Game game;
    game.start();

    while (true) {
        game.playTurn();
    }

    return 0;
}