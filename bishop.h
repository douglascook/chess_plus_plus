#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop: public Piece
{
    public:
        // create vector of valid moves for bishop
        void calculateValidMoves(std::string currentPos);

        // constructor
        Bishop(Colour colour, ChessBoard* board);
};

#endif
