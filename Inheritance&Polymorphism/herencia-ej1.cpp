#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "GradTeachingFellow.h"

using namespace std;

int main()
{
    Person persona1;
    cout << "persona1 nombre: " << persona1.getName() << endl;

    Student student1;
    cout << "student1 nombre: " << student1.getName() << endl;
    cout << "student1 address: " << student1.getAddress() << endl;

    Teacher teacher1;
    cout << "teacher1 nombre: " << teacher1.getName() << endl;
    cout << "teacher1 rank: " << teacher1.getRank() << endl;

    GradTeachingFellow gtf1;
    cout << "gtf1: " << gtf1.getName() << std::endl;
}