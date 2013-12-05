#include "king.h"
#include "ChessBoard.hpp"

using namespace std;

void King::calculateValidMoves(std::string currentPos)
{
    int fileChange, rankChange;

    // get rid of any moves left over from last turn
    validMoves.clear();
    string endPos = currentPos;

    for (int i = 0; i < 8;  i++){
        // coordinate change depends on which iteration of loop
        switch (i){
            case 0: // NE
                fileChange = 1;
                rankChange = 1;
                break;
            case 1:// SE
                fileChange = 1;
                rankChange = -1;
                break;
            case 2:// SW
                fileChange = -1;
                rankChange = -1;
                break;
            case 3:// NW
                fileChange = -1;
                rankChange = 1;
                break;
            case 4:// E
                fileChange = 1;
                rankChange = 0;
                break;
            case 5:// W 
                fileChange = -1;
                rankChange = 0;
                break;
            case 6:// N 
                fileChange = 0;
                rankChange = 1;
                break;
            case 7:// S
                fileChange = 0;
                rankChange = -1;
                break;
        }
        endPos[0] = currentPos[0] + fileChange;
        endPos[1] = currentPos[1] + rankChange;

        // if there is no friendly piece on the target square can move there
        if (board->onBoard(endPos) && board->checkForPiece(endPos) != colour){
            validMoves.push_back(endPos);
        }
    }
}

King::King(Colour _colour, ChessBoard* _board) : Piece(_colour, "King", _board)
{ }
