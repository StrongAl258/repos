#include <cstdlib>
#include <iostream>
using namespace std;

const int X = 1, O = -1, EMPTY = 0;
int board[3][3];
int currentPlayer;
class Game {
public:
	void clearBoard() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				board[i][j] = EMPTY;
		currentPlayer = X;
	}
	void putMark(int i, int j) {
		board[i][j] = currentPlayer;
		currentPlayer = -currentPlayer;
	}
	bool isWin(int mark) {
		int win = 3 * mark;
		return((board[0][0] + board[0][1] + board[0][2] == win) // row 0
			||(board[1][0] + board[1][1] + board[1][2] == win) // row 1
			||(board[2][0] + board[2][1] + board[2][2] == win) // row 2
			||(board[0][0] + board[1][0] + board[1][0] == win) //column 0
			||(board[0][1] + board[1][1] + board[2][1] == win) //column 1
			||(board[0][2] + board[1][2] + board[2][2] == win) //column 2
			||(board[0][0] + board[1][1] + board[2][2] == win) //diagonal
			||(board[2][0] + board[1][1] + board[0][2] == win) //diagonal
			);
	}
	int getWinner() {
		if (isWin(X)) return X;
		else if (isWin(O)) return O;
		else return EMPTY;
	}
	friend ostream& operator<<(ostream& o, const Game &g) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				switch (board[i][j]) {
				case X: o << "X"; break;
				case O: o << "O"; break;
				case EMPTY: o << " "; break;
				}
				if (j < 2) o << "|";
			}
			if (i < 2) o << "\n-+-+-\n";
		}
		return o;
	}
};

int main() {
	Game T;
	T.clearBoard();
	T.putMark(0, 0);
	cout << T << "\n\n";
	T.putMark(1, 1);
	cout << T << "\n\n";
	T.putMark(0, 1);
	cout << T << "\n\n";
	T.putMark(0, 2);
	cout << T << "\n\n";
	T.putMark(2, 0);
	cout << T << "\n\n";
	T.putMark(1, 2);
	cout << T << "\n\n";
	T.putMark(2, 2);
	cout << T << "\n\n";
	T.putMark(2, 1);
	cout << T << "\n\n";
	T.putMark(1, 0);
	cout << T << "\n\n";
	int winner = T.getWinner();
	if (winner != EMPTY)
		cout << " " << (winner == X ? 'X' : 'O') << " wins" << endl;
	else
		cout << " Tie" << endl;
	return EXIT_SUCCESS;
}