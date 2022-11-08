#include "game.hpp"

Game::Game(const Player& player1, const Player& player2, int line, int column): 
    player_one(player1), player_two(player2),
    x_total_square(line), y_total_square(column)
{
    this->square_grid.resize(this->x_total_square, std::vector<Square>(this->y_total_square));
    
    this->initGame();

    if(this->player_one.getColorToken() == ColorToken::BLACK){
        std::cout << "- Player 1 : you have the black color and we give you the 'X' token." << std::endl;
        std::cout << "- Player 2 : you have the white color and we give you the 'O' token." << std::endl;
    } else {
        std::cout << "- Player 1 : you have the white color and we give you the 'O' token." << std::endl;
        std::cout << "- Player 2 : you have the black color and we give you the 'X' token." << std::endl;
    }
}

Game::~Game() {}

void Game::initGame()
{
    this->initBoard();
    this->displayBoard();
}

void Game::initBoard()
{
    for(int i=0; i<this->x_total_square; i++)
    {
        for(int j=0; j<this->y_total_square; j++)
        {
            this->square_grid[i][j] = Square(Token(ColorToken::EMPTY, i, j), State::EMPTY);
        }
    }

}

void Game::displayBoard()
{
    std::cout << "-------------\n";
    for(int i=0; i<this->x_total_square; i++)
    {
        std::cout << "|";
        for(int j=0; j<this->y_total_square; j++)
        {
            if(this->square_grid[i][j].isEmpty())
            {
                std::cout << " - ";
            } else {
                if (this->square_grid[i][j].getToken().isBlackToken())
                {
                    std::cout << " X ";
                }
                else if (this->square_grid[i][j].getToken().isWhiteToken())
                {
                    std::cout << " O ";
                }
            }
            std::cout << "|";
        }
        std::cout << "\n-------------\n";
    }
}

void Game::playRound(const Player& player)
{
    Token token = this->getTokenLocation(player);
    this->dropOffToken(token);
}

void Game::dropOffToken(const Token& token)
{
    this->square_grid[token.getLine()][token.getColumn()].setOccupied();
    this->square_grid[token.getLine()][token.getColumn()].setToken(token);
    this->displayBoard();
}

bool Game::isGameOver(const Player& player) 
{
    return isDraw() || isPlayerWon(player);
}

bool Game::isPlayerWon(const Player& player)
{
    return isLineVictory(player) || isColumnVictory(player) || isDiagonalVictory(player);
}

bool Game::isDraw()
{
    for(int i=0; i<this->x_total_square; i++)
    {
        for(int j=0; j<this->y_total_square; j++)
        {
            if(this->square_grid[i][j].isEmpty()) // means if something a square is still empty = not the end
            {
                return false;
            }
        }
    }
    return true;
}


bool operator==(const Player& player, const Player& playerCompare)
{
   return player.getColorToken() == playerCompare.getColorToken();
}

void Game::playGame()
{
    Player actualPlayer = this->player_one;
    while(true)
    {
        this->playRound(actualPlayer);
        if(this->isGameOver(actualPlayer)){
            std::cout << "GAME OVER\n" << std::endl;
            if(this->isDraw()){
                std::cout << "DRAW MATCH" << std::endl;
            } else if(isPlayerWon(actualPlayer)) {
                std::cout << "Player won with the " << actualPlayer.colorToString() << " tokens. Congrats."<< std::endl;
            }

            char playAgain;
            while((playAgain != 'y') && (playAgain != 'n')){
                std::cout << "Do you wanna play again ? y/n ";
                std::cin >> playAgain;
            }

            if(playAgain == 'y'){
                std::cout << "We restart the game !" << std::endl;
                this->initBoard();
                this->playGame();
            } else {
                std::cout << "Good bye!" << std::endl;
                exit(0);
            }
        }

        // we change the actual player
        actualPlayer = (actualPlayer == this->player_one) ? this->player_two : this->player_one;
    }
}