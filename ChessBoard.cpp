#include "Headers/ChessBoard.h"
//testing
ChessBoard::ChessBoard()
{


    // even for white, odd for black
    this->turn = 0;

    // keeps track if the king and rook have moved
    this->hasKingMovedB = 0;
    this->hasRightRookMovedB = 0;
    this->hasLeftRookMovedB = 0;

    this->hasKingMovedW = 0;
    this->hasRightRookMovedW = 0;
    this->hasLeftRookMovedW = 0;

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
    chessBoard[0][3] = new Queen('b');
    chessBoard[0][4] = new King('b');
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
    int bRow = 0;
    char column = 'a';
    char bColumn = 'h';

    for (int i = 0; i < 9; i++)
    {
        // print the number of 1 to 8
        if (isWhiteTurn() == true)
        {
            if (row == 9)
            {
                cout << "   ";
            }
            else
            {
                cout << "\033[0;33m " << row << "\033[0m"
                     << " ";
            }
        }
        else
        {
            if (bRow == 0)
            {
                cout << "   ";
            }
            else
            {
                cout << "\033[0;33m " << bRow << "\033[0m"
                     << " ";
            }
        }

        for (int j = 0; j < 8; j++)
        {

            // prints the a, b ,c ....
            if (isWhiteTurn() == true)
            {
                if (row == 9)
                {
                    cout << "\033[0;33m " << column << "\033[0m";
                    cout << "  ";
                    column++;
                }
            }
            else
            {
                if (bRow == 0)
                {
                    cout << "\033[0;33m " << bColumn << "\033[0m";
                    cout << "  ";
                    bColumn--;
                }
            }

            // prints the peices on the baord;
            if (row < 9 && column > 0)
            {
                if (chessBoard[i - 1][j] != 0)
                {
                    // checks if the piece colour is black
                    if (chessBoard[i - 1][j]->getPiecesColour() == 'b')
                    {
                        // prints the black pieces
                        cout << "\033[1;33m|\033[0m"
                             << "\033[1;32m" << chessBoard[i - 1][j]->getPieces() << "\033[1;33m| \033[0m";
                    }
                    else
                    {
                        // prints the white peies
                        cout << "\033[1;33m|\033[0m"
                             << "\033[1;37m" << chessBoard[i - 1][j]->getPieces() << "\033[1;33m| \033[0m";
                    }
                }
                else
                {
                    // checks if they are equal to zero
                    if (chessBoard[i - 1][j] == 0)
                    {
                        // prints spaces instead of zeros
                        cout << "\033[1;33m|\033[0m"
                             << " "
                             << "\033[1;33m| \033[0m";
                    }
                }
            }
        }

        bRow++;
        row--;

        cout << endl;

        cout << "\033[0;33m    -   -   -   -   -   -   -   - \033[0m";
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

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp = chessBoard[i][j];
            chessBoard[i][j] = chessBoard[i][7 - j];
            chessBoard[i][7 - j] = temp;
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
        string Player;
        if (isWhiteTurn())
        {
            Player = "White's Turn\n";
            cout << Player;
        }
        else
        {
            Player = "Blacks's Turn\n";
            cout << Player;
        }

        cout << "Coordinates Of The Piece You Want To Move: ";
        cin >> initialPiece;
        if (initialPiece == "exit" || initialPiece == "Exit")
        {
            system("clear");
            exit(0);
        }
        cout << "Coordinates Of Where You Want To Move The Piece To: ";
        cin >> destinationPiece;
        if (destinationPiece == "exit" || destinationPiece == "Exit")
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
                        system("clear");
                        print();
                        cout << "\033[0;36mInvalid Move\033[0m" << endl;
                    }
                }
                else
                {
                    system("clear");
                    print();

                    cout << "\033[0;36mInvalid Move\033[0m" << endl;
                }
            }
            else
            {
                system("clear");
                print();

                cout << "\033[0;36mInvalid Move\033[0m" << endl;
            }
        }
        else
        {
            system("clear");
            print();

            cout << "\033[0;36mInvalid Move\033[0m" << endl;
        }
    }

    // converts the user input into array coordinates
    cNow = initialPiece[0];
    rNow = initialPiece[1];

    cDist = destinationPiece[0];
    rDist = destinationPiece[1];

    if (isWhiteTurn() == true)
    {
        cNow = cNow - 97;
        cDist = cDist - 97;
        rNow = 56 - rNow;
        rDist = 56 - rDist;
    }
    else
    {
        cNow = 104 - cNow;
        cDist = 104 - cDist;
        rNow = rNow - 49;
        rDist = rDist - 49;
    }

    // makes temp pieces
    GamePieces *currentPiece = chessBoard[rNow][cNow];
    GamePieces *temp;

    if (currentPiece == 0)
    {
        system("clear");
        print();
        cout << "\033[0;36mInvalid Move\033[0;0m" << endl;
        validMove = false;
        goto label1;
    }
    printf("\n");
    // checks if the player is moving their own piece

    if (playerColor == currentPiece->getPiecesColour())
    {
        // castling
        if (castling(rDist, cDist, rNow, cNow, chessBoard) == true)
        {
            // white and black have different castling algo
            if (isWhiteTurn() == true)
            {
                // to the left
                if (rDist == 7 && cDist == 2)
                {
                    // change king location
                    chessBoard[7][2] = chessBoard[rNow][cNow];
                    chessBoard[rNow][cNow] = 0;
                    // change rook location
                    chessBoard[7][3] = chessBoard[7][0];
                    chessBoard[7][0] = 0;
                    // check if king is in check
                    bool isKingInCheck = isInCheck();
                    if (isKingInCheck == true)
                    {
                        // switch the places back
                        chessBoard[rNow][cNow] = chessBoard[7][2];
                        chessBoard[7][2] = 0;
                        chessBoard[7][0] = chessBoard[7][3];
                        chessBoard[7][3] = 0;
                        system("clear");
                        print();
                        cout << "\033[0;36mInvalid Move you will be in check\033[0;0m" << endl;
                        validMove = false;
                        // go to the while loop to prompt again
                        goto label1;
                    }
                    else
                    {
                        // if not in check then valid
                        incrementTurn();
                        flipBoard();
                        system("clear");
                    }
                }
                else if (rDist == 7 && cDist == 6)
                {
                    cout << "working" << endl;
                    chessBoard[7][6] = chessBoard[rNow][cNow];
                    chessBoard[rNow][cNow] = 0;
                    chessBoard[7][5] = chessBoard[7][7];
                    chessBoard[7][7] = 0;
                    bool isKingInCheck = isInCheck();
                    if (isKingInCheck == true)
                    {
                        chessBoard[rNow][cNow] = chessBoard[7][6];
                        chessBoard[7][6] = 0;
                        chessBoard[7][7] = chessBoard[7][5];
                        chessBoard[7][5] = 0;
                        system("clear");
                        print();
                        cout << "\033[0;36mInvalid Move\033[0;0m" << endl;
                        validMove = false;
                        goto label1;
                    }
                    else
                    {
                        incrementTurn();
                        flipBoard();
                        system("clear");
                    }
                }
            }
            // castling for black
            else
            {

                if (rDist == 7 && cDist == 1)
                {

                    chessBoard[7][1] = chessBoard[rNow][cNow];
                    chessBoard[rNow][cNow] = 0;
                    chessBoard[7][2] = chessBoard[7][0];
                    chessBoard[7][0] = 0;
                    bool isKingInCheck = isInCheck();
                    if (isKingInCheck == true)
                    {
                        chessBoard[rNow][cNow] = chessBoard[7][1];
                        chessBoard[7][1] = 0;
                        chessBoard[7][0] = chessBoard[7][2];
                        chessBoard[7][2] = 0;
                        system("clear");
                        print();
                        cout << "\033[0;36mInvalid Move you will be in check\033[0;0m" << endl;
                        validMove = false;
                        goto label1;
                    }
                    else
                    {
                        incrementTurn();
                        flipBoard();
                        system("clear");
                    }
                }
                else if (rDist == 7 && cDist == 5)
                {

                    chessBoard[7][5] = chessBoard[rNow][cNow];
                    chessBoard[rNow][cNow] = 0;
                    chessBoard[7][4] = chessBoard[7][7];
                    chessBoard[7][7] = 0;
                    bool isKingInCheck = isInCheck();
                    if (isKingInCheck == true)
                    {
                        chessBoard[rNow][cNow] = chessBoard[7][5];
                        chessBoard[7][5] = 0;
                        chessBoard[7][7] = chessBoard[7][4];
                        chessBoard[7][4] = 0;
                        system("clear");
                        print();
                        cout << "\033[0;36mInvalid Move\033[0;0m" << endl;
                        validMove = false;
                        goto label1;
                    }
                    else
                    {
                        incrementTurn();
                        flipBoard();
                        system("clear");
                    }
                }
            }
        }

        // checks if move is legal to make and then makes the move
        else if (currentPiece->isMoveLegal(rDist, cDist, rNow, cNow, chessBoard))
        {
            if (noCheckAfterMove(rDist, cDist, rNow, cNow, chessBoard) != true)
            {
                if (chessBoard[rNow][cNow] != 0 && chessBoard[rDist][cDist] != 0)
                {
                    if (chessBoard[rNow][cNow]->getPiecesColour() != chessBoard[rDist][cDist]->getPiecesColour())
                    {

                        // promotion
                        if (chessBoard[rNow][cNow]->getPieces() == 'P')
                        {
                            if (promotion(rDist, cDist, rNow, cNow, chessBoard) == true)
                            {
                                chessBoard[rDist][cDist] = chessBoard[rNow][cNow];
                                chessBoard[rNow][cNow] = 0;
                                incrementTurn();
                                flipBoard();
                                system("clear");
                            }
                            else
                            {
                                chessBoard[rDist][cDist] = currentPiece;
                                chessBoard[rNow][cNow] = 0;
                                incrementTurn();
                                flipBoard();
                            }
                        }
                        else
                        {
                            // keeps track if king has moved or not
                            if (chessBoard[rNow][cNow]->getPieces() == 'K')
                            {
                                if (isWhiteTurn() == true)
                                {
                                    this->hasKingMovedW++;
                                }
                                else
                                {
                                    this->hasKingMovedB++;
                                }
                            }

                            // keeps track if left Rook has moved or not

                            if (rNow == 7 && cNow == 0 && chessBoard[rNow][cNow]->getPieces() == 'R')
                            {
                                if (isWhiteTurn() == true)
                                {

                                    this->hasLeftRookMovedW++;
                                }
                                else
                                {
                                    this->hasLeftRookMovedB++;
                                }
                            }

                            // keeps track if Right Rook has moved or not

                            if (rNow == 7 && cNow == 7 && chessBoard[rNow][cNow]->getPieces() == 'R')
                            {
                                if (isWhiteTurn() == true)
                                {
                                    this->hasRightRookMovedW++;
                                }
                                else
                                {
                                    this->hasRightRookMovedB++;
                                }
                            }
                            chessBoard[rDist][cDist] = currentPiece;
                            chessBoard[rNow][cNow] = 0;
                            incrementTurn();
                            flipBoard();
                        }
                    }
                }
                else
                {
                    if (chessBoard[rNow][cNow]->getPieces() == 'P')
                    {
                        if (promotion(rDist, cDist, rNow, cNow, chessBoard) == true)
                        {
                            chessBoard[rDist][cDist] = chessBoard[rNow][cNow];
                            chessBoard[rNow][cNow] = 0;
                            incrementTurn();
                            flipBoard();
                            system("clear");
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

                        if (chessBoard[rNow][cNow]->getPieces() == 'K')
                        {
                            if (isWhiteTurn() == true)
                            {
                                this->hasKingMovedW++;
                            }
                            else
                            {
                                this->hasKingMovedB++;
                            }
                        }

                        // keeps track if left Rook has moved or not

                        if (rNow == 7 && cNow == 0 && chessBoard[rNow][cNow]->getPieces() == 'R')
                        {
                            if (isWhiteTurn() == true)
                            {

                                this->hasLeftRookMovedW++;
                            }
                            else
                            {
                                this->hasLeftRookMovedB++;
                            }
                        }

                        // keeps track if Right Rook has moved or not

                        if (rNow == 7 && cNow == 7 && chessBoard[rNow][cNow]->getPieces() == 'R')
                        {
                            if (isWhiteTurn() == true)
                            {
                                this->hasRightRookMovedW++;
                            }
                            else
                            {
                                this->hasRightRookMovedB++;
                            }
                        }

                        temp = chessBoard[rNow][cNow];
                        chessBoard[rNow][cNow] = chessBoard[rDist][cDist];
                        chessBoard[rDist][cDist] = temp;
                        incrementTurn();
                        flipBoard();
                    }
                }
            }
            else
            {
                system("clear");
                print();
                cout << "\033[0;36mInvalid Move You Will Be In Check\033[0;0m" << endl;
                validMove = false;
                goto label1;
            }
        }
        else
        {
            system("clear");
            print();
            cout << "\033[0;36mInvalid Move\033[0;0m" << endl;
            validMove = false;
            goto label1;
        }
    }
    else
    {
        system("clear");
        print();
        cout << "\033[0;36mInvalid Move\033[0;0m" << endl;
        validMove = false;
        goto label1;
    }
    system("clear");
}

