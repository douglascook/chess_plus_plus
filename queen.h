#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece
{
    public:
        void calculateRange();
        // constructor
        Queen(int colour);
};

#endif
