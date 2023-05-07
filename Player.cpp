#include "Headers/Player.h"

Player::Player()
{
}

Player::Player(string Name, char Color)
{

    this->name = Name;
    this->color = Color;
}

string Player::getPlayerName()
{

    return this->name;
}

char Player::getPlayerColor()
{

    return this->color;
}