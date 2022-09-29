#include <iostream>
#include <cctype> // to use toUpper()
#include <algorithm>
#include <cstdlib>
#include <cmath>



void Ask_Firstname(){
    std::string firstname;
    std::cout << "What's your firstname ? ";
    std::cin >> firstname;

    std::cout << "Welcome, " << firstname << std::endl;
}

void Ask_Firstname_V2(){
    std::string firstname;
    std::string lastname;
    std::cout << "What's your full name (name firstname) ? ";
    std::cin >> lastname >> firstname; // ask for firstname and lastname in one single entry 

    if (!lastname.empty()) 
    {
        std::transform(lastname.begin(), lastname.end(), lastname.begin(), ::toupper); // put all the lastname letters in upper
    }

    if (!firstname.empty())
    {
        std::transform(firstname.begin(), firstname.end(), firstname.begin(), ::tolower); // put all the firstname letters in lower
        firstname[0] = std::toupper(firstname[0]); // we put first letter of the firstname in uppercase
    }

    std::cout << "Welcome, " << lastname << " " << firstname << std::endl;
}

void Seek_Right_Number() {
    srand((unsigned) time(0));
    std::cout << "A number generated will be between 0 and 1000, just find it !" << std::endl;
    int number_generated = (rand() % 1000);
    int guessed = -1; // init to -1 because generated value can be from 0 to 1000
    int number_trials = 0;
    //std::cout << number_generated << std::endl;
    
    do {
        number_trials++;
        std::cout << "Enter a number : ";
        std::cin >> guessed;

        if (std::cin.fail()) {
            std::cout << "--> Error : please enter a value !" << std::endl;
            std::cin.clear();
            std::cin.ignore(); // we clear and ignore the failure to restart the loop
            continue; // we start from the beginning of the loop
        }

        if(guessed < number_generated) {
            std::cout << "It's more !!" << std::endl;
        } else {
            std::cout << "It's less !!" << std::endl;
        }
    } while(number_generated != guessed);
    std::cout << "Congrats ! You found the right word in " << number_trials << " trials." << std::endl;
}

void Seek_Right_Number_Computer() {
    int number_to_guess; // number entered by the user
    int number_guessed; // number guessed by the computer
    int number_trials = 0;

    while(true) {
        std::cout << "Enter a number between 0 and 1000 to make the computer find it : ";
        std::cin >> number_to_guess;

        if (std::cin.fail() || number_to_guess < 0 || number_to_guess > 1000) {
            std::cout << "--> Error : please enter a value !" << std::endl;
            std::cin.clear();
            std::cin.ignore(); // we clear and ignore the failure to restart the loop
            continue; // we start from the beginning of the loop
        } else {
            break;
        }
    }

    int low = 0;
    int high = 1000;
    do {
        number_trials++;
        number_guessed = floor((low+high)/2); // Binary search algorithm formula
        if(number_guessed > number_to_guess) { // it's less 
            high = number_guessed-1; 
        } else {
            low = number_guessed+1; 
        }
        std::cout << "Number guessed by the computer : " << number_guessed << std::endl;
    } while(number_guessed != number_to_guess);
    std::cout << "Congrats ! The computer found the right word in " << number_trials << " trials." << std::endl;
}


int main(){
    // III.1.1
    std::cout << "III.1.1" << std::endl;
    Ask_Firstname();

    // III.1.2
    std::cout << "III.1.2" << std::endl;
    Ask_Firstname_V2();

    // III.2.1 + 2.2
    std::cout << "III.2.1 + 2.2" << std::endl;
    Seek_Right_Number();

    // III.2.3
    std::cout << "III.2.3" << std::endl;
    Seek_Right_Number_Computer();

    return 0;
}