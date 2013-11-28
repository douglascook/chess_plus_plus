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
    }

    // now check for pieces that can be captured 
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

    // if its first move check two squares ahead
    endPos[0] = currentPos[0];
    //cout << endPos << endl;
    if (!moved){
        colour == WHITE ? endPos[1]++ : endPos[1]--;
        //cout << endPos << endl;
        if (board->onBoard(endPos) && board->checkForPiece(endPos) == NO_PIECE){
            validMoves.push_back(endPos);
        }
    }

    //cout << validMoves.size() << " possible moves in range from position " << currentPos << endl;
}

Pawn::Pawn(Colour _colour, ChessBoard* _board) 
    : Piece(_colour, _board), moved(false) 
{ }
