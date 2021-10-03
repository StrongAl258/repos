#include <array>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
void split(const string& date, string& month, string& day, string& year);

int main() {
	int c = 0;
	int* p;
	cout << "Enter the size of the array: ";
	cin >> c;
	p = new int[c];
	for (int i = 0; i != c; i++)
	{
		p[i] = 5 * i;
		cout << p[i] << endl;
	}
	

	for (const string& date : { "05/10/1984", "4/15/84", "September/5/2014" })
	{
		string month, day, year;
		split(date, month, day, year);
		cout << date << ' ' << month << ' ' << day << ' ' << year << '\n';
	}
	return 0;
}
void split(const string& date, string& month, string& day, string& year)
{
	istringstream stm(date);
	if (getline(stm, month,'/' ) && getline(stm, day, '/') && getline(stm, year)); // ok
	else; // parse error
}
