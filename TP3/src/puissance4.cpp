#include "puissance4.cpp"

Puissance4::Puissance4(const Player& player1, const Player& player2): Game::Game(player1, player2, 7, 4){}{}

Puissance4::~Puissance4() {}

void Puissance4::displayBoard()
{
    std::cout << "\nPuissance 4 bord: " << std::endl;
    Game::displayBoard();
}

bool Puissance4::isGameOver(const Player& player)
{
    return Game::isDraw() || isPlayerWon(player);
}

bool Morpion::isPlayerWon(const Player& player)
{
    return isLinePlayerVictory(player) || isColumnPlayerVictory(player) || isDiagonalPlayerVictory(player);
}

bool Puissance4::isLinePlayerVictory(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<Game::x_total_square; i++)
    {
        for(int j=Game::y_total_square-1; j>=0; j--)
        {
            if(Game::square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
                if(amountOfToken == 4) { return true; }
                else{ // means that player didn't get the 4 tokens in once
                    amountOfToken = 0;
                }
        }
        
        amountOfToken = 0;
    }
    return false;
}

bool Puissance4::isColumnPlayerVictory(const Player& player)
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
                else{ // means that player didn't get the 4 tokens in once
                    amountOfToken = 0;
                }
            }
        }

        amountOfToken = 0;
    }
    return false;
}

bool Puissance4::isDiagonalPlayerVictory(const Player& player)
{

}

