#include <iostream>


class Dog{
    int breed;
    float age;
    std::string gender;
    std::string vaccineList[10];
    public:
        void Bark(){
            std::cout << "Woff woff!!" << std::endl;
        }
        void Bite(){
            std::cout << "I just bite you!!" << std::endl;
        }
        void Eat(){
            std::cout << "Yummy!!" << std::endl;
        }
        void unEat(){
            std::cout << "Did you bring the bag?" << std::endl;
        }
};


