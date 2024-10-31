#include <iostream>
#include "utils/utils.h"
#include <utility>

std::string getCoordinateInput();

// int main() {
//     std::cout << "testing.cpp" << std::endl;

//     getCoordinateInput();

//     return 0;
// }

// TODO: Decide the return type based on rest of program, string during testing
std::string getCoordinateInput() {
    // Helper print, perhaps this should be in rules to clear up clutter during gameplay?
    // Perhaps it is not clear how the input is accepted, don't want to print it every round
    std::cout << "Examples: " << std::endl;
    std::cout << "7h, 6d, g3" << std::endl;

    std::string input;
    while (1) {
        std::cout << "Please provide a coordinate input: ";

        std::getline(std::cin, input);
        std::pair<int, int> coords = validateCoordinate(input);
        if (coords.first == -1 || coords.second == -1) {
            std::cout << "Invalid coordinates, please try again." << std::endl << std::endl;
        }

        // TODO: Add logic & execution when coordinates are correct
    }
}
