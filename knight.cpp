#include "knight.h"
#include "ChessBoard.hpp"

using namespace std;

bool Knight::calculateRange(std::string currentPos, std::string targetPos)
{
    // think we need to do this so that endPos has correct size?
    // could use resize instead?
    string endPos = currentPos;

    // create some sort of loop to do this....
    endPos[0] = currentPos[0] - 1;
    //
    endPos[1] = currentPos[1] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }
    endPos[1] = currentPos[1] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    endPos[0] = currentPos[0] + 1;
    //
    endPos[1] = currentPos[1] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }
    endPos[1] = currentPos[1] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    endPos[1] = currentPos[1] - 1;
    //
    endPos[0] = currentPos[0] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }
    endPos[0] = currentPos[0] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    endPos[1] = currentPos[1] + 1;
    //
    endPos[0] = currentPos[0] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }
    endPos[0] = currentPos[0] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    return checkInRange(targetPos);
}

Knight::Knight(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
