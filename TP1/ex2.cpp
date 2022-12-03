#include <iostream>
#include <cstdlib>

// function that just increment score to a player
void add_score(int &score) {
    if(score == 30) {
        score = 40;
    } else {
        score += 15;
    }  
}

void play_game(int &score_player1, int &score_player2) {
    srand((unsigned) time(0));
    int number_matches = 0;

    while(true) {
        std::cout << "--> Match number : " << ++number_matches << std::endl;
        int winner = (rand() % 2); // rand value between 0 and 1 that determine either player1 or player2 won

        // if both players have equality
        if(score_player1 == 40 && score_player2 == 40) { // if equality
            while(true) {
                std::cout << "Egalite ! Echange decisif. " << std::endl;
                int advantage_matchOne = (rand() % 2); // randomly decide whereas player1 or player2 get the ball advantage in a match
                if(advantage_matchOne == 0) {
                    std::cout << " -> Le joueur 1 gagne la balle de jeu !" << std::endl;
                } else {
                    std::cout << " -> Le joueur 2 gagne la balle de jeu !" << std::endl;
                }

                int matchTwo = (rand() % 2); // second match decisive to determine if we game is over or there is still hope

                if(matchTwo == 0 && advantage_matchOne == 0) { //if player1 won this match and got the advantage, he won the game
                    std::cout << "WINNER : Le gagnant est le joueur 1 !" << std::endl;
                    return;
                } else if(matchTwo == 1 && advantage_matchOne == 1) { //if player2 won this match and got the advantage, he won the game
                    std::cout << "WINNER : Le gagnant est le joueur 2 !" << std::endl;
                    return;
                } else { // otherwise it means that it's the player who didn't get the advantage who won, so they're still on equality
                    std::cout << "Vous etes a egalite encore !\n" << std::endl;
                }
            }
        } else if(score_player1 == 40 && winner==0) { // if player1 has a score of 40 and player2 a score less than 40 = player 1 won
            std::cout << "WINNER : Le gagnant est le joueur 1 !" << std::endl;
            return;
        } else if(score_player2 == 40 && winner==1) { // if player2 has a score of 40 and player1 a score less than 40 = player 2 won
            std::cout << "WINNER : Le gagnant est le joueur 2 !" << std::endl;
            return;
        } else { // else it means that the game is not yet finished
            if(winner == 0) { // if player1 won the match, we add points in his score
                add_score(score_player1);
            } else {
                add_score(score_player2);
            }
            std::cout << " - Score player 1 : " << score_player1 << std::endl;
            std::cout << " - Score player 2 : " << score_player2 << std::endl;
            std::cout << "Allezzz, on continue le match" << std::endl;
        }
        
        std::cout << "" << std::endl;
    }
}

int main() { 
    int score_player1 = 0;
    int score_player2 = 0;

    play_game(score_player1, score_player2);
    return 0;
}