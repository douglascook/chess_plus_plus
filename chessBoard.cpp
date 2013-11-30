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

    // first update valid moves for all pieces
    updateValidMoves();
}

void ChessBoard::printBoard()
{
    typedef map<string, Piece*>::iterator it;
    
    char board[8][8];
    char symbol;
    int x, y;


    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            board[i][j] = ' ';
        }
    }


    for (it it1 = positions.begin(); it1 != positions.end(); it1++){
        if (it1->second->colour == WHITE){
            if (it1->second->type == "King"){
                //symbol = '\u2654';
                symbol = 'X';
            }else if (it1->second->type == "Queen"){
                //symbol = '\u2655';
                symbol = 'Q';
            }else if (it1->second->type == "Rook"){
                //symbol = '\u2656';
                symbol = 'R';
            }else if (it1->second->type == "Bishop"){
                //symbol = '\u2657';
                symbol = 'B';
            }else if (it1->second->type == "Knight"){
                //symbol = '\u2658';
                symbol = 'K';
            }else if (it1->second->type == "Pawn"){
                //symbol = '\u2659';
                symbol = 'P';
            } 
        }else {
            if (it1->second->type == "King"){
                //symbol = '\u265A';
                symbol = 'x';
            }else if (it1->second->type == "Queen"){
                //symbol = '\u265B';
                symbol = 'q';
            }else if (it1->second->type == "Rook"){
                //symbol = '\u265C';
                symbol = 'r';
            }else if (it1->second->type == "Bishop"){
                //symbol = '\u265D';
                symbol = 'b';
            }else if (it1->second->type == "Knight"){
                //symbol = '\u265E';
                symbol = 'k';
            }else if (it1->second->type == "Pawn"){
                //symbol = '\u265F';
                symbol = 'p';
            } 
        }

        x = it1->first[0];
        y = it1->first[1];

        //cout << "x = " << x-65 << ", y = " << y-49 << " and symbol should be " << symbol << endl;
        //board[x-65][y-49] = symbol;
        board[y-49][x-65] = symbol;
    }
                        
    cout << endl << endl;
    for (int i = 7; i > -1; i--){
        for (int j = 0; j < 8; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}


void ChessBoard::submitMove(string currentPos, string targetPos)
{
    //cout << "testing move from " << currentPos << " to " << targetPos << endl;
    // check if move is legal
    if (validateMove(currentPos, targetPos)){
        //printBoard();
        updateValidMoves();

        //cout << "kings at " << kings[0] << " and " << kings[1] << endl;
        //cout << kings[(whoseTurn + 1) % 2] << endl;

        // update turn to check for mates
        whoseTurn = (whoseTurn == WHITE ? BLACK : WHITE);

        // checkmate (of non-current player) or stalemate check
        if (mateCheck()){
            if (playerInCheck(whoseTurn)){
                cout << "player " << whoseTurn << " is in check mate" << endl;
            }else {
                cout << "Stalemate!!!" << endl;
            }
        }else if (playerInCheck(whoseTurn)){
            cout << "player " << whoseTurn << " is in check" << endl;
        }
    }
}

void ChessBoard::updateValidMoves()
{
    // loop through and update all move vectors
    for (map<string, Piece*>::iterator it = positions.begin(); it != positions.end(); it++){
        it->second->calculateValidMoves(it->first);
    }
}

bool ChessBoard::playerInCheck(Colour defendingColour)
{
    Piece* piece;

    // check if next player is in check
    for (map<string, Piece*>::iterator it = positions.begin(); it != positions.end(); it++){
        piece = it->second;
        // if it player who just moved's piece and king is within range
        if (piece->colour != defendingColour && piece->checkValidMove(kings[defendingColour])){
            return true;
        }
    }
    return false;
}

bool ChessBoard::mateCheck()
{
    //cout << "checking for mate" << endl;

    Piece* piece;
    string originalPos, testPos;
    vector<string> moveSet;

    // seems like I need to make this in order to iterate through it?
    map<string, Piece*> originalPositions = positions;
    vector<string> originalKings = kings;

    // loop through all pieces for current player
    // check all moves for each piece and see if king is still in check
    for (map<string, Piece*>::iterator it = originalPositions.begin(); it != originalPositions.end(); it++){
        piece = it->second;
        originalPos = it->first;

        // turn is updated before the mate checks are called so use current player here
        if (piece->colour == whoseTurn){
            moveSet = piece->validMoves;
            // loop through all moves for this piece and see if it results in check
            for (unsigned i = 0; i < moveSet.size(); i++){
                testPos = moveSet[i];

                updatePosition(originalPos, testPos);
                updateValidMoves();

                // check if player is not in check
                if (!playerInCheck(whoseTurn)){

                    // put pieces back and reset valid moves so that everything is set for actual move
                    positions = originalPositions;
                    kings = originalKings;
                    updateValidMoves();

                    //cout << "not checkmate because piece at " << originalPos << " can move to " << testPos << endl;
                    return false;
                }
                // put pieces back
                positions = originalPositions;
                kings = originalKings;
            }
        }
    }
    // if all moves result in check
    updateValidMoves();
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
    // if there is a piece then return it's colour
    if (positions.count(strPos)){
        return positions.find(strPos)->second->colour;
    }else {
        return NO_PIECE;
    }
}

bool ChessBoard::validateMove(string currentPos, string targetPos) 
{
    Piece* piece; 
    map<string, Piece*> originalPositions = positions;

    // check if there is a piece at the location
    if (positions.count(currentPos) == 0){
        cout << "There is no piece at position " << currentPos << endl;
        return false;
    }else {
        // get pointer to piece
        piece = positions.find(currentPos)->second;
    }

    /*
    cout << "possible moves are ";
    for (unsigned i = 0; i < piece->validMoves.size(); i++){
        cout << piece->validMoves[i] << ", ";
    }
    cout << endl;
    */

    // check piece is the correct colour
    if (piece->colour != whoseTurn){
        cout << "It is not " << whoseTurn << "'s turn to move!" << endl;
        return false;
    }
    
    //cout << "asked to calculate range" << endl;
    if (piece->checkValidMove(targetPos)){
        updatePosition(currentPos, targetPos);

        // now need to check if player moving has put themselves in check
        if (playerInCheck(whoseTurn)){
            cout << "cannot make that move, it would put you in check" << endl;
            // undo move
            positions = originalPositions;
            return false;
        }else {
            cout << whoseTurn << "'s " << piece->type << " moves from " << currentPos << " to " << targetPos << endl;
            return true;
        }
    }else {
        cout << "cannot move " << piece->type << " to " << targetPos << endl;
        return false;
    }
}

void ChessBoard::updatePosition(std::string startPos, std::string endPos)
{
    Piece* piece = positions.find(startPos)->second;

    // if there is a piece at target position (ie it is captured)
    if (positions.count(endPos)){
        // square now occupied by new piece
        positions.find(endPos)->second = piece;
    }else {
        // if there was no piece there then we need to create a map element
        positions[endPos] = piece;
    }

    // if the piece moved is a king update it's position
    if (piece->type == "King"){
        kings[whoseTurn] = endPos;
    }

    // delete the starting square from map
    positions.erase(startPos);
}

ChessBoard::ChessBoard() : whoseTurn(WHITE), inCheck(NO_PIECE)
{
    resetBoard();
}
