#include "game.hpp"

Game::Game(const Player& player1, const Player& player2, int line, int column): player_one(player1), player_two(player2)
{
    this->x_total_square = line;
    this->y_total_square = column;
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
    Token token = this->askDropToken(player);
    this->dropOffToken(token);
}

Token Game::askDropToken(const Player& player)
{
    int line = -1;
    int column = -1;
    std::cout << "\n- Player with " << player.colorToString() << " tokens, place your token" << std::endl;

    while (true)
    {
        while (line > this->x_total_square || line < 1)
        {
            std::cout << "Enter the x coordinate : ";
            std::cin >> line;
        }

        line--; // bc we start at index 0

        while (column > this->y_total_square || column < 1)
        {
            std::cout << "Enter the y coordinate : ";
            std::cin >> column;
        }

        column--;

        if (this->square_grid[line][column].isEmpty())
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

void Game::dropOffToken(const Token& token)
{
    this->square_grid[token.getLine()][token.getColumn()].setOccupied();
    this->square_grid[token.getLine()][token.getColumn()].setToken(token);
    this->displayBoard();
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