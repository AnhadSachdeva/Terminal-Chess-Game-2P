#ifndef CHESSBOARD_H
#define CHESSBOARD_H
 
#include "GamePieces.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"

class ChessBoard
{

protected:
    GamePieces *chessBoard[8][8];
    string chess[8][8];

public:
    ChessBoard();
    ~ChessBoard();
    void print();
    void makesTheMove();
    void flipBoard();
};



#endif