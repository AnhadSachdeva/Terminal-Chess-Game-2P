#ifndef GAMEPIECES_H
#define GAMEPIECES_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>

#include "Player.h"

using namespace std;

class GamePieces : public Player
{

protected:
    char piecesColour;

public:
    GamePieces();
    GamePieces(char piecesColour);
    // basically their ID
    virtual char getPieces() = 0;
    // checks if it is in the board and doesn't land on the its own peices
    // then returns the values in isMoveLegalForPiece to check if the piece can move in there
    bool isMoveLegal(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
    // checks if the peice can move there using each peices movments and returns true
    virtual bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]) = 0;
    char getPiecesColour();
    virtual ~GamePieces();

};

#endif
