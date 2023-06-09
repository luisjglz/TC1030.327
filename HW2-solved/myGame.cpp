#include "MyGame.h"
#include "Die.h"
#include <iostream>

MyGame::MyGame(int bs, char** vals)
{
    gameOver = false;
    //Board Size
    if (bs > 1)
    {
        //First, set everything as default and then replace with the obtained parameters
        //Setup game with default options
        setDefaults();
        
        // 0=filname, 1=board size, 2=num snakes, 3=num ladders, 4=penalty, 5=reward, 6=Num players, 7=Max turns, 8=Game type
        // ./game 40 4 4 -3 3 4 30 A
        if(bs > 1){
            //2 parameters... e.g.: ./game 30
            setBoardSize(std::stoi(vals[1]));
        }
        if(bs > 2){
            //3 parameters... e.g.: ./game 30 3
            setNumSnakes(std::stoi(vals[2]));
        }
        if(bs > 3){
            setNumLadders(std::stoi(vals[3]));
        }
        if(bs > 4){
            setPenaltySnakes(std::stoi(vals[4]));
        }
        if(bs > 5){
            setRewardLadder(std::stoi(vals[5]));
        }
        if(bs > 6){
            setNumPlayers(std::stoi(vals[6]));
        }
        if(bs > 7){
            setMaxTurns(std::stoi(vals[7]));
        }
        if(bs > 8){
            setGameType(vals[8]);
        }
    }
    else
    {
        //preguntar si quiere juego default o personalizar....
        std::string res;
        std::cout << "Default game (D). Custom game (C)" << std::endl;
        std::cin >> res;
        while(res != "D" && res != "C"){
            std::cout << "Please enter a valid option:" << std::endl;
            std::cout << "Default game (D). Custom game (C)" << std::endl;
            std::cin >> res;
        }
        if(res == "D"){
            //Setup game with default options
            setDefaults();
        }
        else if(res == "C"){
            //Customize game, option by option:
            //Board size
            std::cout << "Enter the number of tiles:" << std::endl;
            std::cin >> res;
            setBoardSize(std::stoi(res));
            //Number of snakes:
            std::cout << "Enter the number of snakes:" << std::endl;
            std::cin >> res;
            setNumSnakes(std::stoi(res));
            // 0=filname, 1=board size, 2=num snakes, 3=num ladders, 4=penalty, 5=reward, 6=Num players, 7=Max turns, 8=Game type
            //Number of ladders:
            std::cout << "Enter the number of ladders:" << std::endl;
            std::cin >> res;
            setNumLadders(std::stoi(res));
            //Penalty:
            std::cout << "Enter the penalty for snakes:" << std::endl;
            std::cin >> res;
            setPenaltySnakes(std::stoi(res));
            //Reward:
            std::cout << "Enter the reward for the ladders:" << std::endl;
            std::cin >> res;
            setRewardLadder(std::stoi(res));
            //Number of players:
            std::cout << "Enter the number of players:" << std::endl;
            std::cin >> res;
            setNumPlayers(std::stoi(res));
            //Max turns:
            std::cout << "Enter the max number of turns:" << std::endl;
            std::cin >> res;
            setMaxTurns(std::stoi(res));
            //Game type:
            std::cout << "Game type. (A) Automatic. (M) Manual." << std::endl;
            std::cin >> res;
            setGameType(res);
        }; 
    };
};

