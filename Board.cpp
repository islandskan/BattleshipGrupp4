#include "Board.h"
#include <iostream>
#include <cctype>
#include <algorithm>

Board::Board(){

    water = nullptr;

    for (int row = 0; row < 10; row++){
        for (int col = 0; col < 10; col++){
            ship_grid[row][col] = water;
            hit_grid[row][col].reset();
        }
    }
}

Board::~Board(){}

// En funktion som kontrollerar om skeppet kan placeras
bool Board::can_place_ship(std::pair<int, int> start, std::pair<int, int> end) {
    for (int col = std::min(start.first, end.first); col <= std::max(start.first, end.first); col++){
        for (int row = std::min(start.second, end.second); row <= std::max(start.second, end.second); row++){
            if (is_occupied(std::make_pair(col, row))) {
                return false; // Returnera falskt om någon del av området redan är upptagen
            }
        }
    }
    return true;
}
        //Kontrollerar om området är ledigt.
bool Board::place_ship(Ship* ship, std::pair<int, int> start, std::pair<int, int> end) {
    if (!can_place_ship(start, end)) {
        std::cerr << "Kan inte placera skeppet: platsen är redan upptagen." << std::endl;
        return false; // Returnerar falskt om vi inte kan placera skeppet
    }

    for (int col = std::min(start.first, end.first); col <= std::max(start.first, end.first); col++){
        for (int row = std::min(start.second, end.second); row <= std::max(start.second, end.second); row++){
            ship_grid[row][col] = ship;
        }
    }
    return true; // Returnerar sant om placeringen lyckades
}

// Resterande funktioner för koordinater och is_occupied (samma som tidigare)
Ship* Board::coordinate_to_grid(std::string coordinate){
    int x, y;
    switch (isalpha(coordinate.front())){
        case true:
            x = coordinate.front() - 'A';
            y = coordinate.back() - '1';
            break;
        case false:
            x = coordinate.back() - 'A';
            y = coordinate.front() - '1';
            break;
    }
    return ship_grid[x][y];
}


Ship* Board::coordinate_to_grid(std::pair<int, int> coordinate){
    // coordinate assumed to be 2 character string A1 or 1A
    return ship_grid[coordinate.second][coordinate.first];
}

bool Board::is_occupied(std::string coordinate){
    return coordinate_to_grid(coordinate) != water;
}

Ship* Board::at_location(std::string coordinate){
return coordinate_to_grid(coordinate);

}

bool Board::is_occupied(std::pair<int, int> coordinate){
    return coordinate_to_grid(coordinate) != water;
}

Ship* Board::at_location(std::pair<int, int> coordinate){
    return coordinate_to_grid(coordinate);
}

void Board::mark(std::pair<int, int> coordinate, bool theirs = false, bool hit_them = false){
    int col = coordinate.first;
    int row = coordinate.second;

    hit_grid[row][col].set(0, !theirs);
    hit_grid[row][col].set(1, theirs);
    hit_grid[row][col].set(2, hit_them);
}

void Board::print(){
    char rowlabel = 'A';
    std::string pboard_line = "";
    std::string opboard_line = "";

    for (int row = 0; row < 10; row++){
            for (int col = 0; col < 10; col++){
                if ( hit_grid[row][col].test(0) ){
                    ship_grid[row][col] != water ? pboard_line.push_back('X') : pboard_line.push_back('O');
                } else {
                    ship_grid[row][col] != water ? pboard_line.push_back('S') : pboard_line.push_back(',');
                }

                if ( hit_grid[row][col].test(1) ){
                    hit_grid[row][col].test(2) ? opboard_line.push_back('X') : opboard_line.push_back('O');
                } else {
                    opboard_line.push_back('.');
                }

                std::cout << (char)rowlabel + row << " " << pboard_line << "   " << (char)rowlabel + row << " " << opboard_line << std::endl;
                pboard_line.clear();
                opboard_line.clear();
            }
    }
}
