/*
    This is the header file of Queen Class
    Queen class is used to create a Queen object.
    It is derived from the GamePieces class.
*/

#ifndef QUEEN_H
#define QUEEN_H

#include "GamePieces.h"

class Queen : public GamePieces
{

public:
    Queen();
    Queen(char Colour);
    char getPieces();
    bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
    bool noPieceInBetweenBish(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
    bool noPieceInBetweenRook(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
};

#endif