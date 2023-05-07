#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "GamePieces.h"
#include "Player.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"

class ChessBoard
{

protected:
    GamePieces *chessBoard[8][8];
    int turn;

public:
    ChessBoard();
    ~ChessBoard();

    void incrementTurn(); // increments the turn by 1
    bool isWhiteTurn();   // checks if it is white's turn

    void print();
    void makesTheMove();
    void flipBoard();

    bool isInCheck();

    // need to do:
    //  implement check logic, if king is in check
    // bool GameOver(); // implement checkmate logic, king cannot move to another piece
    // bool Draw(); // implement draw logic, if king is not in check and cannot move
    // void start(); // check if game over is false, then it runs the while loop // Start the game

    // btw there are function to get the color and piece id so look into it:
    //  getPieceColor() // returns 'b' for black or 'w' for white
    //  getPieces() // returns 'K' for King, 'Q' for Queen, 'R' for Rook, 'B' for Bishop, 'N' for Knight, 'P' for Pawn
};

#endif