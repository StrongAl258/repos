#include <cstdlib>
#include <iostream>
using namespace std;

const int X = 1, O = -1, EMPTY = 0;

int currentPlayer;
class Game {
private:
	int board[3][3];
public:
	Game() {
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
		return((board[0][0] + board[0][1] + board[0][2] == win)// row 0
			|| (board[1][0] + board[1][1] + board[1][2] == win)// row 1
			|| (board[2][0] + board[2][1] + board[2][2] == win)// row 2
			|| (board[0][0] + board[1][0] + board[2][0] == win)// column 0
			|| (board[0][1] + board[1][1] + board[2][1] == win)// column 1
			|| (board[0][2] + board[1][2] + board[2][2] == win)// column 2
			|| (board[0][0] + board[1][1] + board[2][2] == win)// diagonal left to right
			|| (board[2][0] + board[1][1] + board[0][2] == win));// diagonal right to left

	}
	int getWinner() {
		if (isWin(X)) return X;
		else if (isWin(O)) return O;
		else return EMPTY;
	}

	/*void printBoard() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				switch (board[i][j]) {
				case X: cout << "X"; break;
				case O: cout << "O"; break;
				case EMPTY: cout << " "; break;
				}
				if (j < 2) cout << "|";
			}
			if (i < 2) cout << "\n-+-+-\n";
		}
	}*/
	friend ostream& operator<<(ostream& o, const Game& g){
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
	}
};
int main() {
	Game T;
	int winner;
	while (winner == EMPTY) {
		int a, b;
		cout << "\nEnter coordinates: ";
		cin >> a >> b;
		T.putMark(a, b);
		cout << T;
		winner = T.getWinner();

	}
	
	winner = T.getWinner();
	if (winner != EMPTY)
		cout << " " << (winner == X ? 'X' : 'O') << " wins" << endl;
	else
		cout << " Tie" << endl;
	return EXIT_SUCCESS;
}