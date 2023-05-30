#include <iostream>
class Player{
    int pos;
    std::string name;
    public:
    //setters for 'pos' and 'name'
    void setPos(int);
    void setName(std::string);
    //getters for 'pos' and 'name'
    int getPos();
    std::string getName();
};