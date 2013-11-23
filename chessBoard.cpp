#include <iostream>

#include "chessBoard.hpp"

using namespace std;

void ChessBoard::resetBoard()
{
    vector<int> pos(2);

    // first want to set the null pointers where there are no pieces
    for (int i = 3; i < 7; i++){
        for (int j = 1; j < 9; j++){
            // want to assign them more succintly but g++ version is too old???
            pos[0] = i;
            pos[1] = j;
            positions[pos] = NULL;
        }
    }

    // pawns
    for (int j = 1; j < 9; j++){
        pos[0] = 2;
        pos[1] = j;
        positions[pos] = new Pawn(BLACK);

        pos[0] = 7;
        pos[1] = j;
        positions[pos] = new Pawn(WHITE);
    }

    // other black pieces
    pos[0] = 8;
    pos[1] = 1;
    positions[pos] = new Rook(BLACK);
    pos[1] = 2;
    positions[pos] = new Knight(BLACK);
    pos[1] = 3;
    positions[pos] = new Bishop(BLACK);
    pos[1] = 4;
    positions[pos] = new Queen(BLACK);
    pos[1] = 5;
    positions[pos] = new King(BLACK);
    pos[1] = 6;
    positions[pos] = new Bishop(BLACK);
    pos[1] = 7;
    positions[pos] = new Knight(BLACK);
    pos[1] = 8;
    positions[pos] = new Rook(BLACK);

    // other white pieces
    pos[0] = 1;
    pos[1] = 1;
    positions[pos] = new Rook(WHITE);
    pos[1] = 2;
    positions[pos] = new Knight(WHITE);
    pos[1] = 3;
    positions[pos] = new Bishop(WHITE);
    pos[1] = 4;
    positions[pos] = new Queen(WHITE);
    pos[1] = 5;
    positions[pos] = new King(WHITE);
    pos[1] = 6;
    positions[pos] = new Bishop(WHITE);
    pos[1] = 7;
    positions[pos] = new Knight(WHITE);
    pos[1] = 8;
    positions[pos] = new Rook(WHITE);

    cout << "Board created" << endl;

    /*
    pos[1] = 8;
    pos[0] = 8;
    cout << positions.find(pos)->second->colour << endl;
    */
}

void ChessBoard::submitMove(string startPos, string endPos)
{
    vector<int> startVector(2);
    vector<int> endVector(2);

    //cout << startPos.at(1) << endl;

    startVector[0] = startPos.at(0) - 64;
    startVector[1] = startPos.at(1) - 48;
    cout << "starting coords " << startVector[0] << "-" << startVector[1] << endl;
    endVector[0] = endPos.at(0) - 64;
    endVector[1] = endPos.at(1) - 48;
    cout << "end coords " << endVector[0] << "-" <<  endVector[1] << endl;

    // check that start and end positions are on the board
    if (startVector[0] < 1 || startVector[0] > 8){
        cout << "Starting square not on board!" << endl;
    }else if (endVector[0] < 1 || endVector[0] > 8){
        cout << "Destination square not on board!" << endl;
    }
}

int ChessBoard::checkForPiece(vector<int> position)
{
    return 0;
}

bool ChessBoard::validateMove(vector<int> startPos, vector<int> endPos)
{
    return true;
}

void ChessBoard::updatePosition(vector<int> startPos, vector<int> endPos)
{

}

ChessBoard::ChessBoard()
{
    resetBoard();
}
