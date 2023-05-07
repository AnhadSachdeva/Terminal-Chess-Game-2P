#include "Headers/Rook.h"

Rook::Rook()
{
}

Rook::Rook(char Colour) : GamePieces(Colour)
{
}

char Rook::getPieces()
{
    return 'R';
}

bool Rook::isMoveLegalForPiece(int rDest, int cDest, int rNow, int cNow, GamePieces *ChessBoard[8][8])
{

    GamePieces *test = ChessBoard[rDest][cDest];

    int checkRow = rDest - rNow;
    int checkColoumn = cDest - cNow;

    int scalarRDest = abs(rDest - rNow);
    int scalarCDest = abs(cDest - cNow);

    if (test == 0)
    {

        if (scalarRDest == 0 || scalarCDest == 0)
        {
               if (noPieceInBetween(checkRow,checkColoumn,scalarRDest,scalarCDest,rNow,cNow,ChessBoard) == true){
                return true;
            }
 
        }
    }
    else if (scalarRDest == 0 || scalarCDest == 0 && test->getPiecesColour() != ChessBoard[rNow][cNow]->getPiecesColour())
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

bool Rook::noPieceInBetween(int checkRow, int checkColoumn, int scalarRDest, int scalarCDest, int rNow, int cNow,GamePieces *ChessBoard[8][8]){
           // check there is no piecee in between when the rook moves up
            if (checkRow < 0 && checkColoumn == 0)
            {
                for (int i = 1; i < scalarRDest; i++)
                {
                    if (ChessBoard[rNow - i][cNow] != 0)
                    {
                        return false;
                    }
                }
            }
            // check there is no piecee in between when the rook moves down
            if (checkRow > 0 && checkColoumn == 0)
            {
                for (int i = 1; i < scalarRDest; i++)
                {
                    if (ChessBoard[rNow + i][cNow] != 0)
                    {
                        return false;
                    }
                }
            }
            // check there is no piecee in between when the rook moves left

            if (checkRow == 0 && checkColoumn < 0)
            {
                for (int i = 1; i < scalarCDest; i++)
                {
                    if (ChessBoard[rNow][cNow - i] != 0)
                    {
                        return false;
                    }
                }
            }
            // check there is no piecee in between when the rook right

            if (checkRow == 0 && checkColoumn > 0)
            {
                for (int i = 1; i < scalarCDest; i++)
                {
                    if (ChessBoard[rNow][cNow + i] != 0)
                    {
                        return false;
                    }
                }
            }
            return true;


    }
