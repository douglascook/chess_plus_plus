#include "knight.h"
#include "ChessBoard.hpp"

using namespace std;

void Knight::calculateValidMoves(std::string currentPos)
{
    int fileChange, rankChange;

    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;

    for (int i = 0; i < 8;  i++){
        // coordinate change depends on which loop
        switch (i){
            case 0:
                fileChange = 1;
                rankChange = 2;
                break;
            case 1:
                fileChange = 2;
                rankChange = 1;
                break;
            case 2:
                fileChange = 2;
                rankChange = -1;
                break;
            case 3:
                fileChange = 1;
                rankChange = -2;
                break;
            case 4:
                fileChange = -1;
                rankChange = -2;
                break;
            case 5:
                fileChange = -2;
                rankChange = -1;
                break;
            case 6:
                fileChange = -2;
                rankChange = 1;
                break;
            case 7:
                fileChange = -1;
                rankChange = 2;
                break;
        }
        endPos[0] = currentPos[0] + fileChange;
        endPos[1] = currentPos[1] + rankChange;

        // cannot move off board or onto a friendly piece
        if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
            validMoves.push_back(endPos);
        }
    }
}

Knight::Knight(Colour _colour, ChessBoard* _board) : Piece(_colour, "Knight", _board)
{ }
