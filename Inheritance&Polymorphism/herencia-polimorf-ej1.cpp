/* Herencia y polimorfismo */

#include <iostream>
using namespace std;

class Perro{
    public:
    void ladrar(){
        cout << "waff! " << endl;
    };

    //Function overloading
    void ladrar(int veces){
        cout << "----------" << endl;
        for(int i=0; i<veces; i++){
            ladrar();
        };
        cout << "----------" << endl;
    };
};

class Chihuahua : public Perro{
    public:
    // function overriding
    void ladrar(){
        cout << "wiff! " << endl;
    };
    //Function overriding
    void ladrar(int veces){
        cout << "----------" << endl;
        for(int i=0; i<veces; i++){
            ladrar();
        };
        cout << "----------" << endl;
    };
};

class GranDanes : public Perro{
    public:
    // function overriding
    void ladrar(){
        cout << "woff! " << endl;
    };
};

int main(){
    Perro perro;
    Chihuahua chi;
    GranDanes gra;

    perro.ladrar();
    chi.ladrar();
    gra.ladrar();

    perro.ladrar(10);

    chi.ladrar(3);
   
};










