/*
    This is the Pawn class implementation file.
    This is where the Pawn class methods are defined.
*/

#include "../Headers/Pawn.h"

// Default constructor of Pawn Class
Pawn::Pawn()
{
}

// Constructor of Pawn Class with parameter Colour
Pawn::Pawn(char Colour) : GamePieces(Colour)
{
}

// Method to return the piece code which is "P"
char Pawn::getPieces()
{
    return 'P';
}

// Method to check if the move is legal for the Pawn. It can only move one square forward
bool Pawn::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    // Makes a test piece on the destination we want to move the piece on
    GamePieces *test = ChessBoard[rDest][cDest];

    // checkRow is the difference from the row destination from current row position
    int checkRow = rDest - rNow;

    // checkColoumn is the difference from the coloumn destination from current coloumn position
    int checkColoumn = cDest - cNow;

    // scalarRDest is the value of the row difference between the destination and the current row position
    int scalarRDest = rDest - rNow;

    // scalarCDest is the absolute value of the coloumn difference between the destination and the current column position
    int scalarCDest = abs(cDest - cNow);

    // Checks if that block is free
    if (test == 0)
    {
        // It moves 2 blocks at first time
        if (scalarRDest == -2 && scalarCDest == 0)
        {
            if (rNow == 6)
            {

                if (noPieceInBetween(checkRow, checkColoumn, scalarRDest, scalarCDest, rNow, cNow, ChessBoard) == true)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
            // It moves 1 block at at a time
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
    
    else if (scalarRDest == 1 && scalarCDest == 1 && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {
        if (test->getPieces() == 'K'){
        return true;
        }
    }
    return false;
}

// Method to check if there is no piece in between the destination and the current position
bool Pawn::noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

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
