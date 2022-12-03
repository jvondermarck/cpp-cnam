#include "puissance4.hpp"

Puissance4::Puissance4(const Player& player1, const Player& player2): 
    Game::Game(player1, player2, 7, 4){}

Puissance4::~Puissance4() {}

void Puissance4::displayBoard()
{
    std::cout << "\nPuissance 4 bord: " << std::endl;
    Game::displayBoard();
}

void Puissance4::dropOffToken(const Player& player)
{
    std::cout << "\n- Player with " << player.colorToString() << " tokens, place your token" << std::endl;

    while (true)
    {
        int column = 0;
        while (true)
        {
            std::cout << "Enter the <y> coordinate : ";
            scanf("%d", &column);
            if (std::cin.fail() || column < 1 || column > this->columnSize) {
                std::cout << "--> Error : please enter a valid value !" << std::endl;
                std::cin.clear();
                std::cin.ignore(); // we clear and ignore the failure to restart the loop
                continue; // we start from the beginning of the loop
            } else {
                column--;
                break;
            }
        }

        if (Game::squareGrid[0][column].isEmpty()) // line 0 bc we placetoken from bottom to top so if index 0 is not empty == column full
        {
            int i;
            for(i=this->rowSize-1; i>=0; i--) // start from bottom to top
            {
                if(Game::squareGrid[i][column].isEmpty()){
                    break;
                }
            }
    	    
            Game::squareGrid[i][column].setOccupied();
            Game::squareGrid[i][column].setColorToken(player.getColorToken());
            break;
        } else
        {
            std::cout << "The column is full." << std::endl;
        }
    }
} 

bool Puissance4::isLineVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::rowSize; i++)
    {
        for(int j=0; j<Game::columnSize; j++)
        {
            if(Game::squareGrid[i][j].getToken().getColorToken() == player.getColorToken()) 
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
    for(int i=0; i<Game::columnSize; i++)
    {
        for(int j=rowSize-1; j>=0; j--)
        {
            if(Game::squareGrid[j][i].getToken().getColorToken() == player.getColorToken()) 
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
    for(int i=0; i<Game::rowSize; i++)
    {
        for(int j=0; j<Game::columnSize; j++)
        {
            if(Game::squareGrid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                // check diagonal going to the right
                for(int diagonal=1; diagonal<4; diagonal++)
                {
                    if(i+diagonal < 0 ||  i+diagonal >= Game::rowSize || j+diagonal < 0 ||  j+diagonal >= Game::columnSize) { break;}
                    if(Game::squareGrid[i+diagonal][j+diagonal].getToken().getColorToken() == player.getColorToken()){
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
                    if(i+diagonal < 0 ||  i+diagonal >= Game::rowSize || j-diagonal < 0 ||  j-diagonal >= Game::columnSize) { break;}

                    if(Game::squareGrid[i+diagonal][j-diagonal].getToken().getColorToken() == player.getColorToken()){
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