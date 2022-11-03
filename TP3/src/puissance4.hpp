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
        void initGame() override;
        void initBoard() override;
        void displayBoard() override;
        void dropOffToken() override;
        void playRound() override;
        Token askDropToken() override;
        bool isDraw() override;
        bool isPlayerWon(const Player& player) override;
        bool isGameOver(const Player& player) override;

        bool isLineFilled();
        bool isColumnFilled();
        bool isDiagonalFilled();
        
    private:
        
};

#endif