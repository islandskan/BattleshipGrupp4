#include "Player.h"
#include "utils/utils.h"
#include <iostream>


// 3x 2:or 2x 3:or 1x 4:a 1x 5:a 1x Kapten (1:a)
Player::Player(std::string name/*board, ships, points, GameObject&*/){
    this->name = name;
    points = 0;
    ships.emplace_back(new Submarine());
    ships.emplace_back(new Submarine());
    ships.emplace_back(new Submarine());
    ships.emplace_back(new Destroyer());
    ships.emplace_back(new Destroyer());
    ships.emplace_back(new Cruiser());
    ships.emplace_back(new Carrier());
    ships.emplace_back(new Captain());
}

Player::~Player()
{
    for(Ship ship : ships){
        delete &ship;
    }
}


int Player::update_points(int new_point)
{
    points += new_point;
}

int Player::get_attacked(std::pair<int, int> coordinate){
    bool hit = board.is_occupied(coordinate);
    int r = -1 + hit;
    //kolla om motståndaren redan skjutit där och det inte är en kapten, i så fall, returnera false
    //annars om det är en kapten och det är andra skottet då är kaptenen sänkt

    if ( hit == true ) {
        board.at_location(coordinate)->hit();
    }

    r += board.at_location(coordinate)->checkIfSunk() * board.at_location(coordinate)->getPointValue();

    return r;
}


void Player::mark_attack(std::pair<int, int> coordinate, bool success)
{
    board.mark(coordinate, false, success);
}

std::string Player::get_name()
{
    return this->name;
}

int Player::get_points()
{
return this->points;
}

void Player::print()
{
    std::cout<<get_name();
    std::cout<<get_points();
    update_points(2);
    std::cout<<get_points();

}