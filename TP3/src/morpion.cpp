#include "morpion.hpp"

Morpion::Morpion(const Player& player1, const Player& player2): Game::Game(player1, player2, 3, 3){}

Morpion::~Morpion() {}

void Morpion::displayBoard()
{
    std::cout << "\nMorpion bord: " << std::endl;
    Game::displayBoard();
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