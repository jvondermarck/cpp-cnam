#include "Player.hpp"

Player::Player() {}
Player::Player(const ColorToken& color): color_token(color) {}

std::string Player::colorToString() const
{
    std::string color = "";
    if(color_token == ColorToken::BLACK){
        color = "Black";
    } else {
        color = "White";
    }
    return color;
}