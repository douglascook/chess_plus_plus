#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    public:
        // used to record if pawn has moved yet
        bool moved;
        // needs to be declared here for some reason? because it is pure virtual in Piece?
        void calculateValidMoves(std::string currentPos);
        // constructor
        Pawn(Colour colour, ChessBoard* board);
};

#endif
