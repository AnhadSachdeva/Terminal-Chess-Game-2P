#include "Bishop.h"

Bishop::Bishop()
{
}

Bishop::Bishop(char Colour) : GamePieces(Colour)
{
}

char Bishop::getPieces()
{
    return 'B';
}

bool Bishop::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    GamePieces *test = ChessBoard[rDest][cDest];

    int checkRow = rDest - rNow;
    int checkColoumn = cDest - cNow;

    int scalarRDest = abs(rDest - rNow);
    int scalarCDest = abs(cDest - cNow);

    if (test == 0)
    {

        if (scalarRDest == scalarCDest)
        {
            // check there is no piecee in between to the left diagonal
            if (noPieceInBetween(checkRow,checkColoumn,scalarRDest,scalarCDest,rNow,cNow,ChessBoard) == true){
                return true;
            }
        }
    }
    else if (scalarRDest == scalarCDest && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
    {
             if (noPieceInBetween(checkRow,checkColoumn,scalarRDest,scalarCDest,rNow,cNow,ChessBoard) == true){
                return true;
            }
    }
    else
    {

        return false;
    }
    return false;
}

 bool Bishop::noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow, GamePieces *ChessBoard[8][8]){

            if (checkRow < 0 && checkColoumn < 0)
            {
                for (int i = 1; i < scalarRDest; i++)
                {
                    if (ChessBoard[rNow - i][cNow - i] != 0)
                    {
                        return false;
                    }
                }
            }
            // check there is no piecee in between to the right diagonal
            if (checkRow < 0 && checkColoumn > 0)
            {
                for (int i = 1; i < scalarRDest; i++)
                {
                    if (ChessBoard[rNow - i][cNow + i] != 0)
                    {
                        return false;
                    }
                }
            }
            // check there is no piecee in between to the bottom-left diagonal

            if (checkRow > 0 && checkColoumn > 0)
            {
                for (int i = 1; i < scalarRDest; i++)
                {
                    if (ChessBoard[rNow + i][cNow + i] != 0)
                    {
                        return false;
                    }
                }
            }
            // check there is no piecee in between to the bottom-right diagonal

            if (checkRow > 0 && checkColoumn < 0)
            {
                for (int i = 1; i < scalarRDest; i++)
                {
                    if (ChessBoard[rNow + i][cNow - i] != 0)
                    {
                        return false;
                    }
                }
            }

            return true;
    
 }