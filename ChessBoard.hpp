#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <map>
#include <string>
#include <vector>

#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

// iterator needed to loop through pieces on the board
typedef std::map<std::string, Piece*>::iterator pieceIterator;

class ChessBoard
{
    private:
        // map holding the current positions of pieces on the board
        std::map<std::string, Piece*> positions;
        // whose turn it is
        Colour whoseTurn;
        // if the game has finished
        bool gameOver;
        // positions of the kings
        std::vector<std::string> kings;

        // update move vectors for all pieces
        void updateValidMoves();
        // overloaded version, only update moves for one colour
        void updateValidMoves(Colour player);
        // check if move is valid
        bool validateMove(std::string startPos, std::string endPos);
        // update position of piece
        void updatePosition(std::string startPos, std::string endPos, Piece*& takenPiece);
        // check if player is in check
        bool playerInCheck();
        // check if there are any valid moves, return true for stalemate or checkmate
        bool mateCheck();
        // convert colour enum to string
        std::string printColour(Colour colour);
        // clean up pieces left over from previous game
        void deletePieces();

    public:
        // reset pieces to starting positions
        void resetBoard();
        // process given move 
        void submitMove(std::string startPos, std::string endPos);
        // check if a piece is in given position and return colour or no piece
        Colour checkForPiece(std::string startPos);
        // check if given position is on board
        bool onBoard(std::string position);
        // return colour of opponent
        static Colour otherPlayer(Colour player);

        // constructor, needs to set up board
        ChessBoard();
        // destructor needs to destroy any remaining pieces
        ~ChessBoard();
};

#endif
