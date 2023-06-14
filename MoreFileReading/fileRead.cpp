#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
using namespace std;

int main()
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("data.txt");

    // Create our video container...
    vector<Student> students;

    int lineNum = 1;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        if (lineNum > 1)
        {
            ////"Mauricio Aguilar Pacheco,A01663667,3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";
            // get first token (name) -- "Mauricio Aguilar Pacheco"
            string name = myText.substr(0, myText.find(","));
            // erase that first token from the original string: -- "A01663667,3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // ID
            string id = myText.substr(0, myText.find(","));
            // remove id -- "3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // sisID
            int sisID = stoi(myText.substr(0, myText.find(",")));
            // remove sisID -- "3,Student,Jun 5 at 10:47pm,0.589456018518519";
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // Section - stoi to convert string to int
            int section = stoi(myText.substr(0, myText.find(",")));
            // remove section -- "Student,Jun 5 at 10:47pm,0.589456018518519";
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // Role
            string role = myText.substr(0, myText.find(","));
            // remove role -- "Jun 5 at 10:47pm,0.589456018518519";
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // lastActivity
            string lastActivity = myText.substr(0, myText.find(","));
            // remove last activity -- "0.589456018518519";
            myText = myText.substr(myText.find(",") + 1, myText.length());

            // totalActivity -- stod = string to double
            double totAct = stod(myText.substr(0, myText.find(",")));

            // Create new Student:
            Student student1(name, id, sisID, section, role, lastActivity, totAct);
            std::cout << student1.toStr() << std::endl;

            // Add student to vector:
            students.push_back(student1);
        }
        lineNum++;
    }

    // Close the file
    MyReadFile.close();

    // Imprimir todos los videos dentro del vector videosDB:
}
