#include "Player.h"
#include "GameObject.h"
#include <iostream>

GameObject::GameObject(/* args */)
{
    // init the player/players?
}

GameObject::~GameObject()
{
}

void GameObject::start_game() {
    std::cout << "start_game" << std::endl;
}

void GameObject::take_turn(Player)
{
    //void take_turn(Player);


    int turn = 0;
    std::cout << "Press Enter to start turn";
    while(std::cin.get()!='\n');

    // while input from player's coordinates !-1, continue loop = player's turn
    while(turn)
    {
        for( Player active_player : players ) {
           std::pair <int, int> attackcoordinate;
           std::string buf= "";
           std::cin >> buf;
           attackcoordinate=validate(buf);//from included validate
           //check if coordinate is valid
        // if valid, continue
        // else further checking
    for(Player player: players)
    {
        player.mark(active_player);
    }
        }


        /*
        available actions as long as player is active:
        console input = coordinates to attack enemy

        draw board
        display info (name, points)
        receive points if successful hit
        */
    }
}
