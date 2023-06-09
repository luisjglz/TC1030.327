#ifndef TILE_H
#include "Tile.h"
#define TILE_H
#endif

std::string Tile::getType(){
    return type;
}
void Tile::setType(std::string t){
    type = t;
}
int Tile::getAction(){
    return action;
}
void Tile::setAction(int a){
    action = a;
}