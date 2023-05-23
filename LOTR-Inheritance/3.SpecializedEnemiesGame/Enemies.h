#ifndef ENEMIES_H
#define ENEMIES_H
#include "Enemy.h"
class Orc: public Enemy{
  public:
  Orc(){
    this->setType("Orc");
    this->setDamage(-6);
  }
};
class Ogre: public Enemy{
  public:
  Ogre(){
    this->setType("Ogre");
    this->setDamage(-12);
  }
};
#endif