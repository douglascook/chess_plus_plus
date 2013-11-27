#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece
{
    public:
        // needs to be declared here for some reason? because it is pure virtual in Piece?
        bool calculateRange(std::string currentPos, std::string targetPos);
        // constructor
        Knight(Colour colour, ChessBoard* board);
};

#endif

