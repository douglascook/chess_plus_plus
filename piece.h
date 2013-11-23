#ifndef PIECE_H
#define PIECE_H

// numbers to use for black, white, neither in check
#define NEITHER 0
#define WHITE 1
#define BLACK 2

#include <vector>

class Piece
{
    public:
        // colour of the piece, can use the defined colours
        // maybe should use enumeration instead?
        int colour;

        // current position of the piece
        std::vector<int> position;

        // range of the piece based on current positions
        std::vector<std::vector<int> > range;

    public:
        // create the range vector
        //virtual void calculateRange();
        virtual void calculateRange() = 0;

        // check if position is within range
        // this is going to come in very useful for check and checkmate
        bool withinRange(std::vector<int> target);
};

#endif
