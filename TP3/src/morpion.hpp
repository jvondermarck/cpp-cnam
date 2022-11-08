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

        void playRound(const Player& player) override;
        Token getTokenLocationComputer();
        Token getTokenLocation(const Player& player) override;
        void displayBoard() override;

        bool isLineVictory(const Player& player) override;
        bool isColumnVictory(const Player& player) override;
        bool isDiagonalVictory(const Player& player) override;
    private:
        bool isComputerPlaying;
        Player computerPlayer;
};

#endif