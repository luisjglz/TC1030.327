
#include <iostream>
using namespace std;

class Shape{
    public:
        Shape(){
            cout << "Shape created" << endl;
        }
        void draw(){
            cout << "Drawing shape" << endl;
        }
        void print(){
            cout << "Printing shape" << endl;
        }
};

class Square : public Shape{
    public:
        Square() : Shape(){
            cout << "Square created" << endl;
        }
        void draw(){
            cout << "Drawing square" << endl;
        }
        void print(){
            cout << "Printing square" << endl;
        }
};

int main(){
    Shape * shapePtr;
    Square sq;

    shapePtr = & sq;

    shapePtr->draw();


    return 0;
}
