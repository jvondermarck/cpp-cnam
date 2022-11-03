#include <iostream>

#include "token.hpp"
#include "player.hpp"
#include "game.hpp"
#include "morpion.hpp"

int main()
{
    Player player1(ColorToken::WHITE);
    Player player2(ColorToken::BLACK);
    Morpion game (player1, player2);
    
    bool player1Playing = true;
    while(true)
    {
        Player actualPlayer = player1;
        if(!player1Playing){
            actualPlayer = player2;
        }

        game.playRound(actualPlayer);
        if(game.isGameOver(actualPlayer)){
            std::cout << "GAME OVER\n" << std::endl;
            break;
        }

        player1Playing = !player1Playing;
    }
    return 0;
}