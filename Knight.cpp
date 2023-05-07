#include "Knight.h"

Knight::Knight()
{
}

Knight::Knight(char Colour) : GamePieces(Colour)
{
}

char Knight::getPieces()
{
    return 'N';
}

bool Knight::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    GamePieces *test = ChessBoard[rDest][cDest];
    int scalarRDest = abs(rDest - rNow);
    int scalarCDest = abs(cDest - cNow);

    if (test == 0)
    {

        if (scalarRDest == 2 && scalarCDest == 1 || scalarRDest == 1 && scalarCDest == 2)
        {

            return true;
        }
    }
    else if (scalarRDest == 2 && scalarCDest == 1 || scalarRDest == 1 && scalarCDest == 2 && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {

        return true;
    }
    else
    {

        return false;
    }
    return false;
}