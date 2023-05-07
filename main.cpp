#include "Headers/ChessBoard.h"
#include "Headers/ChessGame.h"
#include "Headers/GamePieces.h"
#include "Headers/Player.h"
#include "Headers/King.h"
#include "Headers/Knight.h"
#include "Headers/Rook.h"
#include "Headers/Bishop.h"
#include "Headers/Queen.h"
#include "Headers/Pawn.h"

#include <iostream>

using namespace std;

int main()
{

    //   ChessGame game;
    string playerName1;
    string playerName2;

    cout << "-----------Welcome to the Chess Game-------------" << endl;

    cout << "Enter the player 1 name: ";
    cin >> playerName1;

    cout << "Enter the player 2 name: ";
    cin >> playerName2;

    Player player1(playerName1, 'w');
    Player player2(playerName2, 'b');

    cout << "Player 1: " << playerName1 << " is playing as \033[1;37mWHITE\033[0m" << endl;
    cout << "Player 2: " << playerName2 << " is playing as \033[1;30mBLACK\033[0m" << endl;

    cout << "-------------------------------------------------" << endl;

    cout << "The game has started" << endl;

    ChessBoard chess;
    chess.print();
    int turn = 0;

    for (int i = 0; i < 10; i++)
    {
        if (chess.isInCheck() == true)
        {
            cout << "!!Check!!" << endl;
            cout << "Game Over" << endl;
            break;
        }
        else
        {
            chess.makesTheMove();
            chess.print();
            chess.incrementTurn(turn);
        }
    }

    return 0;
}
