#include "Die.h"
#include <iostream>

int Die::roll() {
    srand(static_cast<unsigned int>(time(0)));
    int randi = (rand() % 6) + 1;
    return randi;
}