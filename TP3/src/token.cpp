#include "token.hpp"

Token::Token() {}
Token::Token(const ColorToken& color, const int& line, const int& column): 
    color_token(color), coord_x(line), coord_y(column) {}

bool Token::isWhiteToken() const
{
    return this->color_token == ColorToken::WHITE ? true : false;
}

bool Token::isBlackToken() const
{
    return this->color_token == ColorToken::BLACK ? true : false;
}
