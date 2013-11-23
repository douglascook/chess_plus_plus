#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    public:
        void calculateRange();
        // constructor
        Pawn(int colour);
};

#endif
