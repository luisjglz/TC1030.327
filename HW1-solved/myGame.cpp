#include "MyGame.h"
#include "Die.h"
#include <iostream>

void MyGame::start(){
    setBoardSize(30);
    p1.setName("A");
    p1.setPos(1);
    p2.setName("B");
    p2.setPos(1);
    setMaxTurns(getBoardSize()/2);
    //Initialize board with boardSize 'N'´s:
    for(int i = 1; i<getBoardSize()+1; i++){
        //board.push_back(std::to_string(i));
        board.push_back("N");
    }
    //create 3 random snakes
    //snakes can't be in tiles 1,2,3,28,29,30
    int totsnakes = 3;
    srand(static_cast<unsigned int>(time(0)));
    while(totsnakes>0){
        int random_tile = (rand() % 24) + 3;
        if(random_tile > 3 && random_tile < boardSize-3 && board[random_tile] != "S" && board[random_tile] != "L"){
            board[random_tile] = "S";
            totsnakes--;
        }
    }
    //create 3 random ladders
    //ladders can't be in tiles 1,2,3,28,29,30
    int totladders = 3;
    srand(static_cast<unsigned int>(time(0)));
    while(totladders>0){
        int random_tile = (rand() % 24) + 3;
        if(random_tile > 3 && random_tile < boardSize-3 && board[random_tile] != "L" && board[random_tile] != "S"){
            board[random_tile] = "L";
            totladders--;
        }
    }
    printBoard(p1, p2);

    //start the game
    std::cout << "Press 'C' to continue playing or 'E' to exit the game" << std::endl;

    std::string answer = "";
    std::cin >> answer;
    int turns = 0;
    while(answer != "E"){
        turns++;

        //Check for maxTurns:
        if(turns > getMaxTurns()){
            std::cout << "Max turns number exceeded. Game ended." << std::endl;
            //Check who won and display message:
            if(p1.getPos()>p2.getPos()){
                std::cout << p1.getName() << " won, because their final tile was: " << p1.getPos() << std::endl;
            }
            else if(p1.getPos()<p2.getPos()){
                std::cout << p2.getName() << " won, because their final tile was: " << p2.getPos() << std::endl;
            }
            else{
                std::cout << "Wow, it was a draw!. " << p1.getName() << " ended in tile: " << p1.getPos() << " and " << p2.getName() << " ended in tile: " << p2.getPos() << std::endl;
            }
            //Get out of the 'while' loop:
            break;
        }


        std::cout << "Turn #" << turns << std::endl;

        //Player turn, alternating when turn is odd/even.
        if(turns%2==1){
            //odd, player's 1 turn
            doTurn(p1);
        }
        else{
            //even, player's 2 turn}
            doTurn(p2);
        }
        std::cout << "Press 'C' to continue playing or 'E' to exit the game" << std::endl;
        std::cin >> answer;
    }


}

void MyGame::doTurn(Player & player){
    //We get a reference to the player object in '& player'
    
    //Roll de die:
    Die die;
    int rollDie;
    rollDie = die.roll();

    //Check for win
    if(player.getPos()+rollDie >= getBoardSize()){
        //Reset position
        player.setPos(getBoardSize());
        //Win!
        std::cout << player.getName() << " won!!!" << std::endl;
        //Finish program execution
        return;
    }

    std::cout << "It's player: " << player.getName() << " turn. Player " << player.getName() << " is in tile: " << player.getPos() << std::endl;
    std::cout << player.getName() << " rolled the die and got a: " << rollDie << std::endl;
    std::cout << player.getName() << " landed on tile " << player.getPos()+rollDie << " which is a " << getTile(player.getPos()-1+rollDie) << " tile." << std::endl;
    if(getTile(rollDie+player.getPos()-1) == "S"){
        //snake tile back 3 tiles:
        player.setPos((player.getPos()+rollDie)-3);
    }
    else if(getTile(rollDie+player.getPos()-1) == "L"){
        //ladder tile forward 3 tiles:
        player.setPos((player.getPos()+rollDie)+3);
    }
    else if(getTile(rollDie+player.getPos()-1) == "N"){
        //normal tile, update pos:
        player.setPos(player.getPos()+rollDie);
    }

    
    std::cout << player.getName() << " final position is: " << player.getPos() << std::endl;
    
    //print board:
    printBoard(p1, p2);
}

void MyGame::printBoard(Player & p1, Player & p2){

    std::cout << "***************" << std::endl;
    std::cout << "p1: " << p1.getPos() << std::endl;
    std::cout << "p2: " << p2.getPos() << std::endl;
    std::cout << "***************" << std::endl;


    //prints the board in a snake & ladders style:
    int rows = 1, currenttile = 30;
    int tiles;
    std::string line = "";
    //print tile number 30
    std::cout << getBoardSize() << std::endl;
    for(int i = getBoardSize()-1; i >= 0; i--){
        if(rows%2==1){ //odd row



            //check for players in tile:
            if(p1.getPos()-1==i && p2.getPos()-1==i){
                //both players in same tile
                std::cout << "[*]";
            }
            else if(p1.getPos()-1==i){
                //player 1 in tile
                std::cout << "[" << p1.getName() << "]";
            }
            else if(p2.getPos()-1==i){
                //player 2 in tile
                std::cout << "[" << p2.getName() << "]";
            }
            else{
                //no player in tile
                std::cout << "[" << board[i] << "]";
            }
            currenttile--;
        }
        if(rows%2==0){ //even row, 
            //print tiles in increasing order
            //reset line:
            line = "";
            tiles = 0;
            while(tiles < 5){

                
                
                //line = ("[" + board[i] + "]") + line;
                if(p1.getPos()-1==i && p2.getPos()==p1.getPos()){
                    //both players in same tile
                    line = ("[*]") + line;
                }
                else if(p1.getPos()-1==i){
                    //player 1 in tile
                    line = ("[" + p1.getName() + "]") + line;
                }
                else if(p2.getPos()-1==i){
                    //player 2 in tile
                    line = ("[" + p2.getName() + "]") + line;
                }
                else{
                    //no player in tile
                    line = ("[" + getTile(i) + "]") + line;
                }
                
                
                
                i--;
                tiles++;
            }
            currenttile-=5;
            i++;
            std::cout << line;
        }
        if(currenttile%5==0){//print an enter every 5 tiles
            std::cout << "" << std::endl;
            rows++;
        }
    }
    //print tile number 1
    std::cout << " 1" << std::endl;
}

void MyGame::setBoardSize(int s){
    boardSize = s;
};

int MyGame::getBoardSize(){
    return boardSize;
};

void MyGame::setMaxTurns(int m){
    maxTurns = m;
};

int MyGame::getMaxTurns(){
    return maxTurns;
};

std::string MyGame::getTile(int index){
    return board[index];
}