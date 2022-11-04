#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include "token.hpp"
#include "player.hpp"
#include "square.hpp"

/**
 * @brief Create a Game
 */
class Game {
    public:
        Game(const Player& player1, const Player& player2, int line, int column);
        virtual ~Game();
        void initGame();
        void initBoard();
        virtual void displayBoard();
        Token askDropToken(const Player& player);
        void dropOffToken(const Token& token);
        void playRound(const Player& player);
        virtual bool isPlayerWon(const Player& player) = 0;
        bool isDraw();
        virtual bool isGameOver(const Player& player) = 0;
    protected:
        std::vector<std::vector<Square>> square_grid; // 2D vector array that don't need a specific size array at instiantiation
        const Player player_one;
        const Player player_two;
        int x_total_square;
        int y_total_square;
};

#endif