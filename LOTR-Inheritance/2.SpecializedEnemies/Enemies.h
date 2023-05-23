#ifndef ENEMIES_H
#define ENEMIES_H
#include "Enemy.h"
class Orc: public Enemy{
  public:
  Orc(){
    this->setType("Orc");
  }
  int doDamage(){
    return -6;
  }
};
class Ogre: public Enemy{
  public:
  int doDamage(){
    return -12;
  }
};
#endif