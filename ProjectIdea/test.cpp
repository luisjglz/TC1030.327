#include <iostream>
#include <fstream>
#include <vector>


#ifndef COLLECTABLE_H
#include "Collectable.h"
#define COLLECTABLE_H
#endif

#ifndef CARD_H
#include "Card.h"
#define CARD_H
#endif

#ifndef WATERBOTTLE_H
#include "WaterBottle.h"
#define WATERBOTTLE_H
#endif

using namespace std;

int main()
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("collectables.txt");

    // Create our video container...
    vector<Collectable *> inventory;

    int lineNum = 1;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        if (lineNum > 1)
        {
            //ID,TYPE,TEAM,PLAYER,SERIES,YEAR,MATERIAL,CAPACITY

            // get first token (id)
            int id = std::stoi(myText.substr(0, myText.find(",")));
            // erase that first token
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // Type
            string type = myText.substr(0, myText.find(","));
            // remove type
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // Team
            string team = myText.substr(0, myText.find(","));
            // remove team
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // Create either Card or Water bottle and add it to inventory:
            if(type=="Card"){

                // Player
                string player = myText.substr(0, myText.find(","));
                // remove player
                myText = myText.substr(myText.find(",") + 1, myText.length());

                // series
                string series = myText.substr(0, myText.find(","));
                // remove series
                myText = myText.substr(myText.find(",") + 1, myText.length());

                // year
                int year = stoi(myText.substr(0, myText.find(",")));
                
                //Card
                Card * c = new Card(id,team,player,series,year);
                inventory.push_back(c);
            
            }

            else if(type=="WaterBottle"){

                // remove player
                myText = myText.substr(myText.find(",") + 1, myText.length());
                // remove series
                myText = myText.substr(myText.find(",") + 1, myText.length());
                // remove year
                myText = myText.substr(myText.find(",") + 1, myText.length());


                // material
                string material = myText.substr(0, myText.find(","));
                // remove material
                myText = myText.substr(myText.find(",") + 1, myText.length());

                // capacity
                float capacity = stof(myText.substr(0, myText.find(",")));


                //Water bottle
                WaterBottle * wb = new WaterBottle(id,team,material,capacity);
                inventory.push_back(wb);
            }

            
        }
        lineNum++;
    }

    // Close the file
    MyReadFile.close();

    // Print all inventory:
    for(Collectable * c : inventory){
        cout << c->toStr() << endl;
    }


}