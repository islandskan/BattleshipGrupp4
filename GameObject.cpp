#include "Player.h"
#include "GameObject.h"
#include <iostream>
#include "utils/utils.cpp"

GameObject::GameObject(/* args */)
{
    // init the player/players?

    std::cout << "Inside GameObject" << std::endl;
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
            std::string buf= "";
            std::cin >> buf;

            std::pair<int, int> attackcoordinate = validateCoordinate(buf);//from included validate
            // Validate coordinates, -1, -1 is invalid
            // Continue if valid, otherwise re-prompt
    for(Player player: players)
    {
        // player.mark(active_player); // Temporarily disabled to get an executable, player is missing this method
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
