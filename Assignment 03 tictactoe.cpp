#include <iostream>
#include <string>
using namespace std;
int moveCounter = 0;

bool isWon(char xo, char board[][3]) {
	bool won = false;
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == xo && board[i][1] == xo && board[i][2] == xo) {
			won = true;
		}

	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == xo && board[1][i] == xo && board[2][i] == xo) {
			won = true;
		}
	}
	if (board[0][0] == xo && board[1][1] == xo && board[2][2] == xo) {
		won = true;
	}
	if (board[0][2] == xo && board[1][1] == xo && board[2][0] == xo) {
		won = true;
	}
	return won;

}
bool isDraw(char board[][3]) {
	bool draw = false;
	if (moveCounter == 9) {
		if (isWon('x', board)) {
			draw = true;
		}
		draw = true;
	}

	return draw;
}
void displayBoard(char board[][3]) {
	for (int i = 0; i < 3; i++) {
		cout << "\n-------------\n";
		for (int j = 0; j < 3; j++) {
			cout << "| " << board[i][j] << " ";
		}
		cout << "|";

	}
	cout << "\n-------------\n";
}


void makeAMove(char board[][3], char xo) {
	int inputRow = 0;
	int inputColumn = 0;
	bool taken = true;
	int a;
	while (taken) {
		cout << "Enter a row (0, 1, 2) for player " << xo << "   : ";
		cin >> inputRow;
		cout << "Enter a column (0, 1, 2) for player " << xo << ": ";
		cin >> inputColumn;
		if (board[inputRow][inputColumn] == 'X' || board[inputRow][inputColumn] == 'O') {
			cout << "This cell is already occupied. Try a different cell";
		}
		else {
			board[inputRow][inputColumn] = xo;
			taken = false;

		}
		cout << endl;
	}
	moveCounter++;
}

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}
