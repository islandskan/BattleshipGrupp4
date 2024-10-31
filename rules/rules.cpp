#include <iostream>
#include "rules.h"
#include <string>
#include <utility>
#include <vector>

#define MAX_LINE_LENGTH 80

// int main() {
//     std::cout << "Running rules.cpp" << std::endl;

//     displayRules();
// }

// Displays title along with some "icons" to separate the rules from these headers
// Fills up the max line length, with a whitespace addition to the suffix of the title if needed
void displayTitle(std::string title) {
    int titleLen = title.length();

    std::string lIcon = "[#####";
    int lIconLen = lIcon.length();

    std::string rIcon = "#####]";
    int rIconlen = rIcon.length();

    int spaceToFill = MAX_LINE_LENGTH - titleLen;

    int prefixSpaceLen = spaceToFill / 2 - lIconLen;
    int suffixSpaceLen = spaceToFill / 2 -  rIconlen;

    int suffixSpaceAddition = (spaceToFill - rIconlen - lIconLen) % 2;
    suffixSpaceLen += suffixSpaceAddition;

    std::string prefixSpace(prefixSpaceLen, ' ');
    std::string suffixSpace(suffixSpaceLen, ' ');

    std::string prefix = lIcon + prefixSpace;
    std::string suffix = suffixSpace + rIcon;

    // Roof & floor of title
    std::string encapsulator = "[" + std::string(MAX_LINE_LENGTH - 2, '#') + "]";

    std::cout << encapsulator << std::endl;
    std::cout << prefix << title << suffix << std::endl;
    std::cout << encapsulator << std::endl;
}

// Display rule & add new line for every 60 characters
// Appends a rule number
void displayRule(std::string *rule, int idx) {
    std::string formattedRule = std::to_string(idx + 1) + ". ";
    int line = 0;

    int charCount = 3; // Rule number prefix
    for (char c : std::string(*rule)) {
        charCount += 1;

        // At the moment, it breaks if character limit is exceeded and if the character is a space.
        // Possible TODO: Can make some system where it detects max line length, backtracks the last sentence and puts that properly on the first line, if we get extra time, this ensures max length without looking weird
        // If the character is a line break, simply reset all & let it break the line
        if (charCount > MAX_LINE_LENGTH && c == ' ' || c == '\n') {
            line += 1;

            // Skip to next line, and add spaces to format it along the lines of the first character above
            charCount = 3;
            formattedRule += "\n   ";
        } else {
            formattedRule += c;
        }
    }

    std::cout << formattedRule << "\n" << std::endl;
}

void displayRules() {
    // TODO: Complete all game rules
    std::vector<std::string> gameRules = {
        "The winner is decided by total points.",
        "During the start phase...",
        "Some other rules...",
        "Some other rules...",
        "During the games progression, you will be asked to make an attack. Each player takes their turn to complete an attack. Once you complete your attack, your opponent has to confirm their round start by pressing any character.",
        "To destroy a captain ship, it has to be shot twice. Destroying the captain ship will yield extra points, and end the game.",
        "Point guide:\nA point is yielded when you completely sink a ship.\n- Captain: 10\n- x: y\n- x: y\n- x: y\n- x: y\n- x: y",
    };

    // TODO: Ensure these commands & inputs are correct when the application is done
    std::vector<std::string> inputInstructions = {
        "When prompted to input coordinates, a combintation of a number between 1-10 and a character between A-J is required. Any order, such as A1 and 1A is accepted. If your input is in any way incorrect, you will be prompted to re-type it.",
        "At all times, you can perform the following commands:\n- !rules (Opens Rules Menu)\n- !start (Opens Start Menu)\n- !quit (Quits The Application)"
    };

    std::pair<std::string, std::vector<std::string>*> titles[2] = {
        std::make_pair("Game Rules", &gameRules),
        std::make_pair("Input Prompt Guide", &inputInstructions)
    };

    for (int i = 0; i < 2; i++) {
        displayTitle(titles[i].first);

        std::cout << "\n";

        std::vector<std::string>* instructions = titles[i].second;
        if (instructions) {
            int instructionNum = 0;

            for (std::string &instruction : *instructions) {
                displayRule(&instruction, instructionNum);

                instructionNum++;
            }
        }
    }
}
