#include "Enemy.h"

class Orc : public Enemy{
    public:
    Orc(std::string n, int d){
        setName(n);
        setDamage(d);
    };
};