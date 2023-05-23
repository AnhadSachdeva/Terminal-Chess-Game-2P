/*
    This is the main file for the chess game.
    It is where the game is started and the players are set up.
    Both the Player and ChessBoard classes are runned from here.
*/
#include "../Headers/ChessBoard.h"
#include "../Headers/GamePieces.h"
#include "../Headers/Player.h"
#include "../Headers/King.h"
#include "../Headers/Knight.h"
#include "../Headers/Rook.h"
#include "../Headers/Bishop.h"
#include "../Headers/Queen.h"
#include "../Headers/Pawn.h"

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
