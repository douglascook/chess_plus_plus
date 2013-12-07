#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece
{
    public:
        // create vector of valid moves for bishop
        void calculateValidMoves(std::string currentPos);

        // constructor
        Queen(Colour colour, ChessBoard* board);
};

#endif
