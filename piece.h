#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>

// numbers to use for black, white, neither in check
enum Colour {WHITE, BLACK, NO_PIECE};

class ChessBoard;

class Piece
{
    protected:
        // colour of the piece
        Colour colour;
        // type of piece
        std::string type;
        // reference to the board so can check where other pieces are
        ChessBoard* board;
        // current position of the piece
        std::string currentPos;
        // range of the piece based on current positions
        std::vector<std::string> validMoves;

    public:
        // create a vector of valid moves for the piece 
        virtual void calculateValidMoves(std::string currentPos) = 0;
        // check if the target square is range of the piece
        bool checkValidMove(std::string targetPos);
        // accessor function for colour of piece
        Colour getColour();
        // return colour of opponent
        static Colour otherPlayer(Colour player);
        // accessor function for type of piece
        std::string getType();
        // accessor function for valid moves
        std::vector<std::string> getValidMoves();


        // non-default constructor, to be used in derived constructors
        Piece(Colour colour, std::string type, ChessBoard* board);
        // need a virtual destructor so that derived classes can be deleted properly
        virtual ~Piece() = 0;
};

#endif
