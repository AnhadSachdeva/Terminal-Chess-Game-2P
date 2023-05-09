#include "Headers/Player.h"

Player::Player()
{
}

Player::Player(string Name, char Color)
{
    //sets up the player name and color
    this->name = Name;
    this->color = Color;
}

string Player::getPlayerName()
{
    //returns the plaeyrs name
    return this->name;
}

char Player::getPlayerColor()
{
    //returns the plaeyrs colour
    return this->color;
}


void Player::setupPlayers(){
    
    //Prompts the user to enter their name and tells the user what pieces you have been assigned

    string playerName1;
    string playerName2;

 
    cout << "-----------Welcome to the Chess Game-------------" << endl;

    //takes inout
    cout << "Enter the player 1 name: ";
    cin >> playerName1;

    cout << "Enter the player 2 name: ";
    cin >> playerName2;

    Player player1(playerName1, 'w');
    Player player2(playerName2, 'b');
    cout << "-------------------------------------------------" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Player 1: " << playerName1 << " is playing as \033[1;37mWHITE\033[0m" << endl;
    cout << "Player 2: " << playerName2 << " is playing as \033[1;32mBLACK\033[0m" << endl;

    cout << "-------------------------------------------------" << endl;

       cout << "if you wish to kill the game just enter kill twice" << endl << endl;

    cout << "The game has started" << endl;


}


