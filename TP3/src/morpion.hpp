#ifndef MORPION_HPP
#define MORPION_HPP

#include <iostream>
#include <vector>
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

        void displayBoard() override;
        bool isPlayerWon(const Player& player) override;
        bool isGameOver(const Player& player) override;

        bool isLineFilled(const Player& player);
        bool isColumnFilled(const Player& player);
        bool isDiagonalFilled(const Player& player);
};

#endif