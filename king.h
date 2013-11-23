#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    public:
        void calculateRange();
        // constructor
        King(int colour);
};

#endif
