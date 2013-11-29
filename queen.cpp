#include "queen.h"
#include "ChessBoard.hpp"

using namespace std;

bool Queen::validMove(string currentPos, string targetPos)
{
    string endPos = currentPos;

    // can improve this by not checking north of etc multiple times

    // target square is in same file
    if (targetPos[0] == currentPos[0]){
        // target is north of current
        if (targetPos[1] > currentPos[1]){
            // loop through all squares between current and target positions
            for (int i = 1; i < targetPos[1] - currentPos[1]; i++){
                endPos[1] = currentPos[1] + i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }else {
            // else target is south of current
            for (int i = 1; i < targetPos[1] - currentPos[1]; i++){
                endPos[1] = currentPos[1] - i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }
    }else if (targetPos[1] == currentPos[1]){
        // target is in same rank 
        // target is east of current
        if (targetPos[0] > currentPos[0]){
            // loop through all squares between current and target positions
            for (int i = 1; i < targetPos[0] - currentPos[0]; i++){
                endPos[0] = currentPos[0] + i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }else {
            // else target is west of current
            for (int i = 1; i < targetPos[1] - currentPos[1]; i++){
                endPos[1] = currentPos[1] - i;
                // if there is a piece in the way move isnt valid
                if (board->checkForPiece(endPos) != NO_PIECE){
                    return false;
                }
            }
        }
    }else if (targetPos[0] > currentPos[0] && targetPos[1] > currentPos[1]){
        // target is to NE
        if (targetPos[0] - currentPos[0] != targetPos[1] - currentPos[1]){
            return false;
        }else {
            for (int i = 1; i < targetPos[1] - currentPos[1]; i++){
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
        // target square is current square 
        return false;
    }

    // otherwise move is valid
    return true;
}

Queen::Queen(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
