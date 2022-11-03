#include "morpion.hpp"

Morpion::Morpion(const Player& player1, const Player& player2): player_one(player1), player_two(player2)
{
    this->initGame();
}

Morpion::~Morpion() {}

void Morpion::initGame()
{
    this->initBoard();
    this->displayBoard();
}

void Morpion::initBoard()
{
    for(int i=0; i<this->x_total_square; i++)
    {
        for(int j=0; j<this->y_total_square; j++)
        {
            this->square_grid[i][j] = Square(Token(ColorToken::EMPTY, i, j), State::EMPTY);
        }
    }
}

void Morpion::displayBoard()
{
    std::cout << "\nMorpion bord: " << std::endl;
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

void Morpion::playRound(const Player& player)
{
    Token token = this->askDropToken(player);
    this->dropOffToken(token);
}

Token Morpion::askDropToken(const Player& player)
{
    int line = -1;
    int column = -1;
    std::cout << "\n- Player with " << player.colorToString() << " tokens, place your token" << std::endl;

    while (true)
    {
        while (line > 2 || line < 0)
        {
            std::cout << "Enter the x coordinate : ";
            std::cin >> line;
        }

        while (column > 2 || column < 0)
        {
            std::cout << "Enter the y coordinate : ";
            std::cin >> column;
        }

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

void Morpion::dropOffToken(const Token& token)
{
    this->square_grid[token.getLine()][token.getColumn()].setOccupied();
    this->square_grid[token.getLine()][token.getColumn()].setToken(token);
    this->displayBoard();
}

bool Morpion::isGameOver(const Player& player) 
{
    return isDraw() || isPlayerWon(player);
}


bool Morpion::isDraw()
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

bool Morpion::isPlayerWon(const Player& player)
{
    return isLineFilled(player) || isColumnFilled(player) || isDiagonalFilled(player);
}

bool Morpion::isLineFilled(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<this->x_total_square; i++)
    {
        for(int j=0; j<this->y_total_square; j++)
        {
            if(this->square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
        }
        if(this->y_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }
    return false;
}

bool Morpion::isColumnFilled(const Player& player)
{
    int amountOfToken = 0;
    for(int i=0; i<this->y_total_square; i++)
    {
        for(int j=0; j<this->x_total_square; j++)
        {
            if(this->square_grid[j][i].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
        }
        if(this->x_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }
    return false;
}

bool Morpion::isDiagonalFilled(const Player& player)
{
    int amountOfToken = 0;
    // seek if diagonal filled from top left to bottom right
    for(int i=0; i<this->x_total_square; i++)
    {
        for(int j=0; j<this->y_total_square; j++)
        {
            if(this->square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
            i++;
        }
        if(this->y_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }
    
    // seek if diagonal filled from top right to bottom left
    for(int i=this->x_total_square-1; i>=0; i--)
    {
        for(int j=this->y_total_square-1; j>=0; j--)
        {
            if(this->square_grid[i][j].getToken().getColorToken() == player.getColorToken()) 
            {
                amountOfToken++;
            }
            i--;
        }
        if(this->y_total_square == amountOfToken) return true;
        amountOfToken = 0;
    }

    return false;
}