#include <iostream>

#include "ChessBoard.hpp"

using namespace std;

void ChessBoard::resetBoard()
{
    // clean up pieces left over from previous game
    for (pieceIterator it = positions.begin(); it != positions.end(); it++){
        delete it->second;
    }
    positions.clear();

    // record positions of kings for quick access
    kings.clear();
    kings.push_back("E1");
    kings.push_back("E8");

    whoseTurn = WHITE;
    string pos = "A1";

    // set up pawns
    for (char file = 'A'; file < 'I'; file++){
        pos[0] = file;

        pos[1] = '2';
        positions[pos] = new Pawn(WHITE, this);

        pos[1] = '7';
        positions[pos] = new Pawn(BLACK, this);
    }

    // setup other white pieces
    positions["A1"] = new Rook(WHITE, this);
    positions["B1"] = new Knight(WHITE, this);
    positions["C1"] = new Bishop(WHITE, this);
    positions["D1"] = new Queen(WHITE, this);
    positions["E1"] = new King(WHITE, this);
    positions["F1"] = new Bishop(WHITE, this);
    positions["G1"] = new Knight(WHITE, this);
    positions["H1"] = new Rook(WHITE, this);

    // setup other black pieces
    positions["A8"] = new Rook(BLACK, this);
    positions["B8"] = new Knight(BLACK, this);
    positions["C8"] = new Bishop(BLACK, this);
    positions["D8"] = new Queen(BLACK, this);
    positions["E8"] = new King(BLACK, this);
    positions["F8"] = new Bishop(BLACK, this);
    positions["G8"] = new Knight(BLACK, this);
    positions["H8"] = new Rook(BLACK, this);

    // first update valid moves for all pieces
    updateValidMoves();

    cout << "A new chess game is started!" << endl;
}

void ChessBoard::submitMove(string currentPos, string targetPos)
{
    // check if move is legal
    if (validateMove(currentPos, targetPos)){
        // update turn to check for mates
        whoseTurn = otherPlayer(whoseTurn);

        // checkmate or stalemate check
        if (mateCheck()){
            if (playerInCheck()){
                cout << printColour(whoseTurn) << " is in check mate" << endl;
            }else {
                cout << "Game is a stalemate" << endl;
            }
        }else if (playerInCheck()){
            cout << printColour(whoseTurn) << " is in check" << endl;
        }
    }
}

bool ChessBoard::validateMove(string currentPos, string targetPos) 
{
    Piece* piece; 
    Piece* takenPiece = NULL;
    map<string, Piece*> originalPositions = positions;

    // check if there is a piece at the location
    if (positions.count(currentPos) == 0){
        cout << "There is no piece at position " << currentPos << "!" << endl;
        return false;
    }else {
        // get pointer to piece
        piece = positions.find(currentPos)->second;
    }
    
    // check piece is the correct colour
    if (piece->getColour() != whoseTurn){
        cout << "It is not " << printColour(otherPlayer(whoseTurn)) << "'s turn to move!" << endl;
        return false;
    }
    
    if (piece->checkValidMove(targetPos)){
        updatePosition(currentPos, targetPos, takenPiece);
        updateValidMoves();

        // now need to check if player moving has put themselves in check
        if (playerInCheck()){
            cout << "cannot make that move, it would put you in check" << endl;
            // undo move
            positions = originalPositions;
            updateValidMoves();
            return false;
        }else if (takenPiece != NULL){
            // successful move, piece has been taken 
            cout << printColour(whoseTurn) << "'s " << piece->getType() 
                 << " moves from " << currentPos << " to " << targetPos 
                 << " taking " << printColour(otherPlayer(whoseTurn)) << "'s " << takenPiece->getType() << endl;
            delete takenPiece;
            return true;
        }else {
            // successful move, no piece taken
            cout << printColour(whoseTurn) << "'s " << piece->getType() 
                 << " moves from " << currentPos << " to " << targetPos << endl;
            return true;
        }
    }else {
        // the move is invalid
        cout << printColour(whoseTurn) << "'s " << piece->getType() 
             << " cannot move to " << targetPos << "!" << endl;
        return false;
    }
}

