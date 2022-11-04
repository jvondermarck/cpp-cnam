#ifndef PUISSANCE_4_HPP
#define PUISSANCE_4_HPP

#include <iostream>

/**
 * @brief Create a Grid
 */
class Puissance4 : public Game {
    public:
        Puissance4(const Player& player1, const Player& player2);
        ~Puissance4() override;
        
        void displayBoard() override;
        bool isPlayerWon(const Player& player) override;
        bool isGameOver(const Player& player) override;

        bool isLinePlayerVictory(const Player& player);
        bool isColumnPlayerVictory(const Player& player);
        bool isDiagonalPlayerVictory(const Player& player);
};

#endif