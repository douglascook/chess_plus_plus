#include "pawn.h"
#include "ChessBoard.hpp"

using namespace std;

void Pawn::calculateValidMoves(std::string currentPos)
{
    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;
    // why does resizing not work???????????????
    //endPos.resize(2);
    
    // standard move, need to check which colour is moving
    colour == WHITE ? endPos[1]++ : endPos[1]--;
    // if there is no piece in the way add to possible moves
    if (board->onBoard(endPos) && board->checkForPiece(endPos) == NO_PIECE){
        validMoves.push_back(endPos);

        // can only go two forward if there is nothing in the way!
        // if its first move check two squares ahead
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
    // if it is an enemy piece
    // has to be a nicer way to check that the the piece is of the other colour
    if (board->onBoard(endPos) && board->checkForPiece(endPos) == (colour + 1)%2 ){
        validMoves.push_back(endPos);
    }
    endPos[0] = currentPos[0] + 1;
    // if it is an enemy piece
    if (board->onBoard(endPos) && board->checkForPiece(endPos) == (colour + 1)%2 ){
        validMoves.push_back(endPos);
    }
}

Pawn::Pawn(Colour _colour, ChessBoard* _board) 
    : Piece(_colour, "Pawn", _board), moved(false) 
{ }
