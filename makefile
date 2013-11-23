chess: ChessMain.cpp chessBoard.o piece.o pawn.o rook.o knight.o bishop.o queen.o king.o 
	g++ -Wall -g ChessMain.cpp chessBoard.o pawn.o rook.o knight.o bishop.o king.o queen.o -o chess
chessBoard.o: chessBoard.cpp piece.h pawn.h rook.h knight.h bishop.h queen.h king.h
	g++ -Wall -g -c chessBoard.cpp
piece.o: piece.cpp
	g++ -Wall -g -c piece.cpp
pawn.o: pawn.cpp piece.h
	g++ -Wall -g -c pawn.cpp
rook.o: rook.cpp piece.h
	g++ -Wall -g -c rook.cpp
knight.o: knight.cpp piece.h
	g++ -Wall -g -c knight.cpp
bishop.o: bishop.cpp piece.h
	g++ -Wall -g -c bishop.cpp
king.o: king.cpp piece.h
	g++ -Wall -g -c king.cpp
queen.o: queen.cpp piece.h
	g++ -Wall -g -c queen.cpp
clean :
	rm -f *.o chess
