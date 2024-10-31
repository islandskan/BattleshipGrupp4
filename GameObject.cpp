#include "Player.h"
#include "GameObject.h"
#include "utils/utils.h"
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
            bool is_hit;
            int score_value = 0;
            std::pair <int, int> attackcoordinate;
            std::string buf= "";
            std::cin >> buf;
            attackcoordinate = validateCoordinate(buf);//from included validate
           //check if coordinate is valid
        // if valid, continue
        // else further checking
        for(Player player: players)
        {
            if (&player != &active_player){
                score_value = player.get_attacked(attackcoordinate);
                if ( score_value >= 0 )
                    is_hit = true;
                } else {
                    is_hit = false;
                    score_value = 0;
            }
        }

        active_player.update_points(score_value);
        active_player.mark_attack(attackcoordinate, is_hit);

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
