/*
    This is the King class implementation file.
    This is where the King class methods are defined.
*/

#include "../headers/King.h"

// Default constructor of King Class
King::King()
{
}

// Constructor of King Class with parameter Colour
King::King(char Colour) : GamePieces(Colour)
{
}

// Method to return the piece code which is "K"
char King::getPieces()
{
    return 'K';
}

// Method to check if the move is legal for the King. It can only move one square in any direction
bool King::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    // Makes a test piece on the destination we want to move the piece on
    GamePieces *test = ChessBoard[rDest][cDest];

    // scalarRDest is the absolute value of the row difference between the destination and the current row position
    int scalarRDest = abs(rDest - rNow);

    // scalarCDest is the absolute value of the coloumn difference between the destination and the current column position
    int scalarCDest = abs(cDest - cNow);

    if (test == 0)
    {
        if (scalarRDest == 0 && scalarCDest == 1 || (scalarRDest == 1 && scalarCDest == 0))
        {

            return true;
        }
        else if (scalarRDest == 1 && scalarCDest == 1)
        {

            return true;
        }
    }
    else if (scalarRDest == 0 && scalarCDest == 1 || (scalarRDest == 1 && scalarCDest == 0) && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {

        return true;
    }
    else if (scalarRDest == 1 && scalarCDest == 1 && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {

        return true;
    }
    {

        return false;
    }
    return false;
}
