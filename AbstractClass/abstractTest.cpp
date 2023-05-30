#include <iostream>
#include "Dog.h"

int main(){
    //Animal class is abstract, can NOT be instantiated:

    /*
    This would cause an error:

    Animal unAnimal;
    
    */

   //We are REQUIRED to create Dog's objects only:

   Dog perro;
   perro.sayHi();

    return 0;
};