#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "Board.h"
#include <utility>
#include "Ship.h"
#include "GameObject.h"


class Player
{
private:
    int points = 0;
    std::string name = "";
    Board board;
    std::vector<Ship*> ships;
    GameObject* Game;

public:
    Player(std::string/*board, ships, points, GameObject&*/);
    ~Player();


    void print();
    void mark_attack(std::pair<int, int>, bool);
    int update_points(int new_points);
    std::pair<int, int> attack(/*coordinates*/);
    void take_turn(Player* opponent);
    int get_attacked(std::pair<int, int> coord);


    // getters
    std::string get_name();
    int get_points();
    // bool get_turn_state();
};

#endif