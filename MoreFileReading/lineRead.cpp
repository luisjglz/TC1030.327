#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

int main()
{
    // Create an empty string that will hold each line temporarly:
    string someLine; //"Mauricio Aguilar Pacheco,A01663667,3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";

    // Create a Student vector container
    vector<Student> students;
    
    someLine = "Mauricio Aguilar Pacheco,A01663667,3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";

    // someLine = "Mauricio Aguilar Pacheco,A01663667,3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";
    // get first token (name) -- "Mauricio Aguilar Pacheco"
    string name = someLine.substr(0, someLine.find(","));
    // erase that first token from the original string: -- "A01663667,3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";
    someLine = someLine.substr(someLine.find(",")+1, someLine.length());

    //ID
    string id = someLine.substr(0, someLine.find(","));
    // remove id -- "3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519";
    someLine = someLine.substr(someLine.find(",")+1, someLine.length());

    //sisID
    string sisID = someLine.substr(0, someLine.find(","));
    // remove sisID -- "3,Student,Jun 5 at 10:47pm,0.589456018518519";
    someLine = someLine.substr(someLine.find(",")+1, someLine.length());

    //Section - stoi to convert string to int
    int section = stoi(someLine.substr(0, someLine.find(",")));
    // remove section -- "Student,Jun 5 at 10:47pm,0.589456018518519";
    someLine = someLine.substr(someLine.find(",")+1, someLine.length());

    //Role
    string role = someLine.substr(0, someLine.find(","));
    // remove role -- "Jun 5 at 10:47pm,0.589456018518519";
    someLine = someLine.substr(someLine.find(",")+1, someLine.length());

    //lastActivity
    string lastActivity = someLine.substr(0, someLine.find(","));
    // remove last activity -- "0.589456018518519";
    someLine = someLine.substr(someLine.find(",")+1, someLine.length());

    //totalActivity -- stod = string to double
    double totAct = stod(someLine.substr(0, someLine.find(",")));

    //Create new Student:
    Student student1(name, id, stoi(sisID), section, role, lastActivity, totAct);
    std::cout << student1.toStr() << std::endl;

    //Add student to vector:
    students.push_back(student1);

    

}