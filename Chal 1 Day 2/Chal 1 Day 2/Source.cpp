#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string n, pass;
	string test;
	int a, b, c = 0, cnt = 0, start = 0;
	ifstream nput{ "input.txt" };

	if (nput.is_open())
	{
		while (1)
		{
			getline(nput, n, '-');
			a = stoi(n);
			getline(nput, n, ' ');
			b = stoi(n);
			getline(nput, n, ':');
			test = n;
			getline(nput, pass);
			int c = count(pass.begin(), pass.end(), test);
			if (c >= a && c <= b)
				cnt++;
		}
		cout << cnt;
		nput.close();
	}
}