void ChessBoard::updateValidMoves()
{
    // loop through and update all move vectors
    for (pieceIterator it = positions.begin(); it != positions.end(); it++){
        it->second->calculateValidMoves(it->first);
    }
}

void ChessBoard::updateValidMoves(Colour player)
{
    // loop through and update all move vectors
    for (pieceIterator it = positions.begin(); it != positions.end(); it++){
        // only update moves if correct player
        if (it->second->getColour() == player){
            it->second->calculateValidMoves(it->first);
        }
    }
}

bool ChessBoard::playerInCheck()
{
    Piece* piece;

    // loop through all pieces 
    for (pieceIterator it = positions.begin(); it != positions.end(); it++){
        piece = it->second;
        // if its player who just moved's piece and king is within range
        if (piece->getColour() != whoseTurn && piece->checkValidMove(kings[whoseTurn])){
            return true;
        }
    }
    return false;
}

bool ChessBoard::mateCheck()
{
    Piece* piece;
    Piece* takenPiece = NULL;
    string originalPos, testPos;
    vector<string> moveSet;

    // make copy of current positions in order to iterate through them
    // and to be able to reset the pieces
    map<string, Piece*> originalPositions = positions;
    vector<string> originalKings = kings;
    Colour opponent = otherPlayer(whoseTurn);

    // loop through all pieces for current player
    for (pieceIterator it = originalPositions.begin(); it != originalPositions.end(); it++){
        piece = it->second;
        originalPos = it->first;

        // turn is updated before the mate checks are called so use current player here
        if (piece->getColour() == whoseTurn){
            // since the moves are going to be updated each time a move is tested
            // need to save the current moveset to loop through 
            moveSet = piece->getValidMoves();

            // check all moves for this piece and see if king is still in check
            for (unsigned i = 0; i < moveSet.size(); i++){
                testPos = moveSet[i];
                updatePosition(originalPos, testPos, takenPiece);
                // only need to update opponents pieces to see if king is still in check
                updateValidMoves(opponent);

                // check if player is not in check
                if (!playerInCheck()){
                    // put pieces back and reset valid moves so that everything is set for actual move
                    positions = originalPositions;
                    kings = originalKings;
                    updateValidMoves(opponent);
                    return false;

                }else {
                    // still in check
                    // put pieces back and reset valid moves so that next move can be checked 
                    positions = originalPositions;
                    kings = originalKings;
                    updateValidMoves(opponent);
                }
            }
        }
    }
    // if all moves result in check
    updateValidMoves(opponent);
    return true;
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
    // if there is a piece then return its colour
    if (positions.count(strPos)){
        return positions.find(strPos)->second->getColour() ;
    }else {
        return NO_PIECE;
    }
}


Colour ChessBoard::otherPlayer(Colour player)
{
    Colour otherPlayer = (player == WHITE ? BLACK : WHITE);
    return otherPlayer;
}

void ChessBoard::updatePosition(string startPos, string endPos, Piece*& takenPiece)
{
    Piece* piece = positions.find(startPos)->second;

    // if there is a piece at target position then it must be an enemy and is taken
    if (positions.count(endPos)){
        // don't delete yet in case move puts player in check
        takenPiece = positions.find(endPos)->second;
        // square now occupied by new piece
        positions.find(endPos)->second = piece;
    }else {
        // if there was no piece there then we need to create a map element
        positions[endPos] = piece;
    }

    // if the piece moved is a king update its position
    if (piece->getType() == "King"){
        kings[whoseTurn] = endPos;
    }

    // delete the starting square from map
    positions.erase(startPos);
}

string ChessBoard::printColour(Colour colour)
{
    if (colour == WHITE){
        return "White";
    }else {
        return "Black";
    }
}

ChessBoard::ChessBoard() : whoseTurn(WHITE)
{
    resetBoard();
}
