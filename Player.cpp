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


void Player::setupPlayers(){
    
    string playerName1;
    string playerName2;

    cout << "-----------Welcome to the Chess Game-------------" << endl;

    cout << "Enter the player 1 name: ";
    cin >> playerName1;

    cout << "Enter the player 2 name: ";
    cin >> playerName2;

    Player player1(playerName1, 'w');
    Player player2(playerName2, 'b');
    cout << "-------------------------------------------------" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Player 1: " << playerName1 << " is playing as \033[1;37mWHITE\033[0m" << endl;
    cout << "Player 2: " << playerName2 << " is playing as \033[1;30mBLACK\033[0m" << endl;

    cout << "-------------------------------------------------" << endl;

    cout << "The game has started" << endl;


}