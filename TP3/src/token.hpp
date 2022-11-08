#ifndef TOKEN_H
#define TOKEN_H

enum class ColorToken : int {
    BLACK = 0,
    WHITE = 1,
    EMPTY = 2
};

/**
 * @brief Position has the coordinate of a specific token on the game
 */
class Token
{
public:
    Token();
    /**
     * @brief Construct a new Token 
     * 
     * @param coord_x : line
     * @param coord_y : column
     */
    Token(const ColorToken& color, const int& line, const int& column);

    /**
     * @brief Destroy the Position object
     */
    ~Token() = default;

    /**
     * @brief Get the Line coordinate of the position of a token on the game
     * 
     * @return int 
     */
    inline int getLine() const {return this->coord_x;}
    
    /**
     * @brief Set the line coordinate 
     * 
     * @param line 
     */
    inline void setLine(int line) { this->coord_x = line;}

    /**
     * @brief Get the column coordinate of the position of a token on the game
     * 
     * @return int 
     */
    inline int getColumn() const {return this->coord_y;}

    /**
     * @brief Set the column coordinate 
     * 
     * @param column 
     */
    inline void setColumn(int column) { this->coord_y = column;}
    
    /**
     * @brief Check if the token has a white color
     * 
     * @return true is white
     * @return false is not white
     */
    bool isWhiteToken() const;

    /**
     * @brief Check if the token has a black color
     * 
     * @return true is black
     * @return false is not black
     */
    bool isBlackToken() const;

    /**
     * @brief Get the Color Token object
     * 
     * @return ColorToken 
     */
    inline ColorToken getColorToken() const {return this->color_token;}
    
    /**
     * @brief Set the Color Token object
     * 
     * @param color 
     */
    inline void setColorToken(const ColorToken &color) { this->color_token = color;}
private:
    ColorToken color_token;
    int coord_x;
    int coord_y;
};

#endif 