#include "Headers/ChessBoard.h"
#include "Headers/ChessGame.h"
#include "Headers/GamePieces.h"
#include "Headers/Player.h"
#include "Headers/King.h"
#include "Headers/Knight.h"
#include "Headers/Rook.h"
#include "Headers/Bishop.h"
#include "Headers/Queen.h"
#include "Headers/Pawn.h"

#include <iostream>

using namespace std;

int main()
{

    //   ChessGame game;
    Player initalSetup;
    initalSetup.setupPlayers();


    ChessBoard chess;
    chess.start();


    return 0;
}
