#include <iostream>
#include "start_menu.h"
#include <cstdlib> // exit
#include <ios> // streamsize
#include <limits> // numeric_limits

// int main() {
//     std::cout << "Running start_menu.cpp" << std::endl;

//     start_menu();

//     return 0;
// }

void start_menu() {
    int choice = 0;

    while (1) {
        std::cout << "[#] Start Menu [#]\n" << std::endl;
        std::cout << "1. Start Game" << std::endl; // Should this also offer a resume version? Can you toggle the menu during a game without any data loss?
        std::cout << "2. Rules" << std::endl;
        std::cout << "3. Quit" << std::endl;

        std::cout << "\nWhat do you want to do?" << std::endl;
        std::cout << "> ";

        std::cin >> choice;

        // Check if the input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        }

        switch (choice) {
            case 1: {
                std::cout << "Starting Game...";
                // TODO: Start the game, add this once we have merged all functions

                return;
            };
            case 2: {
                std::cout << "Opening Rules...";
                // TODO: Open the rules, add this once we have merged all functions

                return;
            };
            case 3: {
                return exit(0);
            };
            default: {
                std::cout << "\nInvalid input, please try again...\n" << std::endl;
                break;
            }
        }
    }
}
