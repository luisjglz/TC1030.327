#include "Fraction.h"
#include <iostream>

int main(){
    Fraction frac1(2,3);
    Fraction frac2(3,4);
    
    Fraction res = frac2.sum(frac1);
    res.display();
}


