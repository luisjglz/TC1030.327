#include <iostream>

class Fraction{
    int numerator;
    int denominator;
    //A private method to return the GCD:
    int gcd(int a, int b) {
        if (b == 0)
        return a;
        return gcd(b, a % b);
    }
    public:
        Fraction(){
            numerator = 0;
            denominator = 1;
        }
        Fraction(int n, int d){
            if(d < 0){
                std::cout << "Invalid input. Default initializing." << std::endl;
                n = 0;
                d = 1;
            }
            int g = gcd(n,d);
            numerator = n/g;
            denominator = d/g;
        }
        void display(){
            std::cout << numerator << "/" << denominator << std::endl;
        }


        int getNum(){
            return numerator;
        }
        int getDen(){
            return denominator;
        }

        Fraction sum(Fraction f){
            int fac = denominator * f.getDen();
            int resNum1 = (fac/denominator)*numerator;
            int resNum2 = (fac/f.getDen())*f.getNum();
            Fraction res(resNum1+resNum2,fac);
            return res;
        }
};


