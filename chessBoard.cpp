#include <iostream>

#include "ChessBoard.hpp"

using namespace std;

void ChessBoard::resetBoard()
{
    // get rid of anything left over from last game
    // going to have to destruct leftovers as well otherwise left with dangling pointers?
    positions.clear();

    string pos = "A1";

    // pawns
    for (char file = 'A'; file < 'I'; file++){
        pos[0] = file;

        pos[1] = '2';
        //cout << posString << endl;
        positions[pos] = new Pawn(WHITE, this);

        pos[1] = '7';
        //cout << posString << endl;
        positions[pos] = new Pawn(BLACK, this);
    }

    // other white pieces
    positions["A1"] = new Rook(WHITE, this);
    positions["B1"] = new Knight(WHITE, this);
    positions["C1"] = new Bishop(WHITE, this);
    positions["D1"] = new Queen(WHITE, this);
    positions["E1"] = new King(WHITE, this);
    positions["F1"] = new Bishop(WHITE, this);
    positions["G1"] = new Knight(WHITE, this);
    positions["H1"] = new Rook(WHITE, this);

    // other black pieces
    positions["A8"] = new Rook(BLACK, this);
    positions["B8"] = new Knight(BLACK, this);
    positions["C8"] = new Bishop(BLACK, this);
    positions["D8"] = new Queen(BLACK, this);
    positions["E8"] = new King(BLACK, this);
    positions["F8"] = new Bishop(BLACK, this);
    positions["G8"] = new Knight(BLACK, this);
    positions["H8"] = new Rook(BLACK, this);

    //printBoard();
}


// going to have to test this to see wtf is going on.......
void ChessBoard::printBoard()
{
    typedef map<string, Piece*>::iterator it;

    for (it it1 = positions.begin(); it1 != positions.end(); it1++){
        cout << "piece found at " << it1->first << endl;
    }
    
    cout << "trying to find D7 " << positions.count("D7") << endl;
}


void ChessBoard::submitMove(string currentPos, string targetPos)
{
    // check if move is legal
    if (validateMove(currentPos, targetPos)){
        // update turn
        whoseTurn = (whoseTurn == WHITE ? BLACK : WHITE);
    }
}

bool ChessBoard::onBoard(string position)
{
    if (position[0] < 'A' || position[0] > 'H' || position[1] < '1' || position[1] > '8'){
        return false;
    }else {
        return true;
    }
}

Colour ChessBoard::checkForPiece(string strPos)
{
    // if there is a piece then return it's colour
    if (positions.count(strPos)){
        return positions.find(strPos)->second->colour;
    }else {
        return NO_PIECE;
    }
}

bool ChessBoard::validateMove(string currentPos, string targetPos) 
{
    Piece* piecePtr;

    // check if there is a piece at the location
    if (positions.count(currentPos) == 0){
        cout << "There is no piece at position " << currentPos << endl;
        return false;
    }else {
        // get pointer to piece
        piecePtr = positions.find(currentPos)->second;
    }

    // check piece is the correct colour
    if (piecePtr->colour != whoseTurn){
        cout << "It is not " << whoseTurn << "'s turn to move!" << endl;
        return false;
    }
    
    // once here we know that it is legal to move the piece
    // get piece to calculate its range
    //cout << "asked to calculate range" << endl;
    if (piecePtr->calculateRange(currentPos, targetPos)){
        updatePosition(currentPos, targetPos);
        cout << "move from " << currentPos << " to " << targetPos << endl;
        return true;
    }else {
        cout << "cannot move to " << targetPos << endl;
        return false;
    }

}

void ChessBoard::updatePosition(std::string startPos, std::string endPos)
{
    Piece* piecePtr = positions.find(startPos)->second;

    // if there is a piece at target position (ie it is captured)
    if (positions.count(endPos)){
        // delete piece pointer
        delete positions.find(endPos)->second;
        // square now occupied by new piece
        positions.find(endPos)->second = piecePtr;
    }

    // if there was no piece there then we need to create a map element
    positions[endPos] = piecePtr;

    // now delete the starting square from map
    positions.erase(startPos);
}

ChessBoard::ChessBoard() : whoseTurn(WHITE), inCheck(NO_PIECE)
{
    resetBoard();
}
