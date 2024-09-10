#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    std::srand(static_cast<unsigned>(std::time(0)));
    
    // random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "This is my Guessing Game!" << std::endl;
    std::cout << "Enter a number between 1 and 100." << std::endl;
    
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > randomNumber) {
            std::cout << "Your guess is too high." << std::endl;
        } else if (userGuess < randomNumber) {
            std::cout << "Your guess is too low." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
        }
    }

    return 0;
}
