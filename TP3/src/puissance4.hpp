#ifndef PUISSANCE_4_HPP
#define PUISSANCE_4_HPP

#include <iostream>
#include "game.hpp"

/**
 * @brief Create a Grid
 */
class Puissance4 : public Game {
    public:
        Puissance4(const Player& player1, const Player& player2);
        ~Puissance4() override;
        
        void dropOffToken(const Player& player) override;
        void displayBoard() override;
        
        bool isLineVictory(const Player& player) override;
        bool isColumnVictory(const Player& player) override;
        bool isDiagonalVictory(const Player& player) override;
};

#endif