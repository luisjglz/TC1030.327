#include "Die.h"
#include <iostream>

int Die::roll() {
    int randi = (rand() % 6) + 1;
    return randi;
}