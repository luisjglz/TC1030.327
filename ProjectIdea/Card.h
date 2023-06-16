#ifndef COLLECTABLE_H
#include "Collectable.h"
#define COLLECTABLE_H
#endif


#include <iostream>
class Card : public Collectable{
    std::string player;
    std::string series;
    int year;
    public:
        Card(int _id, std::string _team, std::string _player, std::string _series, int _year){
            this->setId(_id);
            this->setTeam(_team);
            player = _player;
            series = _series;
            year = _year;
        };
        std::string toStr(){
            return "Card - Team: " + this->getTeam() + ", Player: " + player + ", Series: " + series;
        };
};