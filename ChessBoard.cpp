#include "Headers/ChessBoard.h"
#include "Headers/Player.h"

ChessBoard::ChessBoard()
{
    // even for white, odd for black
    this->turn = 0;

    // intialises the board to all zeros
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessBoard[i][j] = 0;
        }
    }

    // initialise black pieces
    for (int i = 0; i < 8; i++)
    {
        chessBoard[1][i] = new Pawn('b');
    }
    chessBoard[0][0] = new Rook('b');
    chessBoard[0][1] = new Knight('b');
    chessBoard[0][2] = new Bishop('b');
    chessBoard[0][3] = new King('b');
    chessBoard[0][4] = new Queen('b');
    chessBoard[0][5] = new Bishop('b');
    chessBoard[0][6] = new Knight('b');
    chessBoard[0][7] = new Rook('b');

    // initialise white pieces pieces
    for (int i = 0; i < 8; i++)
    {
        chessBoard[6][i] = new Pawn('w');
    }
    chessBoard[7][0] = new Rook('w');
    chessBoard[7][1] = new Knight('w');
    chessBoard[7][2] = new Bishop('w');
    chessBoard[7][3] = new Queen('w');
    chessBoard[7][4] = new King('w');
    chessBoard[7][5] = new Bishop('w');
    chessBoard[7][6] = new Knight('w');
    chessBoard[7][7] = new Rook('w');
}

ChessBoard::~ChessBoard()
{
    // deletes the pieces on the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete chessBoard[i][j];
        }
    }
}

void ChessBoard::incrementTurn()
{
    // increments the turn
    this->turn = turn + 1;
}

bool ChessBoard::isWhiteTurn()
{
    // checks if turn is divisible by 2 then it is whites turn
    if (turn % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ChessBoard::print()
{
    // prints the design of the board

    int row = 9;
    char coloumn = 'a';

    for (int i = 0; i < 9; i++)
    {
        // print the number of 1 to 8
        if (row == 9)
        {
            cout << "    ";
        }
        else
        {
            cout << "\033[0;33m " << row << "\033[0m"
                 << " ";
        }

        for (int j = 0; j < 8; j++)
        {
            // prints the a, b ,c ....
            if (row == 9)
            {
                cout << "\033[0;33m " << coloumn << "\033[0m";
                cout << "   ";
                coloumn++;
            }

            // prints the peices on the baord;
            if (row < 9 && coloumn > 0)
            {
                if (chessBoard[i - 1][j] != 0)
                {
                    // checks if the piece colour is black
                    if (chessBoard[i - 1][j]->getPiecesColour() == 'b')
                    {
                        // prints the black pieces
                        cout << "\033[1;33m|\033[0m"
                             << "\033[1;32m" << chessBoard[i - 1][j]->getPiecesColour() << chessBoard[i - 1][j]->getPieces() << "\033[1;33m| \033[0m";
                    }
                    else
                    {
                        // prints the white peies
                        cout << "\033[1;33m|\033[0m"
                             << "\033[1;37m" << chessBoard[i - 1][j]->getPiecesColour() << chessBoard[i - 1][j]->getPieces() << "\033[1;33m| \033[0m";
                    }
                }
                else
                {
                    // checks if they are equal to zero
                    if (chessBoard[i - 1][j] == 0)
                    {
                        // prints spaces instead of zeros
                        cout << "\033[1;33m|\033[0m"
                             << "  "
                             << "\033[1;33m| \033[0m";
                    }
                }
            }
        }

        row--;
        cout << endl;

        cout << "\033[0;33m    --   --   --   --   --   --   --   --\033[0m";
        cout << endl;
    }
}

void ChessBoard::flipBoard()
{

    // flips the locaiton of the board

    GamePieces *temp;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            temp = chessBoard[i][j];
            chessBoard[i][j] = chessBoard[7 - i][j];
            chessBoard[7 - i][j] = temp;
        }
    }
}

