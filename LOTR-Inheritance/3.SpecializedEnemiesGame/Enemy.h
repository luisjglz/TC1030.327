#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
using namespace std;
class Enemy{
  private:
    //private attributes
    std::string type;
    int damage;

  public:
    //public attributes
    Enemy();
    Enemy(std::string);
    Enemy(std::string,int);
    //getters
    std::string getType();
    int getDamage();
    //setters
    void setType(std::string);
    void setDamage(int);
    //other functions
    void to_str(){
        cout << "****************" << endl;
        cout << "*     ENEMY    *" << endl;
        cout << "* ------------ *" << endl;
        cout << "* Type: " << type << endl;
        cout << "*              *" << endl;
        cout << "****************" << endl;
    }
};
#endif