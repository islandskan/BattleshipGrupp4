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
    for (Ship* ship : ships) {
        delete ship;
    }
}


int Player::update_points(int new_point)
{
    points += new_point;
}
//Hanterar en attack mot spelaren:
int Player::get_attacked(std::pair<int, int> coordinate){

    if (!board.is_occupied(coordinate)) {
        return -1; //Returna false om det redan har skjutits där
    }
    //Markera träff om det finns ett skepp där.
    if (board.at_location(coordinate)->is_already_hit()) {
        return false;
    }

    board.at_location(coordinate)->hit();

    //Kolla om det är en kapten
    if (board.at_location(coordinate)->is_Captain()) {
        if (board.at_location(coordinate)->getHitCount() == 2) {
            return board.at_location(coordinate)->getPointValue();
        }
    }
        //Beräkna poäng om skettet sänks
    int r = board.at_location(coordinate)->checkIfSunk() * board.at_location(coordinate)->getPointValue();
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
    std::cout << "Name: " << get_name() << std::endl;
    std::cout << "Points: " << get_points() << std::endl;
    update_points(2);
    std::cout << "New Points: " << get_points() << std::endl;

}