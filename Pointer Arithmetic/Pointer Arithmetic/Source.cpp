#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
	int i[5] = { 1, 2, 3, 4, 5 };
	int* j = i;
	cout << j << endl;
	cout << *j << endl;
	j++;
	cout << j << endl;
	cout << *j << endl;
	j += 2;
	cout << j << endl;
	cout << *j << endl;

}