#include "Carrier.h"

Carrier::Carrier() : Ship("Carrier", 5) {}

Carrier::~Carrier() {}

void Carrier::displayStatus() const {
    std::cout << "Carrier - Length: " << length << " | Health: " << health << std::endl;
}
