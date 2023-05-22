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
    // an 8x8 matrix/array of gamepiece pointers
    GamePieces *chessBoard[8][8];
    // counts the total number of turns that has happened
    int turn;
    // stores the player colour
    char playerColor;
    // stores the opponents colour
    char opponentColor;

    int hasKingMovedB;
    int hasRightRookMovedB;
    int hasLeftRookMovedB;


    int hasKingMovedW;
    int hasRightRookMovedW;
    int hasLeftRookMovedW;
    

public:
    // initialises the pieces on the baord
    ChessBoard();

    //deletes the dynamic memory
    ~ChessBoard();

    //everytime a valid move is perfomed it increases the turn
    void incrementTurn(); 

    //checks if it is either whites or blacks turn
    bool isWhiteTurn();  

    //starts the game the main while loop goes here
    void start();

    //prints the pieces and baord layout
    void print();

    //takes user input and see if it valid and then makes a legal move
    void makesTheMove();

    //flips the board after each players turn
    void flipBoard();

    //checks if king is in check
    bool isInCheck();

    bool noCheckAfterMove(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);
    //determines who won
    bool checkMate();

    bool promotion(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);

    bool castling(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);

    bool stalemate(int rKing,int cKing, GamePieces *ChessBoard[8][8]);

    bool ifPieceCanBeTaken(int rNow,int cNow, GamePieces *ChessBoard[8][8]);
};

#endif