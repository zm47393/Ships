#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Player.h"
#include "ComputerPlayer.h"

class Game {
private:
    Player* player;
    ComputerPlayer* computerPlayer;

public:
    Game();
    ~Game();

    void start();
    void playTurn();
    void end();
};

#endif  // GAME_H
