/*
    This is the Rook class implementation file.
    This is where the Rook class methods are defined.
*/

#include "../Headers/Rook.h"

// Default constructor of Rook Class
Rook::Rook()
{
}

// Constructor of Rook Class with parameter Colour
Rook::Rook(char Colour) : GamePieces(Colour)
{
}

// Method to return the piece code which is "R"
char Rook::getPieces()
{
    return 'R';
}

// Method to check if the move is legal for the Rook. It can only move in a straight line
bool Rook::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    // makes a test piece on the destination we want to move the piece on
    GamePieces *test = ChessBoard[rDest][cDest];

    // checkRow is the row difference between the row destination and the current row position
    int checkRow = rDest - rNow;

    // checkColoumn is the coloumn difference between the coloumn destination and the current coloumn position
    int checkColoumn = cDest - cNow;

    // scalarRDest is the absolute value of the row difference between the row destination and the current row position
    int scalarRDest = abs(rDest - rNow);

    // scalarCDest is the absolute value of the coloumn difference between the coloumn destination and the current coloumn position
    int scalarCDest = abs(cDest - cNow);

    // Checks if the destination is empty
    if (test == 0)
    {

        if (scalarRDest == 0 || scalarCDest == 0)
        {
            if (noPieceInBetween(checkRow, checkColoumn, scalarRDest, scalarCDest, rNow, cNow, ChessBoard) == true)
            {
                return true;
            }
        }
    }
    else if (scalarRDest == 0 || scalarCDest == 0 && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
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
    return false;
}

// Method to check if there is no piece in between the current position and the destination
bool Rook::noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    // Checks if there is no piecee in between when the rook moves up
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
    // Checks if there is no piecee in between when the rook moves down
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

    // Checks if there is no piecee in between when the rook moves left
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

    // Checks if there is no piecee in between when the rook right
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
