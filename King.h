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