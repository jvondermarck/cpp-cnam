#ifndef GRID_HPP
#define GRID_HPP

#include "token.hpp"

/**
 * @brief Enumeration which determine a state of a specific square
 * Empty means that there is no token on the square
 * Occupied means that there is a token on the square
 */
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

    /**
     * @brief Check whereas the square is empty
     * 
     * @return true the square is empty so there is no token
     * @return false 
     */
    bool isEmpty() const;

    /**
     * @brief Check if the square is occupied 
     * 
     * @return true the square has a token 
     * @return false 
     */
    bool isOccupied() const;

    /**
     * @brief Set the square state to empty (no token on it anymore)
     */
    inline void setEmpty() { this->state_square = State::EMPTY; }

    /**
     * @brief Set the square state to occupied (there is a token)
     */
    inline void setOccupied() { this->state_square = State::OCCUPIED; }

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
    /**
     * @brief The token object that contains
     */
    Token token_square;
    /**
     * @brief The state of the square on the board game (occupied/empty)
     */
    State state_square;
};


#endif 