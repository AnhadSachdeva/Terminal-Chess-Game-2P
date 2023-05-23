/*
    This is the header file of ChessBoard Class
    ChessBoard class is responsible for the chessboard and the interaction of pieces on it
*/

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


    // to check if castling valid or not  
    int hasKingMovedB;
    int hasRightRookMovedB;
    int hasLeftRookMovedB;

    int hasKingMovedW;
    int hasRightRookMovedW;
    int hasLeftRookMovedW;

public:
    // initialises the pieces on the baord
    ChessBoard();

    // deletes the dynamic memory
    ~ChessBoard();

    // increases the turn by 1 after each player has made its valid move
    void incrementTurn();

    // checks if it is either whites or blacks turn
    bool isWhiteTurn();

    // prints the pieces and baord layout
    void print();

    // takes the user input and see if it valid and then makes a legal move
    void makesTheMove();

    // flips the board after each players turn
    void flipBoard();

    // checks if the piece can be taken or not
    bool ifPieceCanBeTaken(int rNow, int cNow, GamePieces *ChessBoard[8][8]);

    // checks if king is in check
    bool isInCheck();

    // checks if the King is not in check, after the player made its move
    bool noCheckAfterMove(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);

    // checks if the No piece can move when the king is not in check
    bool stalemate(int rKing, int cKing, GamePieces *ChessBoard[8][8]);

    // checks if it is checkmate, thus game is over
    bool checkMate();

    // Special Moves

    // Promotes the pawn if the valid condition of pawn promotion is met
    bool promotion(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);

    // Castles the king with rook if the valid condition of castling is met
    bool castling(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]);

    //

    // starts the game the main while loop goes here
    void start();
};

#endif