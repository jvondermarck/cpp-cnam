#include <iostream>

#include "token.hpp"
#include "player.hpp"
#include "game.hpp"
#include "morpion.hpp"
#include "puissance4.hpp"

int main()
{
    Player player1(ColorToken::WHITE);
    Player player2(ColorToken::BLACK);

    char chooseGame;
    while(true)
    {
        while((chooseGame != 'm') && (chooseGame != 'p') && (chooseGame != 'q')){
            std::cout << "Play morpion (m) ? Puissance 4 (p) ? Quit (q) ? : ";
            std::cin >> chooseGame;
        }
        if(chooseGame == 'q'){
            std::cout << "Good bye !" << std::endl;
            exit(0);
        } else if(chooseGame == 'p') {
            Puissance4 game (player1, player2);
            game.playGame();
        } else{
            Morpion game (player1, player2);
            game.playGame();
        }
        
    }
    
    return 0;
}