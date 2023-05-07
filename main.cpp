#include "Headers/ChessBoard.h"
#include "Headers/ChessGame.h"
#include "Headers/GamePieces.h"
#include "Headers/King.h"
#include "Headers/Knight.h"
#include "Headers/Rook.h"
#include "Headers/Bishop.h"
#include "Headers/Queen.h"
#include "Headers/Pawn.h"

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