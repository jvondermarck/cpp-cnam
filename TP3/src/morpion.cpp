#include "morpion.hpp"

Morpion::Morpion(const Player& player1, const Player& player2): 
    Game::Game(player1, player2, 3, 3) 
    {
        char gamePlayingMode;
        while ((gamePlayingMode != 'y') && (gamePlayingMode != 'n'))
        {
            std::cout << "\nPlaying mode : play with a computer (y/n) ? ";
            std::cin >> gamePlayingMode;
        }

        if(gamePlayingMode == 'y'){
            std::cout << "You are going to play with a computer" << std::endl;
            this->computerPlayer = player2;
            isComputerPlaying = true;
        } else {
            std::cout << "You are going to play in pairs" << std::endl;
            isComputerPlaying = false;
        }
    }

Morpion::~Morpion() {}

void Morpion::displayBoard()
{
    std::cout << "\nMorpion bord: " << std::endl;
    Game::displayBoard();
}

void Morpion::playRound(const Player& player)
{
    std::cout << "\n-------- MATCH n°" << ++Game::matchRound << " --------";
    if(isComputerPlaying && player.getColorToken() == computerPlayer.getColorToken()){
        this->dropOffTokenComputer();
    } else {
        this->dropOffToken(player);
    }

    Game::displayBoard();
}

void Morpion::dropOffTokenComputer()
{
    srand (time(NULL));
    int lineRand;
    int columnRand;

    std::cout << "\n- Computer with " << computerPlayer.colorToString() << " will place his token : " << std::endl;
    while(true)
    {
        lineRand = rand() % (this->rowSize);
        columnRand = rand() % (this->columnSize);
        if(Game::squareGrid[lineRand][columnRand].isEmpty()){
            Game::squareGrid[lineRand][columnRand].setOccupied();
            Game::squareGrid[lineRand][columnRand].setColorToken(computerPlayer.getColorToken());
            return;
        }
    }
}

void Morpion::dropOffToken(const Player& player)
{
    std::cout << "\n- Player with " << player.colorToString() << " tokens, place your token" << std::endl;

    while (true)
    {
        int line = 0;
        int column = 0;
        while (true)
        {
            std::cout << "Enter the <x,y> coordinates : ";
            scanf("%d,%d",&line, &column);
            if (std::cin.fail() || line < 1 || column < 1 || line > this->rowSize || column > this->columnSize) {
                std::cout << "--> Error : please enter two valid values !" << std::endl;
                std::cin.clear();
                std::cin.ignore(); // we clear and ignore the failure to restart the loop
                continue; // we start from the beginning of the loop
            } else {
                line--; // bc we start at index 0
                column--;
                break;
            }
        }
        
        if (Game::squareGrid[line][column].isEmpty())
        {
            Game::squareGrid[line][column].setOccupied();
            Game::squareGrid[line][column].setColorToken(player.getColorToken());
            break;
        } else {
            std::cout << "The case is occupied. Try again." << std::endl;
        }
    }
} 

bool Morpion::isLineVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::rowSize; i++)
    {
        for(int j=0; j<Game::columnSize; j++)
        {
            if(Game::squareGrid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
        }
        if(Game::columnSize == amountOfToken) return true;
        amountOfToken = 0;
    }
    return false;
}

bool Morpion::isColumnVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::columnSize; i++)
    {
        for(int j=0; j<Game::rowSize; j++)
        {
            if(Game::squareGrid[j][i].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
        }
        if(Game::rowSize == amountOfToken) return true;
        amountOfToken = 0;
    }
    return false;
}


bool Morpion::isDiagonalVictory(const Player& player)
{
    int amountOfToken = 0;
    // seek if diagonal filled from top left to bottom right
    for(int i=0; i<Game::rowSize; i++)
    {
        if(Game::squareGrid[i][i].getToken().getColorToken() == player.getColorToken()) 
        {
            amountOfToken++;
        }
        if(Game::rowSize == amountOfToken) { return true; }
    }
    
    amountOfToken = 0;

    // seek if diagonal filled from top right to bottom left
    for(int i=Game::rowSize-1; i>=0; i--)
    {
        if(Game::squareGrid[2-i][i].getToken().getColorToken() == player.getColorToken()) 
        {
            amountOfToken++;
        }

        if(Game::rowSize == amountOfToken) { return true; }
    }

    return false;
}