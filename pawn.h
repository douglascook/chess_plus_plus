#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    private:
        // used to record if pawn has moved yet
        bool moved;

    public:
        // create vector of valid moves for pawn 
        void calculateValidMoves(std::string currentPos);

        // constructor
        Pawn(Colour colour, ChessBoard* board);
};

#endif
