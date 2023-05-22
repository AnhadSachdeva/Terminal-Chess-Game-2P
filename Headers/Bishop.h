/*
    This is the header file of Bishop Class
    Bishop class is used to create a Bishop object.
    It is derived from the GamePieces class.
*/

#ifndef BISHOP_H
#define BISHOP_H

#include "GamePieces.h"

class Bishop : public GamePieces
{

public:
    Bishop();
    Bishop(char Colour);
    char getPieces();
    bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
    bool noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
};

#endif