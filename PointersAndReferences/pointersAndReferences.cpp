#include <iostream>
using namespace std;

int main(){

    int num = 1;

    cout << "'num' value: " << num << endl;
    cout << "'num' memory address: " << & num << endl;

    int * numPtr = & num;

    cout << "'numPtr' memory address: " << & numPtr << endl;
    cout << "'Memory address to which 'numPtr' points to: " << numPtr << endl;

    cout << "Value of the variable to which 'numPtr' points to: " << * numPtr << endl;

    //Updated 'num' value using the 'numPtr':
    *numPtr = 2;
    cout << "Updated 'num' value using the 'numPtr': " << num << endl;

    
    //Create a pointer to a pointer
    int ** otherPointer = & numPtr;

    //Get the value of the 
    cout << "** otherPointer: " << ** otherPointer << endl;

    //Create a reference var to 'num' and save it as 'numRef'
    int &numRef = num;
    //Print the value of the variable to which numRef references to:
    cout << "'numRef': " << numRef << endl;
    //Change 'num' by using a reference to it:
    numRef = 3;
    //Print updated 'num' value:
    cout << "'num': " << num << endl;

    return 0;
}