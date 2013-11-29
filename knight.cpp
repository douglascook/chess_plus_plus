#include "knight.h"
#include "ChessBoard.hpp"

using namespace std;

bool Knight::validMove(string currentPos, string targetPos)
{
    // check
    if (targetPos[0] == currentPos[0] - 1){
        // one file left
        if (targetPos[1] == currentPos[1] - 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }else if (targetPos[1] == currentPos[1] + 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }
    }else if (targetPos[0] == currentPos[0] + 1){
        // one file right
        if (targetPos[1] == currentPos[1] - 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }else if (targetPos[1] == currentPos[1] + 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }
    }else if (targetPos[1] == currentPos[1] - 1){
        // one rank down
        if (targetPos[0] == currentPos[0] - 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }else if (targetPos[0] == currentPos[0] + 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }
    }else if (targetPos[1] == currentPos[1] + 1){
        // one rank up
        if (targetPos[0] == currentPos[0] - 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }else if (targetPos[0] == currentPos[0] + 2 && board->checkForPiece(targetPos) != colour){
            return true;
        }
    }

    // if move does not match one of the above
    return false;
    
}

Knight::Knight(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
