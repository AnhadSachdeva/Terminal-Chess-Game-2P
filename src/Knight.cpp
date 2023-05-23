/*
    This is the Knight class implementation file.
    This is where the Knight class methods are defined.
*/
#include "../Headers/Knight.h"

// Default constructor of Knight Class
Knight::Knight()
{
}

// Constructor of Knight Class with parameter Colour
Knight::Knight(char Colour) : GamePieces(Colour)
{
}

// Method to return the piece code which is "N"
char Knight::getPieces()
{
    return 'N';
}

// Method to check if the move is legal for the Knight. It can only move in an L shape
bool Knight::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    // Makes a test piece on the destination we want to move the piece on
    GamePieces *test = ChessBoard[rDest][cDest];

    // scalarRDest is the absolute value of the row difference between the destination and the current row position
    int scalarRDest = abs(rDest - rNow);

    // scalarCDest is the absolute value of the coloumn difference between the destination and the current column position
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