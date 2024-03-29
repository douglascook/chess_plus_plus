#include "piece.h"

using namespace std;

bool Piece::checkValidMove(string targetPos)
{
    // loop through and check if destination square is within range
    for (unsigned i = 0; i < validMoves.size(); i++){
        if (validMoves[i] == targetPos){
            return true;
        }
    }
    // otherwise move is not valid
    return false;
}

Colour Piece::getColour()
{
    return colour;
}

string Piece::getType()
{
    return type;
}

vector<string> Piece::getValidMoves()
{
    return validMoves;
}

Piece::Piece(Colour _colour, string _type, ChessBoard* _board) 
    : colour(_colour), type(_type), board(_board)
{ }

Piece::~Piece()
{ }
