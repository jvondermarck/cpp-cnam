#include "puissance4.hpp"

Puissance4::Puissance4(const Player& player1, const Player& player2): 
    Game::Game(player1, player2, 7, 4){}

Puissance4::~Puissance4() {}

void Puissance4::displayBoard()
{
    std::cout << "\nPuissance 4 bord: " << std::endl;
    Game::displayBoard();
}

Token Puissance4::getTokenLocation(const Player& player)
{
    int column = -1;
    std::cout << "\n- Player with " << player.colorToString() << " tokens, place your token" << std::endl;

    while (true)
    {
        while (column > Game::y_total_square || column < 1)
        {
            std::cout << "Enter the number of the column : ";
            std::cin >> column;
        }

        column--; // bc we start at index 0

        if (Game::square_grid[0][column].isEmpty()) // line 0 bc we placetoken from bottom to top so if index 0 is not empty == column full
        {
            int i;
            for(i=this->x_total_square-1; i>=0; i--) // start from bottom to top
            {
                if(Game::square_grid[i][column].isEmpty()){
                    break;
                }
            }
    	    
            Token token = Token(player.getColorToken(), i, column);
            return token;
        } else
        {
            std::cout << "The column is full." << std::endl;
            column = 0;
        }
    }
} 

bool Puissance4::isLineVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::x_total_square; i++)
    {
        for(int j=0; j<Game::y_total_square; j++)
        {
            if(Game::square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
                if(amountOfToken == 4) { return true; }
            } else { // means that player didn't get the 4 tokens in once
                amountOfToken = 0;
            }
        }
        amountOfToken = 0;
    }
    return false;
}

bool Puissance4::isColumnVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::y_total_square; i++)
    {
        for(int j=x_total_square-1; j>=0; j--)
        {
            if(Game::square_grid[j][i].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
                if(amountOfToken == 4) { return true; } 
            } else { // means that player didn't get the 4 tokens in once
                amountOfToken = 0;
            }
        }

        amountOfToken = 0;
    }
    return false;
}

bool Puissance4::isDiagonalVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::x_total_square; i++)
    {
        for(int j=0; j<Game::y_total_square; j++)
        {
            if(Game::square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                // check diagonal going to the right
                for(int diagonal=1; diagonal<4; diagonal++)
                {
                    if(i+diagonal < 0 ||  i+diagonal >= Game::x_total_square || j+diagonal < 0 ||  j+diagonal >= Game::y_total_square) { break;}
                    if(Game::square_grid[i+diagonal][j+diagonal].getToken().getColorToken() == player.getColorToken()){
                        amountOfToken++;
                    } else {
                        amountOfToken = 0;
                        break;
                    }
                }
                
                if(amountOfToken == 4) { return true; } 

                // check diagonal going to the left
                for(int diagonal=1; diagonal<4; diagonal++)
                {
                    if(i+diagonal < 0 ||  i+diagonal >= Game::x_total_square || j-diagonal < 0 ||  j-diagonal >= Game::y_total_square) { break;}

                    if(Game::square_grid[i+diagonal][j-diagonal].getToken().getColorToken() == player.getColorToken()){
                        amountOfToken++;
                    } else {
                        amountOfToken = 0;
                        break;
                    }
                }

                if(amountOfToken == 4) { return true; } 
            } else {
                amountOfToken = 0;
            }
        }

        amountOfToken = 0;
    }

    return false;
}

