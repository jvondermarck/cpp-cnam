#ifndef MORPION_HPP
#define MORPION_HPP

#include <iostream>
#include "square.hpp"
#include "token.hpp"
#include "game.hpp"
#include "player.hpp"

/**
 * @brief Create a Grid
 */
class Morpion : public Game {
    public:
        Morpion(const Player& player1, const Player& player2);
        ~Morpion() override;
        void initGame() override;
        void initBoard() override;
        void displayBoard() override;
        void dropOffToken(const Token& token) override;
        Token askDropToken(const Player& player) override;
        void playRound(const Player& player) override;
        bool isDraw() override;
        bool isPlayerWon(const Player& player) override;
        bool isGameOver(const Player& player) override;

        bool isLineFilled(const Player& player);
        bool isColumnFilled(const Player& player);
        bool isDiagonalFilled(const Player& player);
        
    private:
        Square square_grid[3][3];
        const Player player_one;
        const Player player_two;
        const int x_total_square = 3;
        const int y_total_square = 3;
};

#endif