bool ChessBoard::noCheckAfterMove(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    GamePieces *tempMove = chessBoard[rDest][cDest];
    chessBoard[rDest][cDest] = chessBoard[rNow][cNow];
    chessBoard[rNow][cNow] = 0;

    bool thereIsAMove = isInCheck();

    chessBoard[rNow][cNow] = chessBoard[rDest][cDest];
    chessBoard[rDest][cDest] = tempMove;

    if (thereIsAMove == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool ChessBoard::stalemate(int rKing, int cKing, GamePieces *ChessBoard[8][8])
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessBoard[i][j] == 0)
            {
                if (chessBoard[rKing][cKing]->isMoveLegal(i, j, rKing, cKing, chessBoard) == true)
                {
                    if (ifPieceCanBeTaken(i, j, chessBoard) == true)
                    {
                        count++;
                    }
                }
            }
        }
    }

    if (rKing == 7 && cKing == 0)
    {
        if (count > 2)
        {
            return true;
        }
    }
    else if (rKing == 7 && cKing == 7)
    {
        if (count > 2)
        {
            return true;
        }
    }
    else if (rKing == 0 && cKing == 0)
    {
        if (count > 2)
        {
            return true;
        }
    }
    else if (rKing == 0 && cKing == 7)
    {
        if (count > 2)
        {
            return true;
        }
    }

    if (count == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ChessBoard::castling(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    if (isWhiteTurn() == true)
    {
        // to the right
        if (rNow == 7 && cNow == 4)
        {
            if (rNow == 7 && cNow == 4 && rDest == 7 && cDest == 6)
            {
                if (chessBoard[7][5] == 0 && chessBoard[7][6] == 0)
                {
                    if (hasKingMovedW == 0 && hasRightRookMovedW == 0)
                    {
                        return true;
                    }
                }
            }
        }

        // to the left
        if (rNow == 7 && cNow == 4)
        {
            if (rNow == 7 && cNow == 4 && rDest == 7 && cDest == 2)
            {

                if (chessBoard[7][1] == 0 && chessBoard[7][2] == 0 && chessBoard[7][3] == 0)
                {
                    if (hasKingMovedW == 0 && hasLeftRookMovedW == 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    // does the same thing for black
    else
    {

        if (rNow == 7 && cNow == 3)
        {
            if (rNow == 7 && cNow == 3 && rDest == 7 && cDest == 5)
            {

                if (chessBoard[7][4] == 0 && chessBoard[7][5] == 0 && chessBoard[7][6] == 0)
                {
                    if (hasKingMovedB == 0 && hasRightRookMovedB == 0)
                    {
                        return true;
                    }
                }
            }
        }

        if (rNow == 7 && cNow == 3)
        {
            if (rNow == 7 && cNow == 3 && rDest == 7 && cDest == 1)
            {
                if (chessBoard[7][1] == 0 && chessBoard[7][2] == 0)
                {
                    if (hasKingMovedB == 0 && hasLeftRookMovedB == 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    // return false
    return false;
}

bool ChessBoard::promotion(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{
    if (rNow == 1 && rDest == 0)
    {
    label2:

        char piece;
        cout << "Chose a new piece (N,Q,R,B): ";
        cin >> piece;
        switch (piece)
        {
        case 'N':
            ChessBoard[rNow][cNow] = new Knight(playerColor);
            return true;
            break;
        case 'Q':
            ChessBoard[rNow][cNow] = new Queen(playerColor);
            cout << "working" << endl;
            return true;
            break;
        case 'R':
            ChessBoard[rNow][cNow] = new Rook(playerColor);
            return true;
            break;
        case 'B':
            ChessBoard[rNow][cNow] = new Bishop(playerColor);
            return true;
            break;

        default:
            system("clear");
            print();
            cout << "\033[0;36mInvalid Piece\033[0;0m" << endl;
            goto label2;
            break;
        }
    }
    return false;
}

bool ChessBoard::isInCheck()
{
    // Find the location of the king of the player's color
    int rKing, cKing;

    if (isWhiteTurn() == true)
    {
        this->playerColor = 'w';
        this->opponentColor = 'b';
    }
    else
    {
        this->playerColor = 'b';
        this->opponentColor = 'w';
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
    bool staleMate = stalemate(rKing, cKing, chessBoard);

    if (staleMate == true)
    {
        cout << "\033[0;36mDRAW STALAMATE\033[0;0m" << endl;
        exit(0);
    }

    // Check if any of the opponent's pieces can attack the king
    if (ifPieceCanBeTaken(rKing, cKing, chessBoard) == true)
    {
        return true;
    }

    cout << endl;

    return false; // King is not in check
}

bool ChessBoard::ifPieceCanBeTaken(int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessBoard[i][j] != 0 && chessBoard[i][j]->getPiecesColour() == opponentColor)
            {
                if (chessBoard[i][j]->isMoveLegal(rNow, cNow, i, j, chessBoard) == true)
                {
                    return true; // can be taken
                }
            }
        }
    }
    return false;
}

bool ChessBoard::checkMate()
{
    if (isInCheck())
    {

        for (int rowCurrent = 0; rowCurrent < 8; ++rowCurrent)
        {
            for (int columnCurrent = 0; columnCurrent < 8; ++columnCurrent)
            {
                if (chessBoard[rowCurrent][columnCurrent] != 0)
                {

                    if (chessBoard[rowCurrent][columnCurrent]->getPiecesColour() == playerColor)
                    {
                        for (int row = 0; row < 8; ++row)
                        {
                            for (int col = 0; col < 8; ++col)
                            {
                                if (chessBoard[rowCurrent][columnCurrent]->isMoveLegal(row, col, rowCurrent, columnCurrent, chessBoard))
                                {

                                    GamePieces *tempMove = chessBoard[row][col];
                                    chessBoard[row][col] = chessBoard[rowCurrent][columnCurrent];
                                    chessBoard[rowCurrent][columnCurrent] = 0;

                                    bool thereIsAMove = isInCheck();

                                    chessBoard[rowCurrent][columnCurrent] = chessBoard[row][col];
                                    chessBoard[row][col] = tempMove;

                                    if (!thereIsAMove)
                                    {
                                        cout << "\033[0;36m||CHECK||\033[0;0m" << endl;
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (isWhiteTurn() == true)
        {
            cout << endl
                 << "\033[0;36m||WHITE LOST CHECKMATE||\033[0;0m" << endl;
            return true;
        }
        else
        {
            cout << endl
                 << "\033[0;36m||BLACK LOST CHECKMATE||\033[0;0m" << endl;
            return true;
        }
    }
    else
    {
        return false;
    }
}

void ChessBoard::start()
{

    print();

    bool gameOver = false;

    do
    {

        if (checkMate())
        {
            gameOver = true;
            break;
        }

        makesTheMove();
        print();

    } while (!gameOver);
}
