#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
using namespace std;
class Enemy{
  private:
    //private attributes
    std::string type;

  public:
    //public attributes
    Enemy();
    Enemy(std::string);
    //getters
    std::string getType();
    //setters
    void setType(std::string);
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