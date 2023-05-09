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
    //the coordinates of the piece the user wants to move
    // "rNow" = current row
    // "cNow" = current coloumnc


    // the coordinates of the place where the user wants to move the piece to
    // "rDest" = row destination
    // "cDest" = coloumn destination

    
    // makes a test piece on the destination we want to move the piece on
    GamePieces *check = ChessBoard[rDest][cDest];

    //checks if that place is empty or is on an opponent piece
    if (check == 0 || check->getPiecesColour() != this->piecesColour)
    {
        //now checks if the move is legal for the piece
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
