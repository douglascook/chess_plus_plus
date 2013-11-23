#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    public:
        void calculateRange();
        // constructor
        Rook(int colour);
};

#endif

