#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece
{
    public:
        // needs to be declared here for some reason? because it is pure virtual in Piece?
        void calculateValidMoves(std::string currentPos);
        // constructor
        Queen(Colour colour, ChessBoard* board);
};

#endif
