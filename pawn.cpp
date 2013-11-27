#include "pawn.h"
#include "ChessBoard.hpp"

using namespace std;

bool Pawn::calculateRange(std::string currentPos, std::string targetPos)
{
    std::string endPos = currentPos;
    
    // standard move, need to check which colour is moving
    colour == WHITE ? endPos[1]++ : endPos[1]--;
    // if there is no piece in the way add to possible moves
    if (board->onBoard(endPos) && !board->checkForPiece(endPos)){
        possibleMoves.push_back(endPos);
    }

    // now check for pieces that can be captured 
    endPos[0] = currentPos[0] - 1;
    // if it is an enemy piece
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != NO_PIECE && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }
    endPos[0] = currentPos[0] + 1;
    // if it is an enemy piece
    if (board->onBoard(endPos) && board->checkForPiece(endPos) != NO_PIECE && board->checkForPiece(endPos) != colour){
        possibleMoves.push_back(endPos);
    }

    // if its first move check two squares ahead
    endPos[0] = currentPos[0];
    //cout << endPos << endl;
    if (!moved){
        colour == WHITE ? endPos[1]++ : endPos[1]--;
        //cout << endPos << endl;
        if (board->onBoard(endPos) && board->checkForPiece(endPos) == NO_PIECE){
            possibleMoves.push_back(endPos);
        }
    }
    //cout << possibleMoves.size() << " possible moves" << endl;

    if (checkInRange(targetPos)){
        moved = true;
        return true;
    }
    return false;
}

Pawn::Pawn(Colour _colour, ChessBoard* _board) 
    : Piece(_colour, _board), moved(false) 
{ }
