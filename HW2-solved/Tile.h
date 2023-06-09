#include <iostream>
class Tile{
    std::string type;
    int action;
    public:
    virtual void makeAbstract()=0;
    std::string getType();
    void setType(std::string);
    int getAction();
    void setAction(int);
};