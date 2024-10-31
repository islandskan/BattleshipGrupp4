#include "utils.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <utility>

// Translates string coordinate input between 1-10 & A-J (1d, d6, h2 etc)
// Returns -1, -1 if invalid
// Returns index for coordinate (0, 9) on success
std::pair<int, int> validateCoordinate(std::string coord) {
    // Trim whitespace (spaces usually)
    coord.erase(std::remove_if(coord.begin(), coord.end(), ::isspace), coord.end());

    if (coord.length() > 3) { // Too long
        coord = coord.substr(0, 3);
    } else if (coord.length() < 2) { // Missing a char or int
        return std::make_pair(-1, -1);
    }

    // Accepted chars are between A-J uppercase (65, 74) https://www.learncpp.com/cpp-tutorial/chars/
    // Uppercase the string to handle the char values correctly
    std::transform(coord.begin(), coord.end(), coord.begin(), toupper);

    std::cout << "Attempting to validate: " << coord << std::endl; // Temp to see the conversions

    char extractedChar = '\0';
    std::string numStr = ""; // String for now, to add together the ints in form of char

    for (int i = 0; i < coord.length(); i++) {
        if (isdigit(coord[i])) {
            // If you have a valid num already set, and prev was not a num, this means a combinaton of int-char-int has been inputted
            if (numStr.length() > 0 && !isdigit(coord[i - 1])) {
                return std::make_pair(-1, -1);
            }

            numStr += coord[i];
        } else {
            if (extractedChar != '\0') return std::make_pair(-1, -1); // Only accepts one char

            // Check if char is within bounds using ASCII values
            if (coord[i] >= 'A' && coord[i] <= 'J') {
                extractedChar = coord[i];
            } else {
                return std::make_pair(-1, -1); // Out of bounds char
            }
        }
    }

    // Translating the extracted values to coordinates, and returning the index for that cordinate

    int xCoord = std::stoi(numStr);
    if (xCoord < 1 or xCoord > 10) {
        return std::make_pair(-1, -1);
    }

    int yCoord = int(extractedChar - 64); // A - 64 = 1

    std::cout << "Found: " << xCoord << ", " << yCoord << std::endl; // Temp to see the validates string

    return std::make_pair(xCoord - 1, yCoord - 1);
}
