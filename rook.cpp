#include "rook.h"
#include "ChessBoard.hpp"

using namespace std;

void Rook::calculateValidMoves(std::string currentPos)
{
    int fileChange, rankChange;

    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;

    for (int i = 0; i < 4;  i++){
        // coordinate change depends on which loop
        switch (i){
            case 0:// E
                fileChange = 1;
                rankChange = 0;
                break;
            case 1:// W
                fileChange = -1;
                rankChange = 0;
                break;
            case 2:// N
                fileChange = 0;
                rankChange = 1;
                break;
            case 3:// S
                fileChange = 0;
                rankChange = -1;
                break;
        }
        endPos[0] = currentPos[0] + fileChange;
        endPos[1] = currentPos[1] + rankChange;
        
        // loop through moves in this direction, cant go through enemy piece or off board
        while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
            validMoves.push_back(endPos);
            // if we have got to an enemy piece cannot pass it
            if (board->checkForPiece(endPos) == otherPlayer(colour)){
                break;
            }
            endPos[0] = endPos[0] + fileChange;
            endPos[1] = endPos[1] + rankChange;
        }
    }
}

Rook::Rook(Colour _colour, ChessBoard* _board) : Piece(_colour, "Rook", _board)
{ }
