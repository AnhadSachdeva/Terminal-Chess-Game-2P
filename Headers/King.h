/*
    This is the header file of King Class
    King class is used to create a King object.
    It is derived from the GamePieces class.
*/

#ifndef KING_H
#define KING_H

#include "GamePieces.h"

class King : public GamePieces
{

public:
    King();
    King(char Colour);
    char getPieces();
    bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
};

#endif