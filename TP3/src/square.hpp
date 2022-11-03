#ifndef GRID_HPP
#define GRID_HPP

#include "token.hpp"

enum class State : int {
  EMPTY = 0,
  OCCUPIED = 1,
};

class Square 
{
  public:

    Square();
    /**
     * @brief Construct a new Square object
     * 
     * @param token : position of the token on the game
     * @param state : the actual state of the token
     */
    Square(const Token& token, const State& state);

    /**
     * @brief Destroy the State object
     */
    ~Square() = default;

    bool isEmpty() const;
    bool isOccupied() const;
    void setEmpty();
    void setOccupied();

    /**
     * @brief Get the State object
     * 
     * @return State 
     */
    inline State getState() const { return this->state_square; }

    /**
     * @brief Set the State object
     * 
     * @param state 
     */
    inline void setState(const State state) { this->state_square = state; }

    /**
     * @brief Get the Position object
     * 
     * @return Position 
     */
    inline Token getToken() const { return this->token_square; }

    /**
     * @brief Set the Position object
     * 
     * @param token 
     */
    inline void setToken(const Token& token) { this->token_square = token; }
  private:
    Token token_square;
    State state_square;
};


#endif 