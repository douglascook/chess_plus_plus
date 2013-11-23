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
        std::map<std::vector<int>, Piece*> positions;

        // whose turn it is
        bool whiteTurn;

        // if either player is in check
        int inCheck;


        // check if move is valid
        bool validateMove(std::vector<int> startPos, std::vector<int> endPos);

        // update position of piece
        void updatePosition(std::vector<int> startPos, std::vector<int> endPos);

    public:
        // reset pieces to starting positions
        void resetBoard();

        // take in start and end positions on board
        void submitMove(std::string startPos, std::string endPos);

        // check if piece is in given position and return colour or neither
        int checkForPiece(std::vector<int> position);

        // constructor, needs to set up board
        ChessBoard();
};

#endif
