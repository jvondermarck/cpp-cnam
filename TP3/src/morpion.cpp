#include "morpion.hpp"

Morpion::Morpion(const Player& player1, const Player& player2): 
    Game::Game(player1, player2, 3, 3) 
    {
        char gamePlayingMode;
        while ((gamePlayingMode != 'y') && (gamePlayingMode != 'n'))
        {
            std::cout << "Playing mode : play with a computer (y/n) ? ";
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

    while(true)
    {
        lineRand = rand() % (this->x_total_square);
        columnRand = rand() % (this->y_total_square);
        std::cout << lineRand << columnRand << std::endl;
        if(Game::square_grid[lineRand][columnRand].isEmpty()){
            Game::square_grid[lineRand][columnRand].setOccupied();
            Game::square_grid[lineRand][columnRand].setColorToken(computerPlayer.getColorToken());
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
        while (line > Game::x_total_square || line < 1)
        {
            std::cout << "Enter the x coordinate : ";
            std::cin >> line;
        }

        while (column > Game::y_total_square || column < 1)
        {
            std::cout << "Enter the y coordinate : ";
            std::cin >> column;
        }
        
        line--; // bc we start at index 0
        column--;

        if (Game::square_grid[line][column].isEmpty())
        {
            Game::square_grid[line][column].setOccupied();
            Game::square_grid[line][column].setColorToken(player.getColorToken());
            break;
        } else {
            std::cout << "The case is occupied. Try again." << std::endl;
        }
    }
} 

bool Morpion::isLineVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::x_total_square; i++)
    {
        for(int j=0; j<Game::y_total_square; j++)
        {
            if(Game::square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
        }
        if(Game::y_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }
    return false;
}

bool Morpion::isColumnVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::y_total_square; i++)
    {
        for(int j=0; j<Game::x_total_square; j++)
        {
            if(Game::square_grid[j][i].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
        }
        if(Game::x_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }
    return false;
}

bool Morpion::isDiagonalVictory(const Player& player)
{
    int amountOfToken = 0;
    // seek if diagonal filled from top left to bottom right
    for(int i=0; i<Game::x_total_square; i++)
    {
        for(int j=0; j<Game::y_total_square; j++)
        {
            if(Game::square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
            i++;
        }
        if(Game::y_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }
    
    // seek if diagonal filled from top right to bottom left
    for(int i=Game::x_total_square-1; i>=0; i--)
    {
        for(int j=Game::y_total_square-1; j>=0; j--)
        {
            if(Game::square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
            i--;
        }
        if(Game::y_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }

    return false;
}