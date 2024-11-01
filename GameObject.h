#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Player.h"
#include <vector>

class GameObject
{
private:
    /* data */
    std::vector <Player> players;
public:
    GameObject();
    ~GameObject();
    void take_turn(Player& player);
    void start_game();

};
#endif
