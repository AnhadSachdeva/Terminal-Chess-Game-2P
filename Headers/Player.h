#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string.h>

using namespace std;

//Base Class 

class Player
{

protected:
    string name;
    char color;



public:

    Player();
    Player(string Name, char Color);
    string getPlayerName();
    char getPlayerColor();
    void setupPlayers();
};

#endif