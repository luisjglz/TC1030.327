#ifndef TILE_H
#include "Tile.h"
#define TILE_H
#endif

#include <iostream>
class NormalTile : public Tile{
    public:
    void print(){
        std::cout << "I'm a normal tile" << std::endl;
    };
};