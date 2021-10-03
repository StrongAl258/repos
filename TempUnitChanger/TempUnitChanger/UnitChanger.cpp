#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double t = 0;
	char u;

	cout << "What is the temperature in digits: \n";
	cin >> t;

	cout << "Is it F or C? \n";
	cin >> u;

	if (u == 'f' || u == 'F')
	{
		
		cout << "Temperature in Celsius is " << (t - 32) * 5.0 / 9.0 << endl;
	}
	else if (u == 'c' || u == 'C')
	{
		cout << "Temperature in Fahrenheit is " << t * 9 / 5 + 32 << endl;
	}
}