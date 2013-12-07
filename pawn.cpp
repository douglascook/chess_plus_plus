#include "pawn.h"
#include "ChessBoard.hpp"

using namespace std;

void Pawn::calculateValidMoves(std::string currentPos)
{
    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;
    
    // standard move 
    // first need to check which colour is moving
    colour == WHITE ? endPos[1]++ : endPos[1]--;
    // if there is no piece in the way add to possible moves
    if (board->onBoard(endPos) && board->checkForPiece(endPos) == NO_PIECE){
        validMoves.push_back(endPos);

        // if pawn has not moved yet check two squares ahead as well
        if (!moved){
            colour == WHITE ? endPos[1]++ : endPos[1]--;
            if (board->onBoard(endPos) && board->checkForPiece(endPos) == NO_PIECE){
                validMoves.push_back(endPos);
            }
        }
    }

    // now check for pieces that can be captured 
    colour == WHITE ? endPos[1] = currentPos[1] + 1 : endPos[1] = currentPos[1] - 1;

    endPos[0] = currentPos[0] - 1;
    // if it is an enemy piece can take it
    if (board->onBoard(endPos) && board->checkForPiece(endPos) == ChessBoard::otherPlayer(colour)){
        validMoves.push_back(endPos);
    }

    endPos[0] = currentPos[0] + 1;
    if (board->onBoard(endPos) && board->checkForPiece(endPos) == ChessBoard::otherPlayer(colour)){
        validMoves.push_back(endPos);
    }
}

Pawn::Pawn(Colour _colour, ChessBoard* _board) 
    : Piece(_colour, "Pawn", _board), moved(false) 
{ }
