/*
    This is the header file for the Player class.
    The Player class is the Parent class of GamePieces class
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

// Base Class

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
    void setPlayers();
};

#endif