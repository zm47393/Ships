#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer() : Player() {}

ComputerPlayer::~ComputerPlayer() {}

std::pair<int, int> ComputerPlayer::generateMove() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 9);

    int x = dist(gen);
    int y = dist(gen);

    return std::make_pair(x, y);
}
