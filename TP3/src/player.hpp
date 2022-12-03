#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "token.hpp"

/**
 * @brief Create a Player
 */
class Player {
    public:
        Player();
        /**
         * @brief Construct a new Player object
         * 
         * @param color the Token Color enumeration
         */
        Player(const ColorToken& color);

        /**
         * @brief Destroy the Player object
         */
        ~Player() = default;

        /**
         * @brief Get the Color Token enumeration
         * 
         * @return ColorToken 
         */
        ColorToken getColorToken() const { return this->color_token; }
        
        /**
         * @brief Convert the color token enumeration in string
         * 
         * @return string 
         */
        std::string colorToString() const;
    private:
        ColorToken color_token;
};

#endif