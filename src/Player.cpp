#include "../Headers/Player.h"

// Default constructor of Player Class
Player::Player()
{
}

// Constructor of Player Class with parameter Name and Color
Player::Player(string Name, char Color)
{
    // Sets the Player's Name and Color
    this->name = Name;
    this->color = Color;
}

// Method to return the player name
string Player::getPlayerName()
{
    // Returns the player's Name
    return this->name;
}

// Method to return the player Color
char Player::getPlayerColor()
{
    // Returns the player's colour
    return this->color;
}

// Method to display the starting of the game
void Player::setupPlayers()
{

// Checks the operating system of the user, and sets clearScreen variable to clear the terminal according to the operating system. "cls" for windows, and "clear" for linux & mac
#if defined(_WIN32) || defined(_WIN64)
    string clearScreen = "cls"; // clears the terminal in windows
#else
    string clearScreen = "clear"; // clears the terminal in linux & mac
#endif

    // Clears the terminal
    system(clearScreen.c_str());

    // Prompts the user to enter their name and tells the user what pieces you have been assigned
    string playerName1;
    string playerName2;
    cout << "" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "           Welcome to the Chess Game             " << endl;
    cout << "-------------------------------------------------" << endl;

    // Takes the input of the player names
    cout << "Enter the name of \033[1;37mPlayer 1\033[0m: ";
    cin >> playerName1;
    cout << "-------------------------------------------------" << endl;

    cout << "Enter the name of \033[1;37mPlayer 2\033[0m: ";
    cin >> playerName2;

    Player player1(playerName1, 'w');
    Player player2(playerName2, 'g');
    cout << "-------------------------------------------------" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Player 1: "
         << "\033[1;37m" << playerName1 << "\033[0m"
         << " is playing as \033[1;37mWHITE\033[0m" << endl;

    cout << "Player 2: "
         << "\033[1;32m" << playerName2 << "\033[0m"
         << " is playing as \033[1;32mGREEN\033[0m" << endl;

    cout << "-------------------------------------------------" << endl;
    cout << "--------------The Game Has Started---------------" << endl;
}
