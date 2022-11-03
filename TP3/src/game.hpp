#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "token.hpp"
#include "player.hpp"
#include "square.hpp"

/**
 * @brief Create a Game
 */
class Game {
    public:
        Game();
        virtual ~Game();
        virtual void initGame() = 0;
        virtual void initBoard() = 0;
        virtual void displayBoard() = 0;
        virtual Token askDropToken(const Player& player) = 0;
        virtual void dropOffToken(const Token& token) = 0;
        virtual void playRound(const Player& player) = 0;
        virtual bool isPlayerWon(const Player& player) = 0;
        virtual bool isDraw() = 0;
        virtual bool isGameOver(const Player& player) = 0;
    private:
};

#endif