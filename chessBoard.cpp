#include <iostream>

#include "ChessBoard.hpp"

using namespace std;

void ChessBoard::resetBoard()
{
    // get rid of anything left over from last game
    // going to have to destruct leftovers as well otherwise left with dangling pointers?
    whoseTurn = WHITE;
    inCheck = NO_PIECE;
    positions.clear();

    // record positions of kings for quick access
    kings.clear();
    kings.push_back("E1");
    kings.push_back("E8");

    string pos = "A1";

    // pawns
    for (char file = 'A'; file < 'I'; file++){
        pos[0] = file;

        pos[1] = '2';
        positions[pos] = new Pawn(WHITE, this);

        pos[1] = '7';
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
        if (playerInCheck(kings[whoseTurn])){
            inCheck = whoseTurn;
            cout << "player " << inCheck << " is in check" << endl;
        }
    }
}

bool ChessBoard::playerInCheck(string king)
{
    Piece* piecePtr;

    // check if next player is in check
    for (map<string, Piece*>::iterator it = positions.begin(); it != positions.end(); it++){
        piecePtr = it->second;
        // if it player who just moved's piece
        if (piecePtr->colour != whoseTurn){
            // check if king is within range of current piece
            if (piecePtr->validMove(it->first, king)){
                //cout << "king at " << king << "in check from piece at " << it->first << endl;
                return true;
            }
        }
    }
    return false;
}

    

bool ChessBoard::onBoard(string position)
{
    // check piece is within bounds of board
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
    
    //cout << "asked to calculate range" << endl;
    if (piecePtr->validMove(currentPos, targetPos)){
        updatePosition(currentPos, targetPos);

        // now need to check if player moving has put themselves in check
        if (playerInCheck(kings[whoseTurn])){
            cout << "cannot make that move, it would put you in check" << endl;
            // undo move
            // need to add something here to replace piece if taken
            updatePosition(targetPos, currentPos);
            return false;
        }else {
            cout << "move from " << currentPos << " to " << targetPos << endl;
            return true;
        }
    }else {
        cout << "cannot move to " << targetPos << endl;
        return false;
    }

}

void ChessBoard::updatePosition(std::string startPos, std::string endPos)
{
    Piece* piecePtr = positions.find(startPos)->second;

    // need to simplify this once piece types are in place
    // if the piece moved is a king update it's position
    for (unsigned i =0; i < 2; i++){
        if (kings[i] == startPos){
            kings[i] = endPos;
            break;
        }
    }

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