void ChessBoard::makesTheMove()
{

    // the coordinates of the piece the user wants to move
    //  "rNow" = current row
    //  "cNow" = current coloumnc

    // the coordinates of the place where the user wants to move the piece to
    // "rDist" = row destination
    // "cDist" = coloumn destination

    int rDist, cDist, rNow, cNow;

    // stores the user input in here
    string initialPiece, destinationPiece;

    // takes user input
    bool validMove;
label1:
    while (validMove == false)
    {

        cout << "Coordinates Of The Piece You Want To Move: ";
        cin >> initialPiece;
        cout << "Coordinates Of Where You Want To Move The Piece To: ";
        cin >> destinationPiece;

        // ends the game
        if (initialPiece == "kill" && destinationPiece == "kill")
        {
            system("clear");
            exit(0);
        }

        // checks if the user made a valid move
        if (initialPiece[0] >= 'a' && initialPiece[0] <= 'h')
        {
            if (initialPiece[1] >= 49 && initialPiece[1] <= 56)
            {
                if (destinationPiece[0] >= 'a' && destinationPiece[0] <= 'h')
                {
                    if (destinationPiece[1] >= 49 && destinationPiece[1] <= 56)
                    {
                        validMove = true;
                    }
                    else
                    {
                        cout << "\033[0;36mInvalid Move Please Try Again\033[0m" << endl;
                    }
                }
                else
                {
                    cout << "\033[0;36mInvalid Move Please Try Again\033[0m" << endl;
                }
            }
            else
            {
                cout << "\033[0;36mInvalid Move Please Try Again\033[0m" << endl;
            }
        }
        else
        {
            cout << "\033[0;36mInvalid Move Please Try Again\033[0m" << endl;
        }
    }

    // converts the user input into array coordinates
    cNow = initialPiece[0];
    rNow = initialPiece[1];

    cDist = destinationPiece[0];
    rDist = destinationPiece[1];

    cNow = cNow - 97;
    cDist = cDist - 97;
    rNow = 56 - rNow;
    rDist = 56 - rDist;

    // checks if the user picked a empty block then prompts the user again
    bool check = false;
    while (check == false)
    {
        if (chessBoard[rNow][cNow] == 0)
        {
            system("clear");
            print();
            cout << "\033[0;36mInvalid Move Please Try Again\033[0m" << endl;
            validMove = false;
            goto label1;
        }
        else
        {
            check = true;
            system("clear");
        }
    }

    // makes temp pieces
    GamePieces *currentPiece = chessBoard[rNow][cNow];
    GamePieces *temp;

    // checks if the player is moving their own piece
    if (playerColor == currentPiece->getPiecesColour())
    {
        // checks if move is legal to make and then makes the move
        if (currentPiece->isMoveLegal(rDist, cDist, rNow, cNow, chessBoard))
        {
            if (chessBoard[rNow][cNow] != 0 && chessBoard[rDist][cDist] != 0)
            {
                if (chessBoard[rNow][cNow]->getPiecesColour() != chessBoard[rDist][cDist]->getPiecesColour())
                {

                    chessBoard[rDist][cDist] = currentPiece;
                    chessBoard[rNow][cNow] = 0;
                    incrementTurn();
                    flipBoard();
                }
            }
            else
            {
                temp = chessBoard[rNow][cNow];
                chessBoard[rNow][cNow] = chessBoard[rDist][cDist];
                chessBoard[rDist][cDist] = temp;
                incrementTurn();
                flipBoard();
            }
        }
        else
        {

            cout << "\033[0;36mInvalid Move Please Try Again\033[0m" << endl;
        }
    }
    // if the user didnt pick their own piece tells the user to pick your own piece
    else
        {


        cout << "\033[0;36mPlease Chose Your Own Piece\033[0m" << endl;
        }
}

bool ChessBoard::isInCheck()
{
    // Find the location of the king of the player's color
    int rKing, cKing;

    if (isWhiteTurn() == true)
    {
        this->playerColor = 'w';
        this->opponentColor = 'b';
        cout << "White's Turn";
    }
    else
    {
        this->playerColor = 'b';
        this->opponentColor = 'w';
        cout << "Black's Turn";
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessBoard[i][j] != 0 && chessBoard[i][j]->getPieces() == 'K' && chessBoard[i][j]->getPiecesColour() == playerColor)
            {

                rKing = i;
                cKing = j;

                break;
            }
        }
    }

    // Check if any of the opponent's pieces can attack the king
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessBoard[i][j] != 0)
            {

                if (chessBoard[i][j]->isMoveLegal(rKing, cKing, i, j, chessBoard) == true)
                {

                    return true; // King is in check
                }
            }
        }
    }
    cout << endl;

    return false; // King is not in check
}

bool ChessBoard::stalemate()
{

    // finds the king and check the squares around it

    return false;
}

bool ChessBoard::checkMate()
{

    // if king is in check then check for stalemate
    // checks if any piece can take the piece that has checked the piece

    // if they both true means that king is checkmated
    return false;
}

void ChessBoard::start()
{

    // need to change this to while look
    print();

    for (int i = 0; i < 10; i++)
    {
        if (isInCheck() == true)
        {
            cout << endl;
            cout << "!!Check!!" << endl;
            cout << "Game Over" << endl;
            break;
        }
        else
        {
            makesTheMove();
            print();
        }
    }
}
