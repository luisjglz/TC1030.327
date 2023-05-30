#include <iostream>
int main(){

    int num = 1;
    int * numPtr = & num;

    std::string name = "Luis";
    std::string * namePtr = & name;

    //address of where 'num' is stored (&):

    std::cout << "The value of 'num' is: " << num << std::endl;
    std::cout << "The mem address of 'num': " << & num << std::endl;
    std::cout << "The value of 'numPtr': " << numPtr << std::endl;

    //Change the value of 'num' to 2 using the pointer:
    * numPtr = 2;
    std::cout << "The value of 'num' is: " << num << std::endl;

    std::cout << "The value of 'name' is: " << name << std::endl;
    std::cout << "The mem address of 'name': " << & name << std::endl;
    std::cout << "The value of 'namePtr': " << namePtr << std::endl;
    std::cout << "Get 'name' through 'namePtr': " << * namePtr << std::endl;

    //change 'name' through pointer:
    * namePtr = "Pedro";
    std::cout << "Get 'name' through 'namePtr': " << * namePtr << std::endl;

    //A pointer that points to another pointer:
    int ** othPtr = & numPtr;

    ** othPtr = 5;
    std::cout << num;

    return 0;
}