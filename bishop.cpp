#include "bishop.h"
#include "ChessBoard.hpp"

using namespace std;

bool Bishop::validMove(string currentPos, string targetPos)
{
    string endPos = currentPos;

    // can do some sort of loop to shorten this too?

    // if target is to NE
    if (targetPos[0] > currentPos[0] && targetPos[1] > currentPos[1]){
        // if it is not on diagonal then move is invalid
        if (targetPos[0] - currentPos[0] != targetPos[1] - currentPos[1]){
            return false;
        }else {
            for (int i = 1; i < targetPos[0] - currentPos[0]; i++){
                endPos[0] = currentPos[0] + i;
                endPos[1] = currentPos[1] + i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }
    }else if (targetPos[0] < currentPos[0] && targetPos[1] > currentPos[1]){
        // target is to NW
        // if it is not on diagonal then move is invalid
        if (currentPos[0] - targetPos[0] != targetPos[1] - currentPos[1]){
            return false;
        }else {
            for (int i = 1; i < currentPos[0] - targetPos[0]; i++){
                endPos[0] = currentPos[0] - i;
                endPos[1] = currentPos[1] + i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }
    }else if (targetPos[0] < currentPos[0] && targetPos[1] < currentPos[1]){
        // target is to SW
        // if it is not on diagonal then move is invalid
        if (currentPos[0] - targetPos[0] != currentPos[1] - targetPos[1]){
            return false;
        }else {
            for (int i = 1; i < currentPos[0] - targetPos[0]; i++){
                endPos[0] = currentPos[0] - i;
                endPos[1] = currentPos[1] - i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }
    }else if (targetPos[0] > currentPos[0] && targetPos[1] < currentPos[1]){
        // target is to SE
        // if it is not on diagonal then move is invalid
        if (targetPos[0] - currentPos[0] != currentPos[1] - targetPos[1]){
            return false;
        }else {
            for (int i = 1; i < targetPos[0] - currentPos[0]; i++){
                endPos[0] = currentPos[0] + i;
                endPos[1] = currentPos[1] - i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }
    }else {
        // target square is not on a diagonal
        return false;
    }

    // otherwise move is valid
    return true;
}

Bishop::Bishop(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
