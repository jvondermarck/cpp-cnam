#include "morpion.hpp"

Morpion::Morpion(const Player& player1, const Player& player2): 
    Game::Game(player1, player2, 3, 3) {}

Morpion::~Morpion() {}

void Morpion::displayBoard()
{
    std::cout << "\nMorpion bord: " << std::endl;
    Game::displayBoard();
}

Token Morpion::getTokenLocation(const Player& player)
{
    int line = -1;
    int column = -1;
    std::cout << "\n- Player with " << player.colorToString() << " tokens, place your token" << std::endl;

    while (true)
    {
        while (line > Game::x_total_square || line < 1)
        {
            std::cout << "Enter the x coordinate : ";
            std::cin >> line;
        }

        line--; // bc we start at index 0

        while (column > Game::y_total_square || column < 1)
        {
            std::cout << "Enter the y coordinate : ";
            std::cin >> column;
        }

        column--;

        if (Game::square_grid[line][column].isEmpty())
        {
            Token token = Token(player.getColorToken(), line, column);
            return token;
        } else
        {
            std::cout << "The case is occupied. Try again." << std::endl;
            line = 0;
            column = 0;
        }
    }
} 

bool Morpion::isGameOver(const Player& player) 
{
    return Game::isDraw() || isPlayerWon(player);
}

bool Morpion::isPlayerWon(const Player& player)
{
    return isLineFilled(player) || isColumnFilled(player) || isDiagonalFilled(player);
}

bool Morpion::isLineFilled(const Player& player)
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

bool Morpion::isColumnFilled(const Player& player)
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

bool Morpion::isDiagonalFilled(const Player& player)
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