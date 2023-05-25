#ifndef CARRIER_H
#define CARRIER_H

#include "Ship.h"

class Carrier : public Ship {
public:
    Carrier();
    ~Carrier();

    void displayStatus() const override;
};

#endif  // CARRIER_H
