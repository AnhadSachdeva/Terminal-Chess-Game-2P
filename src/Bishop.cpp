/*
    This is the Bishop class implementation file.
    This is where the Bishop class methods are defined.
*/

#include "../headers/Bishop.h"

// Default constructor of Bishop Class
Bishop::Bishop()
{
}

// Constructor of Bishop Class with parameter Colour
Bishop::Bishop(char Colour) : GamePieces(Colour)
{
}

// Method to return the piece code which is "B"
char Bishop::getPieces()
{
    return 'B';
}

// Method to check if the move is legal for the Bishop. It can only move diagonally
bool Bishop::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    // Makes a Test Piece on the Destination that we Want to Move the Piece On
    GamePieces *test = ChessBoard[rDest][cDest];

    // checkRow is the row difference between the destination and the current row position
    int checkRow = rDest - rNow;

    // checkColoumn is the coloumn difference between the destination and the current column position
    int checkColoumn = cDest - cNow;

    // scalarRDest is the absolute value of the row difference between the destination and the current row position
    int scalarRDest = abs(rDest - rNow);

    // scalarCDest is the absolute value of the coloumn difference between the destination and the current column position
    int scalarCDest = abs(cDest - cNow);

    if (test == 0)
    {

        if (scalarRDest == scalarCDest)
        {
            // Checks if there is no piecee in between to the left diagonal
            if (noPieceInBetween(checkRow, checkColoumn, scalarRDest, scalarCDest, rNow, cNow, ChessBoard) == true)
            {
                return true;
            }
        }
    }
    else if (scalarRDest == scalarCDest && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
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

// Method to check if there is no piece in between the Bishop's move.
bool Bishop::noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    // Checks if there is no piecee in between to the up-left diagonal
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
    // Checks if there is no piecee in between to the up-right diagonal
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
    // Checks if there is no piecee in between to the bottom-left diagonal

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
    // Checks if there is no piecee in between to the bottom-right diagonal

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