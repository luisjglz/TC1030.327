#include "Dye.h"
#include <string>
#include <iostream>
class MyGame{
    std::string board[30]; // [][][][][][][]

    public:
    void start(){
        //Create the board:
        for(int i = 0; i < 30; i++){
            board[i] = "N";
        };
        //seed random:
        srand(time(0)); 
        //Create a random number between 3 and 27
        int num = 3 + (rand()%25);
        board[num] = "S";

        //Create a random number between 3 and 27
        int num2 = num;
        while(num2 == num){
            num2 = 3 + (rand()%25);
        }
        board[num2] = "S";
        
        std::cout << "Game started" << std::endl;
        printBoard();

        //Start playing!
        int p1p = 0, p2p = 0;
        std::string answer = "";
        std::string turn = "p1";
        while (answer != "E"){
            if(turn == "p1"){
                //Player 1 turn
                std::cout << "Player 1 turn, type 'C' to roll the dye and 'E' to exit" << std::endl;
                std::cin >> answer;
                if(answer == "C"){
                    //roll the dye
                    Dye dye;
                    int res = dye.roll();
                    p1p = p1p + res;
                    std::cout << "Player 1 got a " << res << ", now he is in tile: " << p1p << std::endl;
                    //Change player position.
                }
                turn = "p2";
            }
            if(turn == "p2"){
                //Player 2 turn
                std::cout << "Player 2 turn, type 'C' to roll the dye and 'E' to exit" << std::endl;
                std::cin >> answer;
                if(answer == "C"){
                    //roll the dye
                    Dye dye;
                    int res = dye.roll();
                    p2p = p2p + res;
                    std::cout << "Player 2 got a " << res << ", now he is in tile: " << p2p << std::endl;
                    //Change player position.
                }
                turn = "p1";
            }
        }


    };
    void printBoard(){
        for(int i = 29; i >= 0; i--){
            std::cout << "[" << board[i] << "]";
            if(i % 5 == 0){
                std::cout << "" << std::endl;
            }
        };
    }
};