void MyGame::start()
{
    std::cout << "Setting up game" << std::endl;

    //Fill the board with normal tiles:
    for (int i = 1; i < getBoardSize() + 1; i++)
    {
        NormalTile nt;
        board.push_back(&nt);
    }

    // create numSnakes snakes at random positions:
    // snakes can't be in tiles 1,2,3,...,penaltySnakes
    int totsnakes = getNumSnakes();
    while (totsnakes > 0)
    {
        int random_tile = (rand() % (getBoardSize()+getPenaltySnakes())) + getPenaltySnakes()*-1;
        if (random_tile > getPenaltySnakes()*-1 && random_tile < (getBoardSize() + getPenaltySnakes()) && board[random_tile]->getType() != "S" && board[random_tile]->getType() != "L")
        {
            //Create temp snake and replace the tile with it:
            Snake s;
            board[random_tile] = & s;
            totsnakes--;
        }
    }


    // create 3 random ladders
    // ladders can't be in tiles 1,...,boardSize - reward
    int totladders = 3;
    while (totladders > 0)
    {
        int random_tile = (rand() % (getBoardSize()-getRewardLadder())) + 1;
        if (random_tile > 1 && random_tile < (getBoardSize()-getRewardLadder()) && board[random_tile]->getType() != "L" && board[random_tile]->getType() != "S")
        {
            //Create temp ladder and replace the tile with it:
            Ladder l;
            board[random_tile] = & l;
            totladders--;
        }
    }

    //Create players:
    for(int i = 1; i <= getNumPlayers(); i++){
        Player * p = new Player;
        p->setName(std::to_string(i));
        p->setPos(1);
        players.push_back(p);
    }
    for(int i = 0; i < players.size(); i++){
        std::cout << "PLAYER " << players[i]->getName() << std::endl;
    }


    //Check if the game is automatic or manual:
    if(getGameType()=="A"){
        //automatic mode selected in command line
        play("A");   
    }
    else{
        std::string res;
        std::cout << "Automatic mode (A). Manual mode (M)" << std::endl;
        std::cin >> res;

        while(res != "A" && res != "M"){
            std::cout << "Please enter a valid option:";
            std::cout << "Automatic mode (A). Manual mode (M)";
            std::cin >> res;
        }

        play(res);
    }

    
}

void MyGame::doTurn(Player &player)
{
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    // We get a reference to the player object in '& player'

    // Roll de die:
    Die die;
    int rollDie;
    rollDie = die.roll();

    std::cout << "It's player: " << player.getName() << " turn. Player " << player.getName() << " is in tile: " << player.getPos() << std::endl;
    std::cout << "Player " << player.getName() << " rolled the die and got a: " << rollDie << std::endl;
    std::cout << "Player " << player.getName() << " landed on tile " << player.getPos() + rollDie << " which is a " << board[player.getPos() + rollDie]->getType() << " tile." << std::endl;
    if ( board[player.getPos() + rollDie]->getType() == "S")
    {
        // snake tile back 3 tiles:
        player.setPos((player.getPos() + rollDie) - 3);
    }
    else if ( board[player.getPos() + rollDie]->getType() == "L")
    {
        // ladder tile forward 3 tiles:
        player.setPos((player.getPos() + rollDie) + 3);
    }
    else if ( board[player.getPos() + rollDie]->getType() == "N")
    {
        // normal tile, update pos:
        player.setPos(player.getPos() + rollDie);
    }

    std::cout << "Player " << player.getName() << " final position is: " << player.getPos() << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    
    // Check for win
    if (player.getPos() + rollDie >= getBoardSize())
    {
        // Reset position
        player.setPos(getBoardSize());
        // Win!
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Player " << player.getName() << " won!!!" << std::endl;
        // Finish program execution
        gameOver = true;
        
        return;
    }

    printBoard(players);

}

