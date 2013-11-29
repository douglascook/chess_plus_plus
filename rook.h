#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    public:
        // needs to be declared here for some reason? because it is pure virtual in Piece?
        bool validMove(std::string currentPos, std::string targetPos);
        // constructor
        Rook(Colour colour, ChessBoard* board);
};

#endif
