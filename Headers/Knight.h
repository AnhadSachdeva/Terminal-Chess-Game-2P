/*
    This is the header file of Knight Class
    Knight class is used to create a Kight object.
    It is derived from the GamePieces class.
*/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "GamePieces.h"

class Knight : public GamePieces
{

public:
    Knight();
    Knight(char Colour);
    char getPieces();
    bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
};

#endif