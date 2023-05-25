#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <vector>
#include <utility>
#include <random>
#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer();
    ~ComputerPlayer();

    std::pair<int, int> generateMove() const;
};

#endif  // COMPUTERPLAYER_H
