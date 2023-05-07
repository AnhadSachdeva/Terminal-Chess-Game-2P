#include "Headers/Queen.h"
#include "Headers/Rook.h"
#include "Headers/Bishop.h"

Queen::Queen()
{
}

Queen::Queen(char Colour) : GamePieces(Colour)
{
}

char Queen::getPieces()
{
    return 'Q';
}

bool Queen::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    GamePieces *test = ChessBoard[rDest][cDest];
    int checkRow = rDest - rNow;
    int checkColoumn = cDest - cNow;
    int scalarRDest = abs(rDest - rNow);
    int scalarCDest = abs(cDest - cNow);

    if (test == 0)
    {

        if (scalarRDest == 0 || scalarCDest == 0)
        {
            // rook
            if (noPieceInBetweenRook(checkRow, checkColoumn, scalarRDest, scalarCDest, rNow, cNow, ChessBoard) == true)
            {
                return true;
            }
            // check there is no piecee in between when the rook moves up
        }
        else if (scalarRDest == scalarCDest)
        {

            // bishop
            //  check there is no piecee in between to the left diagonal
            if (noPieceInBetweenBish(checkRow, checkColoumn, scalarRDest, scalarCDest, rNow, cNow, ChessBoard) == true)
            {
                return true;
            }
        }
    }
    else if (scalarRDest == 0 || scalarCDest == 0 && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {

        if (noPieceInBetweenRook(checkRow, checkColoumn, scalarRDest, scalarCDest, rNow, cNow, ChessBoard) == true)
        {
            return true;
        }
    }
    else if (scalarRDest == scalarCDest && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {
        if (noPieceInBetweenBish(checkRow, checkColoumn, scalarRDest, scalarCDest, rNow, cNow, ChessBoard) == true)
        {
            return true;
        }

        return true;
    }

    return false;
}

bool Queen::noPieceInBetweenBish(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    if (checkRow < 0 && checkColoumn < 0)
    {
        for (int i = 1; i < scalarRDest; i++)
        {
            if (ChessBoard[rNow - i][cNow - i] != 0)
            {
                return false;
            }
        }
    }
    // check there is no piecee in between to the right diagonal
    if (checkRow < 0 && checkColoumn > 0)
    {
        for (int i = 1; i < scalarRDest; i++)
        {
            if (ChessBoard[rNow - i][cNow + i] != 0)
            {
                return false;
            }
        }
    }
    // check there is no piecee in between to the bottom-left diagonal

    if (checkRow > 0 && checkColoumn > 0)
    {
        for (int i = 1; i < scalarRDest; i++)
        {
            if (ChessBoard[rNow + i][cNow + i] != 0)
            {
                return false;
            }
        }
    }
    // check there is no piecee in between to the bottom-right diagonal

    if (checkRow > 0 && checkColoumn < 0)
    {
        for (int i = 1; i < scalarRDest; i++)
        {
            if (ChessBoard[rNow + i][cNow - i] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Queen::noPieceInBetweenRook(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    if (checkRow < 0 && checkColoumn == 0)
    {
        for (int i = 1; i < scalarRDest; i++)
        {
            if (ChessBoard[rNow - i][cNow] != 0)
            {
                return false;
            }
        }
    }
    // check there is no piecee in between when the rook moves down
    if (checkRow > 0 && checkColoumn == 0)
    {
        for (int i = 1; i < scalarRDest; i++)
        {
            if (ChessBoard[rNow + i][cNow] != 0)
            {
                return false;
            }
        }
    }
    // check there is no piecee in between when the rook moves left

    if (checkRow == 0 && checkColoumn < 0)
    {
        for (int i = 1; i < scalarCDest; i++)
        {
            if (ChessBoard[rNow][cNow - i] != 0)
            {
                return false;
            }
        }
    }
    // check there is no piecee in between when the rook right

    if (checkRow == 0 && checkColoumn > 0)
    {
        for (int i = 1; i < scalarCDest; i++)
        {
            if (ChessBoard[rNow][cNow + i] != 0)
            {
                return false;
            }
        }
    }
    return true;
}