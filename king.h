#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    public:
        // needs to be declared here for some reason? because it is pure virtual in Piece?
        void calculateValidMoves(std::string currentPos);
        // constructor
        King(Colour colour, ChessBoard* board);
};

#endif
