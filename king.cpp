#include "king.h"
#include "ChessBoard.hpp"

using namespace std;

bool King::calculateRange(std::string currentPos, std::string targetPos)
{
    string endPos = currentPos;

    // can do some sort of loop to shorten this too?
    // E
    endPos[0] = currentPos[0] + 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // W
    endPos[0] = currentPos[0] - 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // N
    endPos[1] = currentPos[1] + 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // S
    endPos[1] = currentPos[1] - 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // NE
    endPos[0] = currentPos[0] + 1;
    endPos[1] = currentPos[1] + 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // SE
    endPos[0] = currentPos[0] + 1;
    endPos[1] = currentPos[1] - 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // SW
    endPos[0] = currentPos[0] - 1;
    endPos[1] = currentPos[1] - 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // NW
    endPos[0] = currentPos[0] - 1;
    endPos[1] = currentPos[1] + 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }
    return checkInRange(targetPos);
}

King::King(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
