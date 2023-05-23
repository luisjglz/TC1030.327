#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(){
  type = "generic";
}

Enemy::Enemy(string the_type){ 
    this->type=the_type;
}