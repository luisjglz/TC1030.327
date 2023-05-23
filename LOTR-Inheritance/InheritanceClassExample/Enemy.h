#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
class Enemy{
    std::string name;
    int damage;

    public:
    Enemy(){
        name = "generic enemy";
        damage = 0;
    };
    Enemy(std::string n, int d){
        name = n;
        damage = d;
    }
    //Getters & setters:
    std::string getName(){
        return name;
    }
    int getDamage(){
        return damage;
    }
    void setName(std::string n){
        name = n;
    }
    void setDamage(int d){
        damage = d;
    }
};

#endif