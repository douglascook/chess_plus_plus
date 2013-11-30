#include "bishop.h"
#include "ChessBoard.hpp"

using namespace std;

void Bishop::calculateValidMoves(std::string currentPos)
{
    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;

    // can do some sort of loop to shorten this too?

    // NE
    endPos[0] = currentPos[0] + 1;
    endPos[1] = currentPos[1] + 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]++;
        endPos[1]++;
    }

    // SE
    endPos[0] = currentPos[0] + 1;
    endPos[1] = currentPos[1] - 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]++;
        endPos[1]--;
    }

    // SW
    endPos[0] = currentPos[0] - 1;
    endPos[1] = currentPos[1] - 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]--;
        endPos[1]--;
    }

    // NW
    endPos[0] = currentPos[0] - 1;
    endPos[1] = currentPos[1] + 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]--;
        endPos[1]++;
    }
}

Bishop::Bishop(Colour _colour, ChessBoard* _board) : Piece(_colour, "Bishop", _board)
{ }
