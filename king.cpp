#include "king.h"
#include "ChessBoard.hpp"

using namespace std;

bool King::validMove(string currentPos, string targetPos)
{
    string endPos = currentPos;

    // can do some sort of loop to shorten this too?
    // E
    endPos[0] = currentPos[0] + 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }
    // W
    endPos[0] = currentPos[0] - 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }
    // N
    endPos[1] = currentPos[1] + 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }
    // S
    endPos[1] = currentPos[1] - 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }
    // NE
    endPos[0] = currentPos[0] + 1;
    endPos[1] = currentPos[1] + 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }
    // SE
    endPos[0] = currentPos[0] + 1;
    endPos[1] = currentPos[1] - 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }
    // SW
    endPos[0] = currentPos[0] - 1;
    endPos[1] = currentPos[1] - 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }
    // NW
    endPos[0] = currentPos[0] - 1;
    endPos[1] = currentPos[1] + 1;
    if (endPos == targetPos && board->checkForPiece(endPos) != colour){
        return true;
    }

    // otherwise move is invalid
    return false;
}

King::King(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
