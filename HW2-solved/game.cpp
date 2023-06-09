#include "MyGame.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    srand(time(0));
    MyGame game(argc,argv);
    game.start();
    return 0;
}