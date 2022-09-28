#include <iostream>
#include <cctype> // to use toUpper()
#include <algorithm>

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

    if (!lastname.empty()) // Edit : Add the verification
    {
        std::transform(lastname.begin(), lastname.end(), lastname.begin(), ::toupper); // put all the lastname letters in upper
    }

    if (!firstname.empty()) // Edit : Add the verification
    {
        std::transform(firstname.begin(), firstname.end(), firstname.begin(), ::tolower); // put all the firstname letters in lower
        firstname[0] = std::toupper(firstname[0]); // we put first letter of the firstname in uppercase
    }

    std::cout << "Welcome, " << lastname << " " << firstname << std::endl;
}

int main(){
    // III.1.1
    Ask_Firstname();

    // III.1.2
    Ask_Firstname_V2();

    return 0;
}