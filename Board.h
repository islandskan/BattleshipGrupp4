#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include <string>
#include <bitset>
#include <utility> // För std::pair

class Board
{
private:
    enum HitState{
        NONE, // Ingen träff har skett på denna plats.
        OURS, // Vår träff på motståndarens skepp.
        THEIRS, // Motståndarens träff på vårt skepp.
        BOTH // Både vi och motståndaren har träffat denna plats.
    };
    Ship* ship_grid[10][10]; // 10x10 matris för att lagra placering av skepp.
    std::bitset<3> hit_grid[10][10]; // 10x10 matris för att spåra skott - [0]: vi blev beskjutna här, [1]: vi sköt här, [2]: vi träffade här.
    Ship* water;
    Ship* coordinate_to_grid(std::string);
    Ship* coordinate_to_grid(std::pair<int, int>);

    // Kontrollerar om en position är ledig innan ett skepp placeras.
    bool can_place_ship(std::pair<int, int> start, std::pair<int, int> end);

public:

    Board();
    ~Board();
    bool place_ship(Ship* ship, std::pair<int, int> start, std::pair<int, int> end);
    void mark(std::pair<int, int>, bool theirs = false, bool hit_them = false); // eget skott: board.mark(coordinate); motståndarens skott: board.mark(coordinate, true);
    Ship* at_location(std::string);
    bool is_occupied(std::string);
    Ship* at_location(std::pair<int, int>);
    bool is_occupied(std::pair<int, int>);
    void print(void);
};

#endif
