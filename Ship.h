#ifndef SHIP_H
#define SHIP_H

#include <iostream>

class Ship {
protected:
    std::string name;
    int length;
    int health;

public:
    Ship(const std::string& name, int length);
    virtual ~Ship();

    const std::string& getName() const;
    int getLength() const;
    int getHealth() const;
    bool isSunk() const;

    void hit();
    virtual void displayStatus() const = 0;
};

#endif  // SHIP_H
