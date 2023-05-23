#ifndef WIZARD_H
#define WIZARD_H

#include "Enemy.h"

class Wizard : public Enemy{
    public:
    Wizard(){
        setName("Generic wizard");
        setDamage(-35);
    }
    Wizard(std::string n, int d){
        setName(n);
        setDamage(d);
    };
    void performSpell(){
        std::cout << "You're cursed!" << std::endl;
    }
};

#endif