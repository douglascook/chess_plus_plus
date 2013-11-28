#include "knight.h"
#include "ChessBoard.hpp"

using namespace std;

void Knight::calculateValidMoves(std::string currentPos)
{
    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;

    // create some sort of loop to do this....
    endPos[0] = currentPos[0] - 1;
    //
    endPos[1] = currentPos[1] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }
    endPos[1] = currentPos[1] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }

    endPos[0] = currentPos[0] + 1;
    //
    endPos[1] = currentPos[1] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }
    endPos[1] = currentPos[1] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }

    endPos[1] = currentPos[1] - 1;
    //
    endPos[0] = currentPos[0] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }
    endPos[0] = currentPos[0] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }

    endPos[1] = currentPos[1] + 1;
    //
    endPos[0] = currentPos[0] - 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }
    endPos[0] = currentPos[0] + 2;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
    }
}

Knight::Knight(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
