#include "rook.h"
#include "ChessBoard.hpp"

using namespace std;

void Rook::calculateValidMoves(std::string currentPos)
{
    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;

    int fileChange, rankChange;
    for (int i = 0; i < 4;  i++){
        // coordinate change depends on which loop
        switch (i){
            case 0:
                fileChange = 1;
                rankChange = 0;
                break;
            case 1:
                fileChange = -1;
                rankChange = 0;
                break;
            case 2:
                fileChange = 0;
                rankChange = 1;
                break;
            case 3:
                fileChange = 0;
                rankChange = -1;
                break;
        }

        endPos[0] = currentPos[0] + fileChange;
        endPos[1] = currentPos[1] + rankChange;
        while (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
            validMoves.push_back(endPos);
            // if we have got to an enemy piece cannot pass it
            if (board->checkForPiece(endPos) == (colour + 1)%2){
                break;
            }
            endPos[0] = endPos[0] + fileChange;
            endPos[1] = endPos[1] + rankChange;
        }
    }
}

Rook::Rook(Colour _colour, ChessBoard* _board) : Piece(_colour, "Rook", _board)
{ }
