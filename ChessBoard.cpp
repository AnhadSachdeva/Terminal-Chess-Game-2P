#include "Headers/ChessBoard.h"

ChessBoard::ChessBoard()
{
    this->turn = 0; // even for white, odd for black

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

    this->turn = turn + 1;
}

bool ChessBoard::isWhiteTurn()
{

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
    // to visualise the address instead of
    //       for (int i = 0; i < 8; i++)
    //  {
    //       for (int j = 0; j < 8; j++)
    //  {
    //      cout << &chessBoard[i][j];
    //  }
    //  cout<<endl;
    //  }

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
            cout << "\033[1;32m " << row << "\033[0m"
                 << " ";
        }

        for (int j = 0; j < 8; j++)
        {
            // prints the a, b ,c ....
            if (row == 9)
            {
                cout << "\033[1;32m " << coloumn << "\033[0m";
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
                             << "\033[1;30m" << chessBoard[i - 1][j]->getPiecesColour() << chessBoard[i - 1][j]->getPieces() << "\033[1;33m| \033[0m";
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

// chessgame
void ChessBoard::flipBoard()
{

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

    int rDist, cDist, rNow, cNow;

    string initialPiece, destinationPiece;

    bool validMove;

    while (validMove == false)
    {

        cout << "Enter the piece you want to move: ";
        cin >> initialPiece;
        cout << "Enter the destination you want to move to: ";
        cin >> destinationPiece;

        if (initialPiece == "kill" && destinationPiece == "kill")
        {
            break;
        }

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
                        cout << "invalid move please try again" << endl;
                    }
                }
                else
                {
                    cout << "invalid move please try again" << endl;
                }
            }
            else
            {
                cout << "invalid move please try again" << endl;
            }
        }
        else
        {
            cout << "invalid move please try again" << endl;
        }
    }

    cNow = initialPiece[0];
    rNow = initialPiece[1];

    cDist = destinationPiece[0];
    rDist = destinationPiece[1];

    cNow = cNow - 97;
    cDist = cDist - 97;
    rNow = 56 - rNow;
    rDist = 56 - rDist;

    // from code line 451 to 530 it changes the input into array coordinates

    // just a quick code to test if the peices moves
    // do e2 to e4 to test if you want
    // but this needs a proper implementation with if statemnets to check if move is legal and will take the peice or replace it
    // this just replaces it

    GamePieces *currentPiece = chessBoard[rNow][cNow];
    GamePieces *temp;

    if (currentPiece->isMoveLegal(rDist, cDist, rNow, cNow, chessBoard))
    {
        if (chessBoard[rNow][cNow] != 0 && chessBoard[rDist][cDist] != 0)
        {
            if (chessBoard[rNow][cNow]->getPiecesColour() != chessBoard[rDist][cDist]->getPiecesColour())
            {

                chessBoard[rDist][cDist] = currentPiece;
                chessBoard[rNow][cNow] = 0;
                flipBoard();
            }
        }
        else
        {
            temp = chessBoard[rNow][cNow];
            chessBoard[rNow][cNow] = chessBoard[rDist][cDist];
            chessBoard[rDist][cDist] = temp;
            flipBoard();
        }
    }
    else
    {
        cout << "invalid move" << endl;
    }
}

bool ChessBoard::isInCheck()
{
    // Find the location of the king of the player's color
    int rKing, cKing;
    char playerColor;
    char opponentColor;

    if (isWhiteTurn() == true)
    {
        playerColor = 'w';
        opponentColor = 'b';
    }
    else
    {
        playerColor = 'b';
        opponentColor = 'w';
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
