#include "square.hpp"

Square::Square() {}
Square::Square(const Token& token, const State& state): token_square(token), state_square(state) {}

bool Square::isOccupied() const
{
    return this->state_square == State::OCCUPIED ? true : false;
}

bool Square::isEmpty() const
{
    return this->state_square == State::EMPTY ? true : false;
}