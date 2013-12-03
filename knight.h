#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece
{
    public:
        // create vector of valid moves for knight
        void calculateValidMoves(std::string currentPos);
        // constructor
        Knight(Colour colour, ChessBoard* board);
};

#endif

