#include "rook.h"
#include "ChessBoard.hpp"

using namespace std;

bool Rook::calculateRange(std::string currentPos, std::string targetPos)
{
    string endPos = currentPos;

    // can do some sort of loop to shorten this too?
    // E
    endPos[0] = currentPos[0] + 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]++;
    }

    // W
    endPos[0] = currentPos[0] - 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]--;
    }

    // N
    endPos[1] = currentPos[1] + 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[1]++;
    }

    // S
    endPos[1] = currentPos[1] - 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[1]++;
    }

    return checkInRange(targetPos);
}

Rook::Rook(Colour _colour, ChessBoard* _board) : Piece(_colour, _board)
{ }
