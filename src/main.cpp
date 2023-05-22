/*
    This is the main file for the chess game.
    It is where the game is started and the players are set up.
    Both the Player and ChessBoard classes are runned from here.
*/
#include "../headers/ChessBoard.h"
#include "../headers/GamePieces.h"
#include "../headers/Player.h"
#include "../headers/King.h"
#include "../headers/Knight.h"
#include "../headers/Rook.h"
#include "../headers/Bishop.h"
#include "../headers/Queen.h"
#include "../headers/Pawn.h"

#include <iostream>

using namespace std;

int main()
{

    Player initalSetup;
    initalSetup.setupPlayers();

    ChessBoard chess;
    chess.start();

    return 0;
}
