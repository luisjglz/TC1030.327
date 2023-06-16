#include <iostream>
class Collectable{
    int id;
    std::string team;
    public:
        virtual std::string toStr()=0;
        void setId(int _id){
            id = _id;
        };
        void setTeam(std::string _team){
            team = _team;
        };
        std::string getTeam(){
            return team;
        };
};