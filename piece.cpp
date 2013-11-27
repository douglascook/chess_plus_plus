#include "piece.h"

using namespace std;

bool Piece::checkInRange(string targetPos)
{
    // loop through and check if destination square is within range
    for (unsigned i = 0; i < possibleMoves.size(); i++){
        if (possibleMoves[i] == targetPos){
            return true;
        }
    }
    // otherwise move is not valid
    return false;
}

Piece::Piece(Colour _colour, ChessBoard* _board) 
    : colour(_colour), board(_board)
{ }
