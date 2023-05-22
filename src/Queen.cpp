/*
    This is the Queen class implementation file.
    This is where the Queen class methods are defined.
*/

#include "../headers/Queen.h"

// Default constructor of Queen Class
Queen::Queen()
{
}

// Constructor of Queen Class with parameter Colour
Queen::Queen(char Colour) : GamePieces(Colour)
{
}

// Method to return the piece code which is "Q"
char Queen::getPieces()
{
    return 'Q';
}

// Method to check if the move is legal for the Queen. It can only move in a straight line or diagonal
bool Queen::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
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
    }

    return false;
}

// Method to check if there is no piece in between the Queen's path in a diagonal line similar to Bishop's move
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

    // Checks there is no piecee in between to the bottom-left diagonal
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

// Method to check if there is no piece in between the Queen's path in a straight line similar to Rook's move
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