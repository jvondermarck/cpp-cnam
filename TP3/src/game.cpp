#include "game.hpp"

Game::Game(const Player& player1, const Player& player2, int line, int column): 
    playerOne(player1), playerTwo(player2),
    rowSize(line), columnSize(column)
{
    this->squareGrid.resize(this->rowSize, std::vector<Square>(this->columnSize));
    
    this->matchRound = 0;
    this->initGame();

    if(this->playerOne.getColorToken() == ColorToken::BLACK){
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
    std::cout << "\nBord game has been initialized ! Good luck !" << std::endl;
    for(int i=0; i<this->rowSize; i++)
    {
        for(int j=0; j<this->columnSize; j++)
        {
            this->squareGrid[i][j] = Square(Token(ColorToken::EMPTY, i, j), State::EMPTY);
        }
    }

}

void Game::displayBoard()
{
    for(int i=0; i<this->columnSize; i++) { std::cout << "----"; }

    for(int i=0; i<this->rowSize; i++)
    {
        std::cout << "-\n|";
        for(int j=0; j<this->columnSize; j++)
        {
            if(this->squareGrid[i][j].isEmpty())
            {
                std::cout << " - ";
            } else {
                if (this->squareGrid[i][j].getToken().isBlackToken())
                {
                    std::cout << " X ";
                }
                else if (this->squareGrid[i][j].getToken().isWhiteToken())
                {
                    std::cout << " O ";
                }
            }
            std::cout << "|";
        }
        std::cout << "\n";
        for(int i=0; i<this->columnSize; i++) { std::cout << "----"; }
    }
    std::cout << "-\n";
}

void Game::playRound(const Player& player)
{
    std::cout << "\n-------- MATCH n°" << ++matchRound << " --------";
    this->dropOffToken(player);
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
    for(int i=0; i<this->rowSize; i++)
    {
        for(int j=0; j<this->columnSize; j++)
        {
            if(this->squareGrid[i][j].isEmpty()) // means if something a square is still empty = not the end
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
    Player actualPlayer = this->playerOne;
    while(true)
    {
        this->playRound(actualPlayer);
        if(this->isGameOver(actualPlayer)){
            std::cout << "\nGAME OVER" << std::endl;
            if(this->isDraw()){
                std::cout << "DRAW MATCH" << std::endl;
            } else if(isPlayerWon(actualPlayer)) {
                std::cout << "Player won with the " << actualPlayer.colorToString() << " tokens. Congrats.\n"<< std::endl;
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
        actualPlayer = (actualPlayer == this->playerOne) ? this->playerTwo : this->playerOne;
    }
}