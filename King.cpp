#include "Headers/King.h"

King::King()
{
}
King::King(char Colour) : GamePieces(Colour)
{
}

char King::getPieces()
{
    return 'K';
}

bool King::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    GamePieces *test = ChessBoard[rDest][cDest];
    int scalarRDest = abs(rDest - rNow);
    int scalarCDest = abs(cDest - cNow);

    if (test == 0)
    {

        if (scalarRDest == 0 && scalarCDest == 1 || (scalarRDest == 1 && scalarCDest == 0))
        {

            return true;
        }
    }
    else if (scalarRDest == 0 && scalarCDest == 1 || (scalarRDest == 1 && scalarCDest == 0) && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {

        return true;
    }
    else
    {

        return false;
    }
    return false;
}
