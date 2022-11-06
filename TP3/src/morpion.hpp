#ifndef MORPION_HPP
#define MORPION_HPP

#include <iostream>
#include "game.hpp"

/**
 * @brief Create a Grid
 */
class Morpion : public Game {
    public:
        Morpion(const Player& player1, const Player& player2);
        ~Morpion() override;

        Token getTokenLocation(const Player& player) override;
        void displayBoard() override;
        bool isPlayerWon(const Player& player) override;
        bool isGameOver(const Player& player) override;

        bool isLineFilled(const Player& player);
        bool isColumnFilled(const Player& player);
        bool isDiagonalFilled(const Player& player);
};

#endif