#include "Animal.h"

class Dog : public Animal{
    public:
    void sayHi(){
        std::cout << "Woff woff!" << std::endl;
    }
};