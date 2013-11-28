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

class ChessBoard
{
    private:
        // map holding the current positions of pieces on the board
        // key is the coords, value is a pointer to a piece
        std::map<std::string, Piece*> positions;

        // whose turn it is
        Colour whoseTurn;

        // if either player is in check
        Colour inCheck;

        std::vector<std::string> kings;

        // update move vectors for all pieces
        void updateValidMoves();

        // check if move is valid
        bool validateMove(std::string startPos, std::string endPos);

        // update position of piece
        void updatePosition(std::string startPos, std::string endPos);

        // check if player is in check
        bool playerInCheck(std::string king);

    public:
        // reset pieces to starting positions
        void resetBoard();

        // check if given position is on board
        bool onBoard(std::string position);

        // take in start and end positions on board
        void submitMove(std::string startPos, std::string endPos);

        // check if piece is in given position and return colour or neither
        Colour checkForPiece(std::string startPos);

        // for testing purposes
        void printBoard();

        // constructor, needs to set up board
        ChessBoard();
};

#endif
