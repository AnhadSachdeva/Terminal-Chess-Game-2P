#include "Headers/GamePieces.h"

GamePieces::GamePieces()
{
}
GamePieces::GamePieces(char piecesColour)
{
    this->piecesColour = piecesColour;
}

bool GamePieces::isMoveLegal(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    // "rDest" = row destination
    // "cDest" = coloumn destination
    // "rNow" = current row
    // "cNow" = current coloumn

    // makes a test piece on the destination we want to move the piece on
    GamePieces *check = ChessBoard[rDest][cDest];
    if (check == 0 || check->getPiecesColour() != this->piecesColour)
    {
        // if the piece is in the coloumn
        return isMoveLegalForPiece(rDest, cDest, rNow, cNow, ChessBoard);
    }
    else
    {
        return false;
    }
}

char GamePieces::getPiecesColour()
{
    return this->piecesColour;
}

GamePieces::~GamePieces(){

};
