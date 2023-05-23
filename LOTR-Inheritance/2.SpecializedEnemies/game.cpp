#include "Enemies.h"
#include <iostream>
using namespace std;

int main(){
    Enemy generic_enemy1;
    Orc orc1;
    Ogre ogre1;

    generic_enemy1.to_str();
    orc1.to_str();
    ogre1.to_str();
    
    cout << "The Orc does " << orc1.doDamage() << " of damage." << endl;
    cout << "The Ogre does " << ogre1.doDamage() << " of damage." << endl;
    cout << "The generic_enemy1 type is: " << generic_enemy1.getType() << endl;
    cout << "The Orc type is: " << orc1.getType() << endl;

}