#include "Player.h"
#include <iostream>
#include <vector>

class MyGame{
    std::vector<std::string> board;
    int boardSize, maxTurns;
    Player p1,p2;
    public:
        void setBoardSize(int);
        int getBoardSize();
        void setMaxTurns(int);
        int getMaxTurns();
        void start();
        void printBoard(Player &,Player &);
        void doTurn(Player &);
        std::string getTile(int);
};