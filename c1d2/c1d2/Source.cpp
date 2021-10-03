#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string n, m, pass;
	char t;
	int a, b, c = 0, cnt = 0, start = 0;
	ifstream nput{ "input.txt" };

	if (nput.is_open())
	{
		while (1)
		{
			getline(nput, n, '-');
			if (nput.eof())
				break;
			a = stoi(n);
			getline(nput, n, ' ');
			b = stoi(n);
			getline(nput, n, ':');
			getline(nput, pass);
			t = n[0];
			if (pass[a] == t && pass[b] != t || pass[a]!= t && pass[b] == t)
				cnt++;
		}
		cout << cnt;
		nput.close();
	}
}