#include "Enemy.h"

class Ogre : public Enemy{
    public:
    Ogre(std::string n, int d){
        setName(n);
        setDamage(d);
    };
};