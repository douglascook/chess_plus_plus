#include "queen.h"
#include "ChessBoard.hpp"

using namespace std;

void Queen::calculateValidMoves(std::string currentPos)
{
    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;

    // can do some sort of loop to shorten this too?
    // E
    endPos[0] = currentPos[0] + 1;
    endPos[1] = currentPos[1];
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]++;
    }

    // W
    endPos[0] = currentPos[0] - 1;
    endPos[1] = currentPos[1];
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[0]--;
    }

    // N
    endPos[0] = currentPos[0];
    endPos[1] = currentPos[1] + 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[1]++;
    }

    // S
    endPos[0] = currentPos[0];
    endPos[1] = currentPos[1] - 1;
    while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
        validMoves.push_back(endPos);
        // if we have got to an enemy piece cannot pass it
        if (board->checkForPiece(endPos) == (colour + 1)%2){
            break;
        }
        endPos[1]++;
    }

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
    
    /*
    for (unsigned i = 0; i < validMoves.size(); i++){
        cout << validMoves[i] << ", ";
    }
    cout << endl;
    */
}

Queen::Queen(Colour _colour, ChessBoard* _board) : Piece(_colour, "Queen", _board)
{ }
