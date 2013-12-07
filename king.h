#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    public:
        // create vector of valid moves for king
        void calculateValidMoves(std::string currentPos);

        // constructor
        King(Colour colour, ChessBoard* board);
};

#endif
