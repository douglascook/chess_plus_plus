#include "pawn.h"
#include "ChessBoard.hpp"

using namespace std;

bool Pawn::validMove(string currentPos, string targetPos)
{
    string endPos = currentPos;
    // why does resizing not work???????????????
    //endPos.resize(2);
    
    // standard move, need to check which colour is moving
    colour == WHITE ? endPos[1]++ : endPos[1]--;
    // if there is no piece there already move is valid 
    if (targetPos == endPos && board->checkForPiece(endPos) == NO_PIECE){
        return true;
    }

    // now check for pieces that can be captured 
    endPos[0] = currentPos[0] - 1;
    // if it is an enemy piece
    if (endPos == targetPos && board->checkForPiece(endPos) == (colour + 1)%2 ){
        return true;
    }

    endPos[0] = currentPos[0] + 1;
    // if it is an enemy piece
    if (endPos == targetPos && board->checkForPiece(endPos) == (colour + 1)%2 ){
        return true;
    }

    endPos[0] = currentPos[0];
    // if its first move check two squares ahead
    if (!moved){
        colour == WHITE ? endPos[1]++ : endPos[1]--;
        //cout << endPos << endl;
        if (endPos == targetPos && board->checkForPiece(endPos) == NO_PIECE){
            return true;
        }
    }

    // if it doesnt match one of cases above move is not valid
    return false;

    //cout << validMoves.size() << " possible moves in range from position " << currentPos << endl;
}

Pawn::Pawn(Colour _colour, ChessBoard* _board) 
    : Piece(_colour, _board), moved(false) 
{ }
