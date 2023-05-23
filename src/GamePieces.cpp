#include "../Headers/GamePieces.h"

GamePieces::GamePieces()
{
}

GamePieces::GamePieces(char piecesColour)
{
    this->piecesColour = piecesColour;
}

bool GamePieces::isMoveLegal(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    /*
        The Co-ordinates of the Piece that the User wants to Move:
          "rNow" = current row
          "cNow" = current coloumn

        The Co-ordinates of the Destination where the User wants move the Piece to:
          "rDest" = row destination
          "cDest" = coloumn destination

    */

    // Makes a Test Piece on the Destination that we Want to Move the Piece On
    GamePieces *check = ChessBoard[rDest][cDest];

    // Checks if that Destination is Empty or has an Opponent's Piece
    if (check == 0 || check->getPiecesColour() != this->piecesColour)
    {
        // Checkes if the Move is Legal for the Piece
        //pure virtual function
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
