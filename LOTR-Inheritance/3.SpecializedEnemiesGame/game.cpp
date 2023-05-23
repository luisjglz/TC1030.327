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

    int points = 100;

    srand(time(0));
    
    cout << "Hi player, you have " << points << " points. Any key to continue." << endl;

    while(points > 0){
        string res;
        cin >> res;

        //random number between 1 and 3 to get opponent:
        // 1: generic enemy
        // 2: Orc
        // 3: Ogre

        int random_opponent = rand()%3+1;

        cout << "You rolled a: " << random_opponent << endl;
        switch(random_opponent){
            case 1: cout << "You fight against " << generic_enemy1.getType() << endl;
                    cout << "You loose " << generic_enemy1.getDamage() << endl;
                    points += generic_enemy1.getDamage();
                    
            case 2: cout << "You fight against " << orc1.getType() << endl;
                    cout << "You loose " << orc1.getDamage() << endl;
                    points += orc1.getDamage();
                    
            case 3: cout << "You fight against " << ogre1.getType() << endl;
                    cout << "You loose " << ogre1.getDamage() << endl;
                    points += ogre1.getDamage();
                    
        }
        cout << "You now have " << points << " points." << endl;
        cout << "\n";
    }

}