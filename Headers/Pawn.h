#ifndef PAWN_H
#define PAWN_H

#include "GamePieces.h"

class Pawn : public GamePieces
{

protected:
public:
    Pawn();
    Pawn(char Colour);
    char getPieces();
    bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
    bool noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow,GamePieces *ChessBoard[8][8]);

};



#endif