# Terminal Chess Game

This implementation of a two-player terminal chess game follows
object-oriented programming principles. The game includes various
features such as checkmate and check detection, validation of moves,
handling invalid moves while in check, promotion, castling, and stalemate.
For instance, if a player is in check, they can only move the pieces
that prevent them from remaining in check.

Furthermore, it is recommended to play this game in black-background terminal.

Piece Notation:

```bash
P - Pawn ,
N - Knight ,
K - King ,
Q - Queen ,
B - Bishop ,
R - Rook
```


```bash
    To compile the code and run it
        ./chess.sh
    Or 
        cd src
        g++ *.cpp -o chess.exe
        .\chess.exe 
       
    To exit the game, simply enter "exit" in the terminal.

    When a pawn reaches the last square, the user will be prompted with
    the message: "Pick a Piece (N, Q, B, R):". 
    The user needs to input the corresponding notation for the desired piece, such as: 
    "Q" for Queen, "N" for Knight, "B" for Bishop, "R" for Rook to promote the pawn to that piece.  
```



This only works on MacOS
To restart the game, simply enter "restart" in the terminal

## Note: You may need to change the "clearScreen" variable in the ChessBoard class, if your Terminal/CommandPrompt only accepts "clear" and not "cls".



Areas for further improvement:

    En Passant rule implementation.

    Scoring system to keep track of the game's progress and player
    performance.

    Keeping track of captured pieces during the game.

    Recording and storing moves, allowing the game to be saved and
    resumed later.



Thank you once again for trying out this game. I want to note that this was
my first coding project ever. While I understand that this may not be the most
optimized version of chess, it fulfills its purpose effectively.

Authors
Anhad Sachdeva
Shyamsundar Shrestha

