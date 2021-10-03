#include <iostream>
#include <array>
using namespace std;

int main() {
	int M[8][10];
	int m, n;
	cout << "Enter two numbers: ";
	cin >> m >> n;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; ++j)
		{
			 if (j > i)
				M[i][j] = j;
			 else
				M[i][j] = i;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; ++j) {
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}
	
	int** E = new int* [n];
	for (int i = 0; i < n; i++)
	{
		E[i] = new int[m];
		cout << "new array element added added to this array of arrays" << endl;
	}
	cout << m << " is the first number entered and " << n << " is the second" << endl;
	for (int i = 0; i < n; i++)
		delete[] E[i];
	delete[] E;
}