#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 8; i++)
	{
		for (int sp = 1; sp <= 8 - i; sp++)
		{
			cout << " ";
		}

		cout << "*";

		for (int b = 4; b <= i * 2; b++)
		{
			cout << " ";
		}
		cout << "*";
		cout << endl;
	}
}