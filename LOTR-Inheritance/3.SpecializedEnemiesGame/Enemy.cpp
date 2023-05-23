#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(){
  type = "generic";
  damage = 0;
}

Enemy::Enemy(string the_type){ 
    this->type = the_type;
    this->damage = 0;
}

Enemy::Enemy(string the_type, int the_damage){ 
    this->type = the_type;
    this->damage = the_damage;
}

string Enemy::getType(){
  return type;
}

void Enemy::setType(string the_type){
  this->type=the_type;
}

int Enemy::getDamage(){
  return damage;
}

void Enemy::setDamage(int the_damage){
  damage = the_damage;
}