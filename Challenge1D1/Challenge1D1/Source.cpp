#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string input;
	vector<int> a;
	ifstream nput{ "input.txt" };

	if (nput.is_open())
	{
		while (1)
		{
			getline(nput, input);
			if (nput.eof())
				break;
			cout << input << endl;
			a.push_back(stoi(input));
		}
		nput.close();
	}
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			for (int k = j + 1; k < a.size(); k++)
			{
				if (a[i] + a[j] + a[k]== 2020)
				{
					cout << a[i] * a[j] * a[k];
					break;
				}
			}
		}
	}
	

	return 0;
}