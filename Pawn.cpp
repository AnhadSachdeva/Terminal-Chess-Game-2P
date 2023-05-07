#include "Pawn.h"

Pawn::Pawn(char Colour) : GamePieces(Colour)
{
}

char Pawn::getPieces()
{
    return 'P';
}

bool Pawn::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    // makes a test piece on the destination we want to move the piece on
    GamePieces *test = ChessBoard[rDest][cDest];

    int checkRow = rDest - rNow;
    int checkColoumn = cDest - cNow;

    // calculate and stores the absolute value of the difference from the destination from current position
    int scalarRDest = rDest - rNow;
    int scalarCDest = abs(cDest - cNow);
    // checks if that block is free
    if (test == 0)
    {
        // moves 2 blocks at a time
        // can make the
        if (scalarRDest == -2 && scalarCDest == 0)
        {
                 if (noPieceInBetween(checkRow,checkColoumn,scalarRDest,scalarCDest,rNow,cNow,ChessBoard) == true){
                return true;
            }
            // one block at a time
        }
        else if (scalarRDest == -1 && scalarCDest == 0)
        {
            return true;
        }
    }
    else if (scalarRDest == -1 && scalarCDest == 1 && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {

        return true;
    }
    else
    {
        return false;
    }
    return false;
}


bool Pawn::noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow,GamePieces *ChessBoard[8][8]){
             
              if (checkRow < 0 && checkColoumn == 0)
            {
                for (int i = -1; i > scalarRDest; i--)
                {
                    if (ChessBoard[rNow + i][cNow] != 0)
                    {
                        return false;
                    }
                }
            }

            return true;
}
