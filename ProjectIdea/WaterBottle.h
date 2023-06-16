#ifndef COLLECTABLE_H
#include "Collectable.h"
#define COLLECTABLE_H
#endif


#include <iostream>
#include <cmath>
class WaterBottle : public Collectable{
    std::string material;
    float capacity;
    public:
        WaterBottle(int _id, std::string _team, std::string _material, float _capacity){
            this->setId(_id);
            this->setTeam(_team);
            material = _material;
            capacity = _capacity;
        };
        std::string toStr(){
            return "Water bottle - Team: " + this->getTeam() + ", Material: " + material + ", Capacity: " + std::to_string(capacity) + "ml.";
        };
};