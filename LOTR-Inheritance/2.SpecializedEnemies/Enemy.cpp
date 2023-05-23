#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(){
  type = "generic";
}

Enemy::Enemy(string the_type){ 
    this->type=the_type;
}

string Enemy::getType(){
  return type;
}

void Enemy::setType(string the_type){
  this->type=the_type;
}