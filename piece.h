#ifndef PIECE_H
#define PIECE_H

// numbers to use for black, white, neither in check
enum Colour {WHITE, BLACK, NO_PIECE};

#include <vector>
#include <iostream>

// this needs to be outside the Piece class
// dont need to include the header file as we are only using a pointer to Chessboard
// not any of its methods or properties
class ChessBoard;

class Piece
{
    // this part should all actually be private or protected
    public:
        // colour of the piece, can use the defined colours
        // maybe should use enumeration instead?
        Colour colour;

        // type of piece
        std::string type;

        // reference to the board so can check where other pieces are
        ChessBoard* board;

        // current position of the piece
        std::string currentPos;

        // range of the piece based on current positions
        std::vector<std::string> validMoves;

        // check if the target square is range of the piece
        bool checkValidMove(std::string targetPos);

    public:
        // create the range vector
        // this is pure virtual -> the class is abstract
        virtual void calculateValidMoves(std::string currentPos) = 0;

        // non-default constructor, to be used in derived constructors
        Piece(Colour colour, std::string type, ChessBoard* board);
};

#endif
