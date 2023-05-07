#include "ChessBoard.h"
#include "ChessGame.h"
#include "GamePieces.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"

#include <iostream>

int main()
{
    ChessBoard chess;
    chess.print();
    for (int i = 0; i < 10; i++)
    {
    chess.makesTheMove();
    chess.print();
    }
    
  

    return 0;
}