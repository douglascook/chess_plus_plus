#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop: public Piece
{
    public:
        void calculateRange();
        // constructor
        Bishop(int colour);
};

#endif
