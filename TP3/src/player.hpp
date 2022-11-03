#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "token.hpp"
#include <string>

/**
 * @brief Create a Player
 */
class Player {
    public:
        Player();
        Player(const ColorToken& color);
        ~Player() = default;

        ColorToken getColorToken() const { return this->color_token; }
        std::string colorToString() const;
    private:
        ColorToken color_token;
};

#endif