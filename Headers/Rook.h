/*
    This is the header file of Rook Class
    Rook class is used to create a Rook object.
    It is derived from the GamePieces class.
*/

#ifndef ROOK_H
#define ROOK_H

#include "GamePieces.h"

class Rook : public GamePieces
{

public:
    Rook();
    Rook(char Colour);
    char getPieces();
    bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
    bool noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
};

#endif