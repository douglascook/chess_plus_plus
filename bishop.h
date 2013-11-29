#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop: public Piece
{
    public:
        // needs to be declared here for some reason? because it is pure virtual in Piece?
        bool validMove(std::string currentPos, std::string targetPos);

        // constructor
        Bishop(Colour colour, ChessBoard* board);
};

#endif
