#include "Player.h"
//setters for 'pos' and 'name'
void Player::setPos(int p){
    pos = p;
};
void Player::setName(std::string n){
    name = n;
};
//getters for 'pos' and 'name'
int Player::getPos(){
    return pos;
};
std::string Player::getName(){
    return name;
};