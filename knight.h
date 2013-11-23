#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece
{
    public:
        void calculateRange();
        // constructor
        Knight(int colour);
};

#endif

