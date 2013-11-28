#include "piece.h"

using namespace std;

bool Piece::checkValidMove(string targetPos)
{
    // loop through and check if destination square is within range
    //cout << validMoves.size() << " possible moves" << endl;
    for (unsigned i = 0; i < validMoves.size(); i++){
        if (validMoves[i] == targetPos){
            return true;
        }
    }
    // otherwise move is not valid
    return false;
}

Piece::Piece(Colour _colour, ChessBoard* _board) 
    : colour(_colour), board(_board)
{ }
