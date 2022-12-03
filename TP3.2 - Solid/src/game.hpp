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
        /**
         * @brief Construct a new Game object
         * 
         * @param player1 
         * @param player2 
         * @param line : the number of lines in the board game
         * @param column : the number of columns in the board game
         */
        Game(const Player& player1, const Player& player2, int line, int column);
        
        /**
         * @brief Destroy the Game object
         */
        virtual ~Game();

        /**
         * @brief It will take care of calling the methods to start the game
         */
        void initGame();

        /**
         * @brief It will initialize the board with empty square
         */
        void initBoard();

        /**
         * @brief Display the board to the player in the console
         */
        virtual void displayBoard();

        /**
         * @brief Droping off the token on the board game
         * 
         * @param token 
         */
        virtual void dropOffToken(const Player& player) = 0;

        /**
         * @brief play a round for a player to drop off a token on the game
         * 
         * @param player 
         */
        virtual void playRound(const Player& player);

        /**
         * @brief Check if the player won in the game
         * 
         * @param player 
         * @return true the player won the game
         * @return false the player didn't won the game 
         */
        bool isPlayerWon(const Player& player);

        /**
         * @brief Check if in the board game it's not possible to play anymore so the game is a draw
         * 
         * @return true the game is a drw
         * @return false there is no draw
         */
        bool isDraw();

        /**
         * @brief Will check if there is a draw or if the player won the game
         * 
         * @param player 
         * @return true the game is over so we stop the game
         * @return false the game is not yet finished, so we continue playing
         */
        bool isGameOver(const Player& player);

        /**
         * @brief To simulate a game match between players 
         */
        void playGame();

        virtual bool isLineVictory(const Player& player) = 0;
        virtual bool isColumnVictory(const Player& player) = 0;
        virtual bool isDiagonalVictory(const Player& player) = 0;

        /**
         * @brief Check if two Players are equal by comparing they ColorToken
         * 
         * @param player : our player
         * @param playerCompare : the second player that we want to check the equality with the first
         * @return true the two Players are equal
         * @return false the players are not equal
         */
        friend bool operator==(const Player& player, const Player& playerCompare);
        // note for myself : A friend class can access private and protected members of other class in which it is declared as friend.
    protected:
        std::vector<std::vector<Square>> squareGrid; // 2D vector array that don't need a specific size array at instiantiation
        const Player playerOne;
        const Player playerTwo;
        const int rowSize;
        const int columnSize;
        int matchRound;
};

#endif