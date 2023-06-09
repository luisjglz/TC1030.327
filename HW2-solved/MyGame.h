#ifndef TILE_H
#include "Tile.h"
#define TILE_H
#endif

#ifndef NORMALTILE_H
#include "NormalTile.h"
#define NORMALTILE_H
#endif

#ifndef SNAKE_H
#include "Snake.h"
#define SNAKE_H
#endif

#ifndef LADDER_H
#include "Ladder.h"
#define LADDER_H
#endif

#ifndef PLAYER_H
#include "Player.h"
#define PLAYER_H
#endif

#include <iostream>
#include <vector>

class MyGame{
    bool gameOver;
    std::vector<Tile*> board;
    std::string gameType;
    int boardSize, numPlayers, maxTurns, numSnakes, numLadders, penaltySnakes, rewardLadder;
    std::vector<Player*> players;
    public:
        MyGame(int,char**);
        void setBoardSize(int);
        int getBoardSize();
        void setMaxTurns(int);
        int getMaxTurns();
        void setNumPlayers(int);
        int getNumPlayers();
        void start();
        void printBoard(std::vector<Player *> &);
        void doTurn(Player &);
        void setNumSnakes(int);
        int getNumSnakes();
        void setNumLadders(int);
        int getNumLadders();
        void setPenaltySnakes(int);
        int getPenaltySnakes();
        void setRewardLadder(int);
        int getRewardLadder();
        std::string getGameType();
        void setGameType(std::string);
        void setDefaults();
        void play(std::string);
};