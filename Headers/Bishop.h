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