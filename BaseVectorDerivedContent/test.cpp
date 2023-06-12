#include "NormalTile.h"
#include "SnakeTile.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<Tile *> board;
    
    NormalTile nt;
    board.push_back(& nt);

    SnakeTile st;
    board.push_back(& st);

    board[0]->print();
    board[1]->print();

    return 0;
}