void MyGame::printBoard(std::vector<Player *> & players)
{

    // prints the board in a snake & ladders style:
    int rows = 1, currenttile = getBoardSize();
    int tiles;
    std::string line = "";
    // print last tile number
    std::cout << getBoardSize() << std::endl;
    for (int i = getBoardSize() - 1; i >= 0; i--)
    {
        if (rows % 2 == 1)
        { // odd row

            // check for players in tile:
            int totPlayersInPos = 0;
            std::string playerID;
            for(Player * p : players){
                if (p->getPos() - 1 == i)
                {
                    totPlayersInPos++;
                    playerID = p->getName();
                }
            }
            if(totPlayersInPos==0){
                std::cout << "[" << board.at(i)->getType() << "]"; //board.at(i) is the same as board[i]
            }
            else if(totPlayersInPos==1){
                std::cout << "[" << playerID << "]";
            }
            else if(totPlayersInPos>1){
                std::cout << "[*]";
            }
            currenttile--;
        }
        if (rows % 2 == 0)
        { // even row,
            // print tiles in increasing order
            // reset line:
            line = "";
            tiles = 0;
            while (tiles < 5)
            {
                // check for players in tile:
                int totPlayersInPos = 0;
                std::string playerID;
                for(Player * p : players){
                    if (p->getPos() - 1 == i)
                    {
                        totPlayersInPos++;
                        playerID = p->getName();
                    }
                }
                if(totPlayersInPos==0){
                    line = ("[" + board.at(i)->getType() + "]") + line;
                }
                else if(totPlayersInPos==1){
                    line = ("[" + playerID + "]") + line;
                }
                else if(totPlayersInPos>1){
                    line = ("[*]") + line;
                }
                i--;
                tiles++;
            }
            currenttile -= 5;
            i++;
            std::cout << line;
        }
        if (currenttile % 5 == 0)
        { // print an enter every 5 tiles
            std::cout << "" << std::endl;
            rows++;
        }
    }
    // print tile number 1
    std::cout << " 1" << std::endl;
}

void MyGame::setBoardSize(int s)
{
    boardSize = s;
};

int MyGame::getBoardSize()
{
    return boardSize;
};

void MyGame::setMaxTurns(int m)
{
    maxTurns = m;
};

int MyGame::getMaxTurns()
{
    return maxTurns;
};

int MyGame::getNumPlayers()
{
    return numPlayers;
};

void MyGame::setNumPlayers(int n){
    numPlayers = n;
}

int MyGame::getNumSnakes()
{
    return numSnakes;
};

void MyGame::setNumSnakes(int s)
{
    numSnakes = s;
};

int MyGame::getNumLadders()
{
    return numLadders;
};

void MyGame::setNumLadders(int l)
{
    numLadders = l;
};

int MyGame::getPenaltySnakes()
{
    return penaltySnakes;
};

void MyGame::setPenaltySnakes(int p)
{
    penaltySnakes = p;
};

int MyGame::getRewardLadder()
{
    return rewardLadder;
};

void MyGame::setRewardLadder(int r)
{
    rewardLadder = r;
};

std::string MyGame::getGameType()
{
    return gameType;
};

void MyGame::setGameType(std::string g)
{
    gameType = g;
};

void MyGame::setDefaults(){
    setBoardSize(30);
    setNumSnakes(3);
    setNumLadders(3);
    setPenaltySnakes(-3);
    setRewardLadder(3);
    setNumPlayers(2);
    setMaxTurns(boardSize/2);
    setGameType("M");
}

void MyGame::play(std::string t){
    //Get most advanced position
    int maxPos = -1;
    for(int i = 0; i < getNumPlayers(); i++){
        if(players[i]->getPos() > maxPos){
            maxPos = players[i]->getPos();
        }
    }
    
    while(maxPos < getBoardSize() && !gameOver){
        //No one has won yet, continue playing

        //Call turns for each player:
        for(int i = 0; i < getNumPlayers(); i++){
            Player* p = players[i];

            if(t=="M"){
                //manual mode, wait for user confirmation
                std::cout << "Press (C) to continue or (E) to exit" << std::endl;
                std::string res;
                std::cin >> res;
                while(res != "C" && res != "E"){
                    std::cout << "Press (C) to continue or (E) to exit" << std::endl;
                    std::cin >> res;
                }
                if(res == "E"){
                    gameOver = true;
                    printBoard(players);
                    break;
                }
            }



            doTurn(*p);
            if(gameOver){
                printBoard(players);
                break;
            }
        }

        //Check positions:
        for(int i = 0; i < getNumPlayers(); i++){
            if(players[i]->getPos() > maxPos){
                maxPos = players[i]->getPos();
            }
        }
    }
}