#ifndef GAMEPIECES_H
#define GAMEPIECES_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>

#include "Player.h"



class GamePieces : public Player
{

protected:
    //either a piece can be 'b' for black or 'w' for white
    char piecesColour;

public:

    GamePieces();

    //parameterized constructor to set the colour of the pieces
    GamePieces(char piecesColour);

    // used as an ID to differentiate between pieces
    virtual char getPieces() = 0;

    // checks if the move is in the board
    // then returns the values to isMoveLegalForPiece to check if the piece can legally complete that move
    bool isMoveLegal(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);

    // checks if the peice can move if it can then it returns true
    virtual bool isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]) = 0;
   
   //returns the colour of a specific piece
    char getPiecesColour();

    //deletes the memory of different pieces
    virtual ~GamePieces();

};

#endif
