#ifndef TILE_H
#include "Tile.h"
#define TILE_H
#endif

#include <iostream>
class SnakeTile : public Tile{
    public:
    void print(){
        std::cout << "I'm a snake tile" << std::endl;
